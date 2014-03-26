#include "StdAfx.h"
#include "opencv2\core\types_c.h"
#include <cmath>
using namespace std;
using namespace cv;


    ProcessingCore::ProcessingCore(void)
	{

	}
    std::string ProcessingCore::convertToStdString( QString & s )
	{
        std::string stds = s.toLocal8Bit().constData();
        return stds;
	}
    Mat ProcessingCore::readImage(QString & s)
    {
        Mat image = imread(ProcessingCore::convertToStdString(s), -1);
        int channelsNumber = image.channels();
        switch(channelsNumber)
        {
            case 1:
                break;
            case 3:
                cvtColor(image, image, CV_BGR2RGB);
                break;
            case 4:
                cvtColor(image, image, CV_BGRA2RGBA);
                break;
        }
        return image;
    }
    Mat ProcessingCore::RGB2BGR(Mat image)
    {
        Mat newImage;
        int channelsNumber = image.channels();
        switch(channelsNumber)
        {
            case 1:
                newImage = image;
                break;
            case 3:
                cvtColor(image, newImage, CV_RGB2BGR);
                break;
            case 4:
                cvtColor(image, newImage, CV_RGBA2BGRA);
                break;
        }
        return newImage;
    }
    bool ProcessingCore::writeImage(QString fileName, Mat image)
    {
        bool success = false;
        Mat newImage = ProcessingCore::RGB2BGR(image);
        success = cv::imwrite(ProcessingCore::convertToStdString(fileName), newImage);

        return success;
    }
    QImage* ProcessingCore::convertToQImage( Mat& matrix)
    {
        QImage* img;
        int channelsNumber;
        //Mat resized;
        //cv::resize(matrix, resized, Size(width, height), 0, 0);
        channelsNumber = matrix.channels();
        switch(channelsNumber)
        {
        case 1:
            //resized = matrix;
            img = new QImage((uchar*)matrix.data, matrix.cols, matrix.rows, matrix.step, QImage::Format_Indexed8);
            break;
        case 3:
//            cvtColor(matrix, matrix, CV_BGR2RGB);
            img = new QImage((uchar*)matrix.data, matrix.cols, matrix.rows, matrix.step, QImage::Format_RGB888);
            break;
        case 4:
//            cvtColor(matrix, matrix, CV_BGRA2RGBA);
            img = new QImage((uchar*)matrix.data, matrix.cols, matrix.rows, matrix.step, QImage::Format_ARGB32);
            break;
        }
        return img;
    }
    vector<QImage*> ProcessingCore::splitToQImage(Mat matrix)
    {
        vector<QImage*> result;
        vector<Mat> channels;
        int channelsNumber;
        channelsNumber = matrix.channels();
        cv::split(matrix, channels);
        for (int i = channelsNumber-1; i>=0; i--)
        {
            Mat* ch = new Mat(channels[i]);
            result.push_back(new QImage((uchar*)ch->data, ch->cols, ch->rows, ch->step, QImage::Format_Indexed8));
        }
        return result;
    }
    Mat ProcessingCore::getChannel(Channels ch, Mat & matrix)
    {
        Mat result;
        int channelsNumber = matrix.channels();
        if (channelsNumber>ch && ch>=0)
        {
            vector<Mat> channels;
            cv::split(matrix, channels);
            result = channels[ch];
        }
        return result;
    }
    QRresult ProcessingCore::mgs_qr(Mat& A)
	{
        QRresult result;
        result.Q = A;
        result.Q.convertTo(result.Q, CV_32F);
        int Width = result.Q.cols;
        result.R = Mat::zeros(Width, Width, CV_32F);
        for (int j = 0; j<Width; j++)
        {
            result.R.at<float>(j ,j) = norm(result.Q.col(j));
            result.Q.col(j) = result.Q.col(j)/result.R.at<float>(j ,j);
            for (int k=j+1; k<Width;k++)
            {
                Mat temp = result.Q.col(j).t()*result.Q.col(k);
                int rows = temp.rows; int cols = temp.cols;
                result.R.at<float>(j ,k)=	temp.at<float>(0, 0);
                result.Q.col(k) = result.Q.col(k)-result.R.at<float>(j ,k)*result.Q.col(j);
            }
        }
        return result;
	}
    template<class T>
    void ProcessingCore::matIteration(Mat M,  void (*callback)(T Value))
	{
		for(int i = 0; i < M.rows; i++)
		{
			const T* Mi = M.ptr<T>(i);
			for(int j = 0; j < M.cols; j++)
			{
				callback(Mi[j]);
			}

		}
	}
    cv::Mat ProcessingCore::FFT(Mat image)
    {
        if (image.channels() > 1)
        {
            vector<Mat> ch;
            cv::split(image, ch);
            image = ch[0];
        }
        Size dftSize;
        dftSize.width = getOptimalDFTSize(image.cols);
        dftSize.height = getOptimalDFTSize(image.rows);

        Mat temp=Mat::zeros(dftSize, CV_64FC1), result;
        Mat roi_temp(temp, Rect(0, 0, image.cols, image.rows));
        image.convertTo(roi_temp, CV_64F);
        cv::dft(temp, result, DFT_COMPLEX_OUTPUT );
        return result;
    }
    cv::Mat ProcessingCore::IFT(Mat transform, int origType)
    {
        Mat iftm;
        cv::dft(transform, iftm, DFT_INVERSE + DFT_SCALE + DFT_REAL_OUTPUT );
        iftm.convertTo(iftm, origType);
        return iftm;
    }

    //void Core::getBasicCharacteristics(Mat image)
    //{
		/*int maxValue;
		switch (image.depth())
		{
		case CV_16U:
		maxValue=65535;
		break;
		case CV_8U:
		maxValue = 255;
		break;
		}*/
	/*Mat p = Mat(1, maxValue+1, image.type());
	MatConstIterator_<short> it, it_end = image.end<short>(); int count=0;
	for(int i=0; i<maxValue; ++i)
	{
	it = image.begin<short>();
	for (; it != it_end; ++it)
	{
	if(*it == i)
	{
	++count;
	}
	}
	p.push_back(count);
	count=0;
	}
	p= p*(1/cv::sum(p)[0]);
	*p*(cv::log() p))/log(2));
	return result;
	}
	bool MainImagesList::push_back(string Key)
	{
	bool exist=false;
	for (int i = 0; i<_Images.size(); i++)
	{
	if(_Images[i].Key == Key)
	{
	exist=true;
	break;
	}
	} 
	if (!exist)
	{
	Mat Image = imread(Key);
	MainImagesListItem item = MainImagesListItem(Image, Key);
	this->_Images.push_back(item);
	}
	return !exist;*/
    //	}
