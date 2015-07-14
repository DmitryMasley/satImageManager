#ifndef STANDARDIMAGEMODEL_H
#define STANDARDIMAGEMODEL_H

#include <QObject>
#include <opencv2/opencv.hpp>
#include <opencv2/core/cuda.hpp>
#include "../standardmodel.h"
#include "standardimageitem.h"

class StandardImageModel : public StandardModel
{
    Q_OBJECT
public:
    explicit StandardImageModel(QObject *parent = 0);
    explicit StandardImageModel(const QList<QMap<int, QVariant> > &data, QObject *parent = 0);
    void AddBlankItem();
    void AddMultichannelImage(const cv::Mat image, const QString fileName);
    void AddImage(const cv::Mat image, const QString fileName);
    StandardImageItem* findImage(QString fileName);
signals:

public slots:
private:

signals:

public slots:

};

#endif // STANDARDIMAGEMODEL_H
