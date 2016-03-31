#ifndef STANDARDIMAGEMODEL_H
#define STANDARDIMAGEMODEL_H

#include <QObject>
#include <qurl.h>
#include <opencv2/opencv.hpp>
#include <opencv2/core/cuda.hpp>
#include "../standardmodel.h"
#include "standardimageitem.h"

class StandardImageModel : public StandardModel
{
    Q_OBJECT
public:
    explicit StandardImageModel(QObject *parent = 0);
    explicit StandardImageModel(const QList<QMap<int, QVariant> > &headerData, QObject *parent = 0);
    void AddBlankItem();
    void AddMultichannelImage(const cv::Mat image, const QString fileName);
    void AddImage(const cv::Mat image, const QString fileName);
    StandardImageItem* findImage(QString fileName);
    void addCustomData(QMimeData *data, const QModelIndexList indexes) const;
signals:

public slots:
private:

signals:

public slots:

};

#endif // STANDARDIMAGEMODEL_H