QIcon ProcessingCore::convertToQIcon(Mat image, int width, int height)
{
    QImage* qimage = convertToQImage(image);
    QPixmap pixmap = QPixmap::fromImage(*qimage);
    QIcon ic = QIcon(pixmap.scaled(width, height));
    return ic;
}
static double getSSIM(IplImage* src1, IplImage* src2, IplImage* mask,
                      const double K1,
                      const double K2,
                      const int L,
                      const int downsamplewidth,
                      const int gaussian_window,
                      const double gaussian_sigma,
                      IplImage* dest)
{
    // default settings
    const double C1 = (K1 * L) * (K1 * L); //6.5025 C1 = (K(1)*L)^2;
    const double C2 = (K2 * L) * (K2 * L); //58.5225 C2 = (K(2)*L)^2;

    //�@get width and height
    int x=src1->width, y=src1->height;

    //�@distance (down sampling) setting
    int rate_downsampling = std::max(1, int((std::min(x,y) / downsamplewidth) + 0.5));

    int nChan=1, d=IPL_DEPTH_32F;

    //�@size before down sampling
    CvSize size_L = cvSize(x, y);

    //�@size after down sampling
    CvSize size = cvSize(x / rate_downsampling, y / rate_downsampling);

    //�@image allocation
    cv::Ptr<IplImage> img1 = cvCreateImage( size, d, nChan);
    cv::Ptr<IplImage> img2 = cvCreateImage( size, d, nChan);


    //�@convert 8 bit to 32 bit float value
    cv::Ptr<IplImage> img1_L = cvCreateImage( size_L, d, nChan);
    cv::Ptr<IplImage> img2_L = cvCreateImage( size_L, d, nChan);
    cvConvert(src1, img1_L);
    cvConvert(src2, img2_L);

    //�@down sampling
    cvResize(img1_L, img1);
    cvResize(img2_L, img2);

    //�@buffer alocation
    cv::Ptr<IplImage> img1_sq = cvCreateImage( size, d, nChan);
    cv::Ptr<IplImage> img2_sq = cvCreateImage( size, d, nChan);
    cv::Ptr<IplImage> img1_img2 = cvCreateImage( size, d, nChan);

    //�@pow and mul
    cvPow( img1, img1_sq, 2 );
    cvPow( img2, img2_sq, 2 );
    cvMul( img1, img2, img1_img2, 1 );

    //�@get sigma
    cv::Ptr<IplImage> mu1 = cvCreateImage( size, d, nChan);
    cv::Ptr<IplImage> mu2 = cvCreateImage( size, d, nChan);
    cv::Ptr<IplImage> mu1_sq = cvCreateImage( size, d, nChan);
    cv::Ptr<IplImage> mu2_sq = cvCreateImage( size, d, nChan);
    cv::Ptr<IplImage> mu1_mu2 = cvCreateImage( size, d, nChan);


    cv::Ptr<IplImage> sigma1_sq = cvCreateImage( size, d, nChan);
    cv::Ptr<IplImage> sigma2_sq = cvCreateImage( size, d, nChan);
    cv::Ptr<IplImage> sigma12 = cvCreateImage( size, d, nChan);

    //�@allocate buffer
    cv::Ptr<IplImage> temp1 = cvCreateImage( size, d, nChan);
    cv::Ptr<IplImage> temp2 = cvCreateImage( size, d, nChan);
    cv::Ptr<IplImage> temp3 = cvCreateImage( size, d, nChan);

    //ssim map
    cv::Ptr<IplImage> ssim_map = cvCreateImage( size, d, nChan);


    //////////////////////////////////////////////////////////////////////////
    // 	// PRELIMINARY COMPUTING

    //�@gaussian smooth
    cvSmooth( img1, mu1, CV_GAUSSIAN, gaussian_window, gaussian_window, gaussian_sigma );
    cvSmooth( img2, mu2, CV_GAUSSIAN, gaussian_window, gaussian_window, gaussian_sigma );

    //�@get mu
    cvPow( mu1, mu1_sq, 2 );
    cvPow( mu2, mu2_sq, 2 );
    cvMul( mu1, mu2, mu1_mu2, 1 );

    //�@calc sigma
    cvSmooth( img1_sq, sigma1_sq, CV_GAUSSIAN, gaussian_window, gaussian_window, gaussian_sigma );
    cvAddWeighted( sigma1_sq, 1, mu1_sq, -1, 0, sigma1_sq );

    cvSmooth( img2_sq, sigma2_sq, CV_GAUSSIAN, gaussian_window, gaussian_window, gaussian_sigma);
    cvAddWeighted( sigma2_sq, 1, mu2_sq, -1, 0, sigma2_sq );

    cvSmooth( img1_img2, sigma12, CV_GAUSSIAN, gaussian_window, gaussian_window, gaussian_sigma );
    cvAddWeighted( sigma12, 1, mu1_mu2, -1, 0, sigma12 );


    //////////////////////////////////////////////////////////////////////////
    // FORMULA

    // (2*mu1_mu2 + C1)
    cvScale( mu1_mu2, temp1, 2 );
    cvAddS( temp1, cvScalarAll(C1), temp1 );

    // (2*sigma12 + C2)
    cvScale( sigma12, temp2, 2 );
    cvAddS( temp2, cvScalarAll(C2), temp2 );

    // ((2*mu1_mu2 + C1).*(2*sigma12 + C2))
    cvMul( temp1, temp2, temp3, 1 );

    // (mu1_sq + mu2_sq + C1)
    cvAdd( mu1_sq, mu2_sq, temp1 );
    cvAddS( temp1, cvScalarAll(C1), temp1 );

    // (sigma1_sq + sigma2_sq + C2)
    cvAdd( sigma1_sq, sigma2_sq, temp2 );
    cvAddS( temp2, cvScalarAll(C2), temp2 );

    // ((mu1_sq + mu2_sq + C1).*(sigma1_sq + sigma2_sq + C2))
    cvMul( temp1, temp2, temp1, 1 );

    // ((2*mu1_mu2 + C1).*(2*sigma12 + C2))./((mu1_sq + mu2_sq + C1).*(sigma1_sq + sigma2_sq + C2))
    cvDiv( temp3, temp1, ssim_map, 1 );

    cv::Ptr<IplImage> stemp = cvCreateImage( size, IPL_DEPTH_8U, 1);
    cv::Ptr<IplImage> mask2 = cvCreateImage( size, IPL_DEPTH_8U, 1);

    cvConvertScale(ssim_map, stemp, 255.0, 0.0);
    cvResize(stemp,dest);
    cvResize(mask,mask2);

    CvScalar index_scalar = cvAvg( ssim_map, mask2 );

    // through observation, there is approximately
    // 1% error max with the original matlab program

    return index_scalar.val[0];
}


