#ifndef IMAGEFUSIONPROCESSOR_H
#define IMAGEFUSIONPROCESSOR_H
#include "../stdafx.h"
#include <opencv2/core.hpp>
#include <QObject>
#include "ProcessingCore.h"

class ImageFusionProcessor : public QObject
{
    Q_OBJECT
public:
    explicit ImageFusionProcessor(cv::Mat input, cv::Mat pan, int panType, int orthType = 0, QObject *parent = 0);
    void exec();
    cv::Mat result;
    cv::Mat disp;
    cv::Mat w;
    cv::Mat u;
    cv::Mat vt;
    cv::Mat uDisp;
private:
    cv::Mat inputMatrix;
    cv::Mat panImage;
    int type;
    int orthogonalizationType;
    cv::Mat getDispertion(cv::Mat input);
signals:

public slots:

};

#endif // IMAGEFUSIONPROCESSOR_H
