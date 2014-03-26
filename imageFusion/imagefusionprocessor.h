#ifndef IMAGEFUSIONPROCESSOR_H
#define IMAGEFUSIONPROCESSOR_H
#include "../stdafx.h"
#include <QObject>

class ImageFusionProcessor : public QObject
{
    Q_OBJECT
public:
    explicit ImageFusionProcessor(Mat input, Mat pan, int panType, int orthType = 0, QObject *parent = 0);
    void exec();
    Mat result;
    Mat disp;
    Mat w;
    Mat u;
    Mat vt;
    Mat uDisp;
private:
    Mat inputMatrix;
    Mat panImage;
    int type;
    int orthogonalizationType;
    Mat getDispertion(Mat input);
signals:

public slots:

};

#endif // IMAGEFUSIONPROCESSOR_H