double xcvCalcSSIM(IplImage* src, IplImage* dest, int channel, int method, IplImage* _mask,
                   const double K1,
                   const double K2,
                   const int L,
                   const int downsamplewidth,
                   const int gaussian_window,
                   const double gaussian_sigma,
                   IplImage* ssim_map
                   )
{
    IplImage* mask;
    IplImage* __mask=cvCreateImage(cvGetSize(src),8,1);
    IplImage* smap=cvCreateImage(cvGetSize(src),8,1);

    cvSet(__mask,cvScalarAll(255));


    if(_mask==NULL)mask=__mask;
    else mask=_mask;
    IplImage* ssrc;
    IplImage* sdest;
    if(src->nChannels==1)
    {
        ssrc=cvCreateImage(cvGetSize(src),8,3);
        sdest=cvCreateImage(cvGetSize(src),8,3);
        cvCvtColor(src,ssrc,CV_GRAY2BGR);
        cvCvtColor(dest,sdest,CV_GRAY2BGR);
    }
    else
    {
        ssrc = cvCloneImage(src);
        sdest = cvCloneImage(dest);
        cvCvtColor(dest,sdest,method);
        cvCvtColor(src,ssrc,method);
    }

    IplImage* gray[4];
    IplImage* sgray[4];
    for(int i=0;i<4;i++)
    {
        gray[i] = cvCreateImage(cvGetSize(src),8,1);
        sgray[i] = cvCreateImage(cvGetSize(src),8,1);
    }

    cvSplit(sdest,gray[0],gray[1],gray[2],NULL);
    cvSplit(ssrc,sgray[0],sgray[1],sgray[2],NULL);

    double sn=0.0;

    if(channel==ALLCHANNEL)
    {
        for(int i=0;i<src->nChannels;i++)
        {
            sn+=getSSIM(sgray[i],gray[i],mask,K1,K2,L,downsamplewidth,gaussian_window,gaussian_sigma,smap);
        }
        sn/=(double)src->nChannels;
    }
    else
    {
        sn	= getSSIM(sgray[channel],gray[channel],mask,K1,K2,L,downsamplewidth,gaussian_window,gaussian_sigma,smap);
    }

    for(int i=0;i<4;i++)
    {
        cvReleaseImage(&gray[i]);
        cvReleaseImage(&sgray[i]);
    }

    if(ssim_map!=NULL)cvCopy(smap,ssim_map);
    cvReleaseImage(&smap);
    cvReleaseImage(&__mask);
    cvReleaseImage(&ssrc);
    cvReleaseImage(&sdest);
    return sn;
}

