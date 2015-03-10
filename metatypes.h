#ifndef METATYPES
#define METATYPES
#include <iostream> // for standard I/O
#include <string> // for strings
#include <QObject>
#include <opencv2/imgproc/imgproc.hpp> // Gaussian Blur
#include <opencv2/core/core.hpp> // Basic OpenCV structures (cv::Mat, Scalar)
#include <opencv2/highgui/highgui.hpp> // OpenCV window I/O
#include <opencv2/imgproc/imgproc_c.h>
#include <opencv2/core/mat.hpp>
#include <opencv2/core/cuda.hpp>
#include <QImage>
#include <QVariant>
#include <QList>
Q_DECLARE_METATYPE(cv::Mat)
Q_DECLARE_METATYPE(QImage*)
Q_DECLARE_METATYPE(QList<QList<QVariant> >)
#endif // METATYPES

