#include "StdAfx.h"
#include <opencv2/core.hpp>
#include "ImagePropertiesEvaluating.h"

ImagePropertiesEvaluating::~ImagePropertiesEvaluating(void)
{
}
double ImagePropertiesEvaluating::ShannonEntropyEval(cv::Mat & image)
{
    int maxValue;
	switch (image.depth())
	{
	case CV_16U:
        maxValue=65535;
        return ImagePropertiesEvaluating::ShannonEntropy<unsigned short>(image, maxValue);
		break;
	case CV_8U:
        maxValue = 255;
        return ImagePropertiesEvaluating::ShannonEntropy<unsigned char>(image, maxValue);
		break;
    default:
        return 0;
        break;
	}
}
double ImagePropertiesEvaluating::SignalEntropyEval(cv::Mat& image)
{
    int maxValue;
    switch (image.depth())
    {
    case CV_16U:
        maxValue=65535;
        return ImagePropertiesEvaluating::SignalEntropy<unsigned short>(image, maxValue);
        break;
    case CV_8U:
        maxValue = 255;
        return ImagePropertiesEvaluating::SignalEntropy<unsigned char>(image, maxValue);
        break;
    default:
        return 0;
        break;
    }
}
double ImagePropertiesEvaluating::AdaptationLevelEval(cv::Mat& image)
{
    int maxValue;
    switch (image.depth())
    {
    case CV_16U:
        maxValue=65535;
        return ImagePropertiesEvaluating::AdaptationLevel<unsigned short>(image, maxValue);
        break;
    case CV_8U:
        maxValue = 255;
        return ImagePropertiesEvaluating::AdaptationLevel<unsigned char>(image, maxValue);
        break;
    default:
        return 0;
        break;
    }
}
double ImagePropertiesEvaluating::GradiationsUsingCoefficientEval(cv::Mat & image)
{
    int maxValue;
    switch (image.depth())
    {
    case CV_16U:
        maxValue=65535;
        return ImagePropertiesEvaluating::GradiationsUsingCoefficient<unsigned short>(image, 0, maxValue);
        break;
    case CV_8U:
        maxValue = 255;
        return ImagePropertiesEvaluating::GradiationsUsingCoefficient<unsigned char>(image, 0, maxValue);
        break;
    default:
        return 0;
        break;
    }
}
double ImagePropertiesEvaluating::MaxDynamicContrastEval(cv::Mat & image)
{
    int maxValue;
    switch (image.depth())
    {
    case CV_16U:
        maxValue=65535;
        return ImagePropertiesEvaluating::MaxDynamicContrast<unsigned short>(image, maxValue);
        break;
    case CV_8U:
        maxValue = 255;
        return ImagePropertiesEvaluating::MaxDynamicContrast<unsigned char>(image, maxValue);
        break;
    default:
        return 0;
        break;
    }
}
void ImagePropertiesEvaluating::EvalAllCharatceristics()
{
    //ImagePropertiesEvaluating::ShannonEntropyEval();
}
template<class T>
double ImagePropertiesEvaluating::ShannonEntropy(cv::Mat & image, int maxValue)
{

    cv::Mat p = GetFrequenses<T>(image, maxValue);
    cv::Mat pnew = cv::Mat::ones(1, maxValue+1, CV_64F);
    double scale = image.rows*image.cols*image.channels();
	pnew = p/scale;
    pnew = pnew+7e-16;
    cv::Mat logP = cv::Mat::zeros(1, maxValue+1, CV_64F);
	cv::log(pnew, logP);
    return -cv::sum(pnew.dot(logP/std::log(2.0)))[0];
}
template<class T>
double ImagePropertiesEvaluating::SignalEntropy(cv::Mat & image, int maxValue)
{
    cv::Mat p = GetFrequenses<T>(image, maxValue);
    for (int m=0; m<maxValue+1; m++)
    {
        p.at<double>(m) = p.at<double>(m)*m;
    }

    cv::Mat pnew = cv::Mat::ones(1, maxValue+1, CV_64F);
    pnew = p/(cv::sum(p)[0]);
    pnew = pnew+7e-16;
    cv::Mat logP = cv::Mat::zeros(1, maxValue+1, CV_64F);
    cv::log(pnew, logP);
    return -cv::sum(pnew.dot(logP/std::log(2.0)))[0];
}
template<class T>
double ImagePropertiesEvaluating::GradiationsUsingCoefficient(cv::Mat & image, double n, int maxValue)
{
    double threshold = image.cols*image.rows*n;
    cv::Mat p = GetFrequenses<T>(image, maxValue);
    double S=0;
    for (int i=0; i<=maxValue; i++)
    {
        if (p.at<double>(i)>threshold)
        {
            S=S+1;
        }
    }
    return S/(maxValue+1);
    //Mat mask = Mat::zeros(1, maxValue+1, CV_64F);
    //compare(p, threshold, mask, CMP_LT);


}
template<class T>
cv::Mat ImagePropertiesEvaluating::GetFrequenses(cv::Mat & matrix, int maxValue)
{
    cv::Mat p = cv::Mat::zeros(1, maxValue+1, CV_64F);
    vector<cv::Mat> channels;
    cv::split(matrix, channels);
    int rows =  matrix.rows;
    int cols = matrix.cols;
    for(int n = 0; n<matrix.channels(); n++)
    {
        for(int i = 0; i < rows; i++)
        {
            const T* Mi = channels[n].ptr<T>(i);
            for(int j = 0; j < cols; j++)
            {
                p.at<double>(Mi[j])=p.at<double>(Mi[j])+1;
            }
        }
    }
    return p;
}
template<class T>
double ImagePropertiesEvaluating::AdaptationLevel(cv::Mat & image, int maxValue)
{
    double meanValue = cv::mean(image)[0];
    return 1-(std::abs(meanValue-maxValue/2)/(maxValue/2));
}
template<class T>
double ImagePropertiesEvaluating::MaxDynamicContrast(cv::Mat & image, int maxValue)
{
    vector<double> drop;
    vector<double> el;
    vector<cv::Mat> channels;
    cv::split(image, channels);
    bool direction=false;
    int rows =  image.rows;
    int cols = image.cols;
    for(int n=0; n<image.channels();n++)
    {
        for(int i = 0; i < rows; i++)
        {
            if(isRangeWider(el, drop))
            {
                el = drop;
            }
            drop.clear();
            drop.push_back(channels[n].at<T>(i, 0));
            const T* M = channels[n].ptr<T>(i);
            for(int j = 0; j < cols; j++)
            {
                if (j==0)
                {
                    continue;
                }
                if (M[j]>M[j-1])
                {
                    if(direction)
                    {
                        drop.push_back((double)M[j]);
                    }
                    else
                    {
                        direction = !direction;
                        if(isRangeWider(el, drop))
                        {
                            el.clear();
                            el = drop;
                        }
                        double lastEl = drop.back();
                        drop.clear();
                        drop.push_back(lastEl);
                        drop.push_back((double)M[j]);
                    }
                }
                else
                {
                    if(!direction)
                    {
                        drop.push_back((double)M[j]);
                    }
                    else
                    {
                        direction = !direction;
                        if(isRangeWider(el, drop))
                        {
                            el.clear();
                            el=drop;
                        }
                        double lastEl = drop.back();
                        drop.clear();
                        drop.push_back(lastEl);
                        drop.push_back((double)M[j]);
                    }
                }

            }
        }
    }
    vector<double> diffs = diffVector<double>(el);
    vector<double> powDiffs;
    cv::pow(diffs, 2.0, powDiffs);
    diffs.empty();
    double elMax = *(std::max_element(el.begin(), el.end()));
    double elMin = *(std::min_element(el.begin(), el.end()));
    return (cv::sum(powDiffs)[0]/(elMax-elMin))/maxValue;
}
bool ImagePropertiesEvaluating::isRangeWider(vector<double> el, vector<double> newEl)
{
    double elMax=0, elMin=0, newElMax=0, newElMin=0;
    if (el.size())
    {
        elMax = *(std::max_element(el.begin(), el.end()));
        elMin = *(std::min_element(el.begin(), el.end()));
    }
    if (newEl.size())
    {
        newElMax = *(std::max_element(newEl.begin(), newEl.end()));
        newElMin = *(std::min_element(newEl.begin(), newEl.end()));
    }
    return (elMax-elMin)<(newElMax-newElMin);
}
template<class T>
vector<T> ImagePropertiesEvaluating::diffVector(vector<T> sq)
{
    vector<T> diffs;
    int length = sq.size();
    for (int i = 0; i<length-1; i++)
    {
        diffs.push_back(sq[i+1]-sq[i]);
    }
    return diffs;
}

//void ImageProperties::Iteration(void (*callback)(int Value))
//{
//	for(int i = 0; i < image.rows; i++)
//	{
//		const int* Mi = image.ptr<int>(i);
//		for(int j = 0; j < image.cols; j++)
//		{
//			callback(Mi[j]);
//		}
//
//	}
//}