double xcvCalcDSSIM(IplImage* src, IplImage* dest, int channel, int method, IplImage* _mask,
                    const double K1,
                    const double K2,
                    const int L,
                    const int downsamplewidth,
                    const int gaussian_window,
                    const double gaussian_sigma,
                    IplImage* ssim_map
                    )
{
    double ret = xcvCalcSSIM(src, dest, channel, method, _mask, K1,K2,L,downsamplewidth,gaussian_window,gaussian_sigma,ssim_map);
    if(ret==0)ret=-1.0;
    else ret =(1.0 / ret) - 1.0;
    return ret;
}
double xcvCalcSSIMBB(IplImage* src, IplImage* dest, int channel, int method, int boundx,int boundy,const double K1,	const double K2,	const int L, const int downsamplewidth, const int gaussian_window, const double gaussian_sigma, IplImage* ssim_map)
{
    IplImage* mask = cvCreateImage(cvGetSize(src),8,1);
    cvZero(mask);
    cvRectangle(mask,cvPoint(boundx,boundy),cvPoint(src->width-boundx,src->height-boundy),cvScalarAll(255),CV_FILLED);

    double ret = xcvCalcSSIM(src,dest,channel,method,mask,K1,K2,L,downsamplewidth,gaussian_window,gaussian_sigma,ssim_map);
    cvReleaseImage(&mask);
    return ret;
}

