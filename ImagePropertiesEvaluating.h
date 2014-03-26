#pragma once
#include "stdafx.h"
class ImagePropertiesEvaluating
{
public:
    //ImagePropertiesEvaluating(Mat & M);
    ~ImagePropertiesEvaluating(void);
	void EvalAllCharatceristics();
    static double ShannonEntropyEval(Mat&);
    static double SignalEntropyEval(Mat&);
    static double GradiationsUsingCoefficientEval(Mat&);
    static double AdaptationLevelEval(Mat&);
    static double MaxDynamicContrastEval(Mat&);
private:
    //Mat image;
	template<class T>
    static double ShannonEntropy(Mat&, int);
    template<class T>
    static double SignalEntropy(Mat&, int);
    template<class T>
    static double GradiationsUsingCoefficient(Mat&, double, int);
    template<class T>
    static double AdaptationLevel(Mat&, int);
    template<class T>
    static double MaxDynamicContrast(Mat&, int);
    template<class T>
    static Mat GetFrequenses(Mat&, int);
    static bool isRangeWider(vector<double> el, vector<double> newEl);
    template<class T>
    static vector<T> diffVector(vector<T> sq);
    //int maxValue;
};
