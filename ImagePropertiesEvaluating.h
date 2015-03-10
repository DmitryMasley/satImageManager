#pragma once
#include "stdafx.h"
#include <opencv2/core.hpp>
#include <vector>
using namespace std;
class ImagePropertiesEvaluating
{
public:
    //ImagePropertiesEvaluating(Mat & M);
    ~ImagePropertiesEvaluating(void);
	void EvalAllCharatceristics();
    static double ShannonEntropyEval(cv::Mat&);
    static double SignalEntropyEval(cv::Mat&);
    static double GradiationsUsingCoefficientEval(cv::Mat&);
    static double AdaptationLevelEval(cv::Mat&);
    static double MaxDynamicContrastEval(cv::Mat&);
private:
    //Mat image;
	template<class T>
    static double ShannonEntropy(cv::Mat&, int);
    template<class T>
    static double SignalEntropy(cv::Mat&, int);
    template<class T>
    static double GradiationsUsingCoefficient(cv::Mat&, double, int);
    template<class T>
    static double AdaptationLevel(cv::Mat&, int);
    template<class T>
    static double MaxDynamicContrast(cv::Mat&, int);
    template<class T>
    static cv::Mat GetFrequenses(cv::Mat&, int);
    static bool isRangeWider(vector<double> el, vector<double> newEl);
    template<class T>
    static vector<T> diffVector(vector<T> sq);
    //int maxValue;
};