double xcvCalcDSSIMBB(IplImage* src, IplImage* dest, int channel, int method, int boundx,int boundy,const double K1,	const double K2,	const int L, const int downsamplewidth, const int gaussian_window, const double gaussian_sigma, IplImage* ssim_map)
{
    IplImage* mask = cvCreateImage(cvGetSize(src),8,1);
    cvZero(mask);
    cvRectangle(mask,cvPoint(boundx,boundy),cvPoint(src->width-boundx,src->height-boundy),cvScalarAll(255),CV_FILLED);

    double ret = xcvCalcSSIM(src,dest,channel,method,mask,K1,K2,L,downsamplewidth,gaussian_window,gaussian_sigma,ssim_map);
    cvReleaseImage(&mask);

    if(ret==0)ret=-1.0;
    else ret = (1.0 / ret) - 1.0;
    return ret;
}

double ProcessingCore::calcSSIM(cv::Mat& src1, cv::Mat& src2, int channel, int method, const double K1, const double K2,	const int L, const int downsamplewidth, const int gaussian_window, const double gaussian_sigma)
{
    Mat mask; Mat map;
    return calcSSIM(src1, src2, mask, map, channel,  method, K1, K2, L, downsamplewidth, gaussian_window, gaussian_sigma);
}

double ProcessingCore::calcSSIM(cv::Mat& src1, cv::Mat& src2, cv::Mat& mask, cv::Mat& ssim_map, int channel, int method, const double K1, const double K2,	const int L, const int downsamplewidth, const int gaussian_window, const double gaussian_sigma)
{
    if(ssim_map.empty())ssim_map.create(src1.size(),CV_8U);
    IplImage Src1 = IplImage(src1);
    IplImage Src2 = IplImage(src2);
    IplImage Ssim_map = IplImage(ssim_map);
    IplImage* iplSrc1 = &Src1;
    IplImage* iplSrc2 = &Src2;
    IplImage* iplSsim_map = &Ssim_map;
    if(mask.empty())
    {

        xcvCalcSSIM(iplSrc1,iplSrc2,channel,method,NULL,K1,K2,L,downsamplewidth,gaussian_window,gaussian_sigma, iplSsim_map);
        return xcvCalcSSIM(iplSrc1,iplSrc2,channel,method,NULL,K1,K2,L,downsamplewidth,gaussian_window,gaussian_sigma, iplSsim_map);
    }
    else
    {
        IplImage Mask = IplImage(mask);
        IplImage* iplMask = &Mask;
        return xcvCalcSSIM(iplSrc1,iplSrc2,channel,method,iplMask,K1,K2,L,downsamplewidth,gaussian_window,gaussian_sigma, iplSsim_map);
    }
}
double ProcessingCore::calcSSIMBB(cv::Mat& src1, cv::Mat& src2, int channel, int method, int boundx, int boundy, const double K1, const double K2, const int L, const int downsamplewidth, const int gaussian_window, const double gaussian_sigma)
{
    Mat ssim_map;
    return calcSSIMBB(src1, src2, ssim_map, channel, method, boundx, boundy, K1, K2, L, downsamplewidth, gaussian_window, gaussian_sigma);
}
double ProcessingCore::calcSSIMBB(cv::Mat& src1, cv::Mat& src2, cv::Mat& ssim_map, int channel, int method, int boundx, int boundy, const double K1, const double K2, const int L, const int downsamplewidth, const int gaussian_window, const double gaussian_sigma)
{
    IplImage Src1 = IplImage(src1);
    IplImage Src2 = IplImage(src2);
    IplImage Ssim_map = IplImage(ssim_map);
    IplImage* iplSrc1 = &Src1;
    IplImage* iplSrc2 = &Src2;
    IplImage* iplSsim_map = &Ssim_map;
    if(ssim_map.empty())ssim_map.create(src1.size(),CV_8U);
    return xcvCalcSSIMBB(iplSrc1,iplSrc2,channel,method,boundx,boundy,K1,K2,L,downsamplewidth,gaussian_window,gaussian_sigma, iplSsim_map);
}

