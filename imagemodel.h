#ifndef IMAGEMODEL_H
#define IMAGEMODEL_H
#include "stdafx.h"
#include "imageitem.h"
#include <QObject>

class ImageModel : public BasicModel
{
    Q_OBJECT
public:
    explicit ImageModel(const QList<QList<QVariant> > &data, QObject *parent = 0);
    void AddBlankItem();
    void AddMultichannelImage(const Mat image, const QString fileName);
    void AddImage(const Mat image, const QString fileName);
    ImageItem* findImage(QString fileName);
signals:
    
public slots:
private:
    
};

#endif // IMAGEMODEL_H
