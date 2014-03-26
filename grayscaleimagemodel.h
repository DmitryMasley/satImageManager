#ifndef GRAYSCALEIMAGEMODEL_H
#define GRAYSCALEIMAGEMODEL_H

#include <stdafx.h>
#include "imagemodel.h"

class GrayScaleImageModel : public ImageModel
{
    Q_OBJECT
public:
    explicit GrayScaleImageModel(const QList<QList<QVariant> > &data, QObject *parent = 0);
    QModelIndexList parseDropData(QModelIndexList indexes);
    
signals:
    
public slots:
    
};

#endif // IMAGEFUSIONSOURSESMODEL_H