//double calcDSSIM(cv::Mat& src1, cv::Mat& src2, int channel, int method, cv::Mat& mask, const double K1, const double K2,	const int L, const int downsamplewidth, const int gaussian_window, const double gaussian_sigma, cv::Mat& ssim_map)
//{
//	if(ssim_map.empty())ssim_map.create(src1.size(),CV_8U);
//    IplImage* iplSrc1 = &IplImage(src1);
//    IplImage* iplSrc2 = &IplImage(src2);
//    IplImage* iplSsim_map = &IplImage(ssim_map);
//	if(mask.empty())
//	{
//        xcvCalcSSIM(iplSrc1,iplSrc2,channel,method,NULL,K1,K2,L,downsamplewidth,gaussian_window,gaussian_sigma, iplSsim_map);
//        return xcvCalcDSSIM(iplSrc1,iplSrc2,channel,method,NULL,K1,K2,L,downsamplewidth,gaussian_window,gaussian_sigma, iplSsim_map);
//	}
//	else
//    {
//        IplImage* iplMask = &IplImage(mask);
//        return xcvCalcDSSIM(iplSrc1,iplSrc2,channel,method,iplMask,K1,K2,L,downsamplewidth,gaussian_window,gaussian_sigma, iplSsim_map);
//    }
//}

//double calcDSSIMBB(cv::Mat& src1, cv::Mat& src2, int channel, int method, int boundx, int boundy, const double K1, const double K2, const int L, const int downsamplewidth, const int gaussian_window, const double gaussian_sigma, cv::Mat& ssim_map)
//{
//	if(ssim_map.empty())ssim_map.create(src1.size(),CV_8U);
//    IplImage* iplSrc1 = &IplImage(src1);
//    IplImage* iplSrc2 = &IplImage(src2);
//    IplImage* iplSsim_map = &IplImage(ssim_map);
//    return xcvCalcDSSIMBB(iplSrc1,iplSrc2,channel,method,boundx,boundy,K1,K2,L,downsamplewidth,gaussian_window,gaussian_sigma, iplSsim_map);
//}

double ProcessingCore::meanDiff(Mat img1, Mat img2)
{
    Mat diff;
    cv::absdiff(img1, img2, diff);
    Scalar result = cv::mean(diff);
    return result.val[0];
}

