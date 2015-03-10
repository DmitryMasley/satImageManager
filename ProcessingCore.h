#pragma once
#include <stdafx.h>
#define ALLCHANNEL -1
#include <opencv2/opencv.hpp>
#include <opencv2/core/cuda.hpp>
#include <QString>
#include <QImage>
#include <QIcon>
#include <QPixmap>
using namespace std;

struct QRresult
{
    cv::Mat Q;
    cv::Mat R;
};
struct QRresultGPU
{
    cv::cuda::GpuMat Q;
    cv::cuda::GpuMat R;
};
enum Channels
{
    All=-1,
    B = 0,
    G = 1,
    R = 2,
    A = 3

};
struct ImageProperties
{
    double SignalEntropy;
    double ShannonEntropy;
    double AdaptationLevelOfBrightness;
    double GradationsUsingCoefficient;
    double MaxDynamicContrast;
};
class ProcessingCore
{
    public:
    ProcessingCore(void);
    static std::string convertToStdString( QString& s );
    static cv::Mat readImage(QString & s);
//	static System::String^ MarshalString ( std::string& os );
    static QRresult mgs_qr(cv::Mat &A);
    static QImage* convertToQImage(cv::Mat &matrix);
    static std::vector<QImage*> splitToQImage(cv::Mat matrix);
    static cv::Mat getChannel(Channels ch, cv::Mat & matrix);
    static cv::Mat FFT(cv::Mat image);
//    static gpu::GpuMat FFT(gpu::GpuMat image);
    static cv::Mat IFT(cv::Mat transform, int origType=CV_8U);
//    static gpu::GpuMat IFT(gpu::GpuMat, int origType=CV_8U);
    static bool writeImage(QString fileName, cv::Mat image);
    static QIcon convertToQIcon(cv::Mat image, int width=40, int height=40);
    static cv::Mat RGB2BGR(cv::Mat image);
    static cv::Scalar getMSSIM(const cv::Mat& i1, const cv::Mat& i2, cv::Mat& ssim_map);
    static double calcSSIM(cv::Mat& src1,
                cv::Mat& src2,
                cv::Mat& mask,
                cv::Mat& ssim_map,
                int channel = 0,
                int method=cv::COLOR_BGR2YUV,
                const double K1 = 0.01,
                const double K2 = 0.03,
                const int L = 255,
                const int downsamplewidth=256,
                const int gaussian_window=11,
                const double gaussian_sigma=1.5);
    static double calcSSIM(cv::Mat& src1,
                cv::Mat& src2,
                int channel = 0,
                int method=cv::COLOR_BGR2YUV,
                const double K1 = 0.01,
                const double K2 = 0.03,
                const int L = 255,
                const int downsamplewidth=256,
                const int gaussian_window=11,
                const double gaussian_sigma=1.5);
    static double calcSSIMBB(cv::Mat& src1,
                  cv::Mat& src2,
                  cv::Mat& ssim_map,
                  int channel = 0,
                  int method=cv::COLOR_BGR2YUV,
                  int boundx=0,
                  int boundy=0,
                  const double K1 = 0.01,
                  const double K2 = 0.03,
                  const int L = 255,
                  const int downsamplewidth=256,
                  const int gaussian_window=11,
                  const double gaussian_sigma=1.5);
    static double calcSSIMBB(cv::Mat& src1,
                  cv::Mat& src2,
                  int channel = 0,
                  int method=cv::COLOR_BGR2YUV,
                  int boundx=0,
                  int boundy=0,
                  const double K1 = 0.01,
                  const double K2 = 0.03,
                  const int L = 255,
                  const int downsamplewidth=256,
                  const int gaussian_window=11,
                  const double gaussian_sigma=1.5);
    static double meanDiff(cv::Mat img1, cv::Mat img2);
    static double normCorrelation(cv::Mat img1, cv::Mat img2);
    static double correlationQuality(cv::Mat img1, cv::Mat img2);
    static double maxDiff(cv::Mat img1, cv::Mat img2);
    static double imageFidelity(cv::Mat img1, cv::Mat img2);
    template<class T>
    static cv::Mat getO(cv::Mat img);
    static double laplMeanSqError(cv::Mat img1, cv::Mat img2);
    static double meanSqError(cv::Mat img1, cv::Mat img2);
    static double peakMeanSqError(cv::Mat img1, cv::Mat img2);
    static double normalizedAbsoluteError(cv::Mat img1, cv::Mat img2);
    static double normalizedMeanSquareError(cv::Mat img1, cv::Mat img2);
    static double snr(cv::Mat img1, cv::Mat img2);
    static double psnr(cv::Mat img1, cv::Mat img2);


//double calcDSSIM(cv::Mat& src1, cv::Mat& src2, int channel = 0, int method=CV_BGR2YUV, cv::Mat& mask=cv::Mat(),const double K1 = 0.01, const double K2 = 0.03,	const int L = 255, const int downsamplewidth=256, const int gaussian_window=11, const double gaussian_sigma=1.5, cv::Mat& ssim_map=cv::Mat());
//double calcDSSIMBB(cv::Mat& src1, cv::Mat& src2, int channel = 0, int method=CV_BGR2YUV, int boundx=0,int boundy=0,const double K1 = 0.01, const double K2 = 0.03,	const int L = 255, const int downsamplewidth=256, const int gaussian_window=11, const double gaussian_sigma=1.5, cv::Mat& ssim_map=cv::Mat());

//	static System::Drawing::Bitmap^ convertmatToBitmap(Mat matrix, int width, int height, int channel);
private:
//	template<class channelsType, class BitDeph>
//	static System::Drawing::Bitmap^ getBitmap(Mat &matrix, int width, int height, int channel);
    static void getBasicCharacteristics(cv::Mat image);
	template<class T>
    static void matIteration(cv::Mat M,  void (*callback)(T Value));
};
