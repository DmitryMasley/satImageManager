#pragma once
#include <stdafx.h>
#define ALLCHANNEL -1
using namespace cv;
using namespace std;

struct QRresult
{
    Mat Q;
    Mat R;
};
struct QRresultGPU
{
    gpu::GpuMat Q;
    gpu::GpuMat R;
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
    static Mat readImage(QString & s);
//	static System::String^ MarshalString ( std::string& os );
    static QRresult mgs_qr(Mat &A);
    static QImage* convertToQImage(Mat &matrix);
    static std::vector<QImage*> splitToQImage(Mat matrix);
    static cv::Mat getChannel(Channels ch, Mat & matrix);
    static cv::Mat FFT(Mat image);
//    static gpu::GpuMat FFT(gpu::GpuMat image);
    static cv::Mat IFT(Mat transform, int origType=CV_8U);
//    static gpu::GpuMat IFT(gpu::GpuMat, int origType=CV_8U);
    static bool writeImage(QString fileName, Mat image);
    static QIcon convertToQIcon(Mat image, int width=40, int height=40);
    static Mat RGB2BGR(Mat image);
    static double calcSSIM(cv::Mat& src1,
                cv::Mat& src2,
                cv::Mat& mask,
                cv::Mat& ssim_map,
                int channel = 0,
                int method=CV_BGR2YUV,
                const double K1 = 0.01,
                const double K2 = 0.03,
                const int L = 255,
                const int downsamplewidth=256,
                const int gaussian_window=11,
                const double gaussian_sigma=1.5);
    static double calcSSIM(cv::Mat& src1,
                cv::Mat& src2,
                int channel = 0,
                int method=CV_BGR2YUV,
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
                  int method=CV_BGR2YUV,
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
                  int method=CV_BGR2YUV,
                  int boundx=0,
                  int boundy=0,
                  const double K1 = 0.01,
                  const double K2 = 0.03,
                  const int L = 255,
                  const int downsamplewidth=256,
                  const int gaussian_window=11,
                  const double gaussian_sigma=1.5);
    static double meanDiff(Mat img1, Mat img2);
    static double normCorrelation(Mat img1, Mat img2);
    static double correlationQuality(Mat img1, Mat img2);
    static double maxDiff(Mat img1, Mat img2);
    static double imageFidelity(Mat img1, Mat img2);
    template<class T>
    static Mat getO(Mat img);
    static double laplMeanSqError(Mat img1, Mat img2);
    static double meanSqError(Mat img1, Mat img2);
    static double peakMeanSqError(Mat img1, Mat img2);
    static double normalizedAbsoluteError(Mat img1, Mat img2);
    static double normalizedMeanSquareError(Mat img1, Mat img2);
    static double snr(Mat img1, Mat img2);
    static double psnr(Mat img1, Mat img2);


//double calcDSSIM(cv::Mat& src1, cv::Mat& src2, int channel = 0, int method=CV_BGR2YUV, cv::Mat& mask=cv::Mat(),const double K1 = 0.01, const double K2 = 0.03,	const int L = 255, const int downsamplewidth=256, const int gaussian_window=11, const double gaussian_sigma=1.5, cv::Mat& ssim_map=cv::Mat());
//double calcDSSIMBB(cv::Mat& src1, cv::Mat& src2, int channel = 0, int method=CV_BGR2YUV, int boundx=0,int boundy=0,const double K1 = 0.01, const double K2 = 0.03,	const int L = 255, const int downsamplewidth=256, const int gaussian_window=11, const double gaussian_sigma=1.5, cv::Mat& ssim_map=cv::Mat());

//	static System::Drawing::Bitmap^ convertmatToBitmap(Mat matrix, int width, int height, int channel);
private:
//	template<class channelsType, class BitDeph>
//	static System::Drawing::Bitmap^ getBitmap(Mat &matrix, int width, int height, int channel);
	static void getBasicCharacteristics(Mat image);
	template<class T>
	static void matIteration(Mat M,  void (*callback)(T Value));
};