double ProcessingCore::normCorrelation(Mat img1, Mat img2)
{
    Mat img1pow2, mult;
    cv::pow(img1, 2.0, img1pow2);
    cv::multiply(img1, img2, mult);
    cv::Scalar result = cv::sum(mult)/cv::sum(img1pow2);
    return result.val[0];
}
double ProcessingCore::correlationQuality(Mat img1, Mat img2)
{
    Mat mult;
    cv::multiply(img1, img2, mult);
    cv::Scalar result = cv::sum(mult)/cv::sum(img1);
    return result.val[0];
}
double ProcessingCore::maxDiff(Mat img1, Mat img2)
{
    Mat diff;
    cv::absdiff(img1, img2, diff);
    double max;
    cv::minMaxLoc(diff, NULL, &max);
    return max;
}
double ProcessingCore::imageFidelity(Mat img1, Mat img2)
{
    Mat img1pow2, diff;
    cv::pow(img1, 2.0, img1pow2);
    cv::absdiff(img1, img2, diff);
    cv::pow(diff, 2.0, diff);
    Scalar value = cv::sum(diff)/cv::sum(img1pow2);
    return 1.0-value.val[0];

}
template<class T>
Mat ProcessingCore::getO(Mat img)
{
    Mat o = Mat::zeros(img.rows, img.cols, CV_32F);
    for(int i = 0; i < img.rows; i++)
    {
        for(int j = 0; j < img.cols; j++)
        {
            float value = -4*img.at<T>(i, j);
            if(i)
            {
                value+=img.at<T>(i-1, j);
            }
            if(j)
            {
                value+=img.at<T>(i, j-1);
            }
            if(i != img.rows-1)
            {
                value+=img.at<T>(i+1, j);
            }
            if(j != img.cols-1)
            {
                value+=img.at<T>(i, j+1);
            }
            o.at<float>(i, j) = value;
        }
    }
    return o;
}

double ProcessingCore::laplMeanSqError(Mat img1, Mat img2)
{
    Mat oImg1,oImg2;
    switch(img1.depth())
    {
    case CV_8U:
        oImg1 = ProcessingCore::getO<unsigned char>(img1);
        break;
    case CV_16U:
        oImg1 = ProcessingCore::getO<unsigned int>(img1);
        break;
    case CV_32F:
        oImg1 = ProcessingCore::getO<float>(img1);
    case CV_64F:
        oImg1 = ProcessingCore::getO<double>(img1);
        break;
    }
    switch(img2.depth())
    {
    case CV_8U:
        oImg2 = ProcessingCore::getO<unsigned char>(img2);
        break;
    case CV_16U:
        oImg2 = ProcessingCore::getO<unsigned int>(img2);
        break;
    case CV_32F:
        oImg2 = ProcessingCore::getO<float>(img2);
    case CV_64F:
        oImg2 = ProcessingCore::getO<double>(img2);
        break;
    }

    Mat oImg1Pow;
    pow(oImg1, 2.0, oImg1Pow);
    Scalar value = cv::sum(oImg1-oImg2)/cv::sum(oImg1Pow);
    return value.val[0];
}
double ProcessingCore::meanSqError(Mat img1, Mat img2)
{
    Mat pow2;
    cv::pow(img1-img2, 2.0, pow2);
    Scalar result = cv::mean(pow2);
    return result.val[0];
}
double ProcessingCore::peakMeanSqError(Mat img1, Mat img2)
{
    Mat pow2;
    cv::pow(img1-img2, 2.0, pow2);

    double max;
    cv::minMaxLoc(img1, NULL, &max);
    max = pow(max, 2.0);
    Scalar result = cv::mean(pow2);
;
    return result.val[0]/pow(max, 2.0);
}
double ProcessingCore::normalizedAbsoluteError(Mat img1, Mat img2)
{
    Scalar result = cv::sum(img1-img2)/cv::sum(img1);
    return result.val[0];
}
double ProcessingCore::normalizedMeanSquareError(Mat img1, Mat img2)
{
    Mat img1pow2, diff;
    cv::pow(img1, 2.0, img1pow2);
    cv::absdiff(img1, img2, diff);
    cv::pow(diff, 2.0, diff);
    Scalar value = cv::sum(diff)/cv::sum(img1pow2);
    return value.val[0];
}
double ProcessingCore::snr(Mat img1, Mat img2)
{
    Mat img1pow2;
    cv::pow(img1, 2.0, img1pow2);
    Mat img1img2pow2;
    cv::pow(img1-img2, 2.0, img1img2pow2);
    cv::Scalar result = cv::sum(img1pow2)/cv::sum(img1img2pow2);
    return 10.0*std::log10(result.val[0]);
}
double ProcessingCore::psnr(Mat img1, Mat img2)
{
    Mat pow2 = img1-img2;
    cv::pow(pow2, 2.0, pow2);
    cv::Scalar mean = cv::mean(pow2);
    double max;
    cv::minMaxLoc(img1, NULL, &max);
    return 10.0*std::log10(std::pow(max, 2.0)/mean.val[0]);
}
