#include "imagefusionprocessor.h"

ImageFusionProcessor::ImageFusionProcessor(Mat input, Mat pan, int panType, int orthType, QObject *parent) :
    QObject(parent)
{
    inputMatrix = input;
    panImage = pan;
    type = panType;
    orthogonalizationType = orthType;
}
void ImageFusionProcessor::exec()
{
    cv::reduce(inputMatrix, inputMatrix.col(0), 1, CV_REDUCE_AVG, -1);
    switch(orthogonalizationType)
    {
        case 0:
        {
            // QR transform inputMatrix
            QRresult inputMatrixQR = ProcessingCore::mgs_qr(inputMatrix);
            inputMatrix.release();

            // vector form pan image
            panImage = panImage.reshape(0, 1).t();
            // QR transform of pan image
            QRresult panImageQR = ProcessingCore::mgs_qr(panImage);
            panImageQR.R.release();
            panImage.release();
            inputMatrixQR.Q.col(0) = panImageQR.Q.col(0)*1;
            panImageQR.Q.release();
            result = inputMatrixQR.Q*inputMatrixQR.R;
            inputMatrixQR.Q.release();
            inputMatrixQR.R.release();
            break;
        }
        case 1:
        {
            Mat input32;
            cv::SVD inputSVD, panSVD;
            inputMatrix.convertTo(input32, CV_32F);
            inputSVD = cv::SVD(input32);

//            cv::SVD::compute(input32, inputW, inputU, inputVt);
            input32.release();
            inputMatrix.release();


//            // vector form pan image
            panImage = panImage.reshape(0, 1).t();
            // QR transform of pan image
            panImage.convertTo(input32, CV_32F);
            panSVD = cv::SVD(input32);
            panImage.release();
            input32.release();

            inputSVD.u.col(0) = panSVD.u.col(0)*1;
        //     we got it in as vector, transform it to diagonal matrix
            Mat W=Mat::zeros(inputSVD.w.rows,inputSVD.w.rows,CV_32FC1);
            for(int i=0;i<inputSVD.w.rows;i++)
            {
               W.at<float>(i,i)=inputSVD.w.at<float>(i);
            }
            result = inputSVD.u*W*inputSVD.vt;
//            result = inputVt.t()*cv::Mat::diag(1./inputW)*inputU.t();
            break;
        }
        default:
        {
            break;
        }
    }
    result.convertTo(result, type);
    result.colRange(1, result.cols).copyTo(result);
}
Mat ImageFusionProcessor::getDispertion(Mat input)
{
    Mat disp = Mat::zeros(input.cols, 1, CV_32F);
    for(int i=0; i<input.cols; i++)
    {
        Mat col;
        input.col(i).copyTo(col);
        Scalar mean = cv::mean(col);
        col = col-mean;
        cv::pow(col, 2.0, col);
        Scalar dispertion = cv::mean(col);
        disp.at<float>(i, 0) = (float)dispertion[0];
    }
    return disp;
}
