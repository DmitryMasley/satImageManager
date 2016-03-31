#ifndef GRAYSCALEIMAGEMODEL_H
#define GRAYSCALEIMAGEMODEL_H

#include <stdafx.h>
#include "lib/image/standardimagemodel.h"

class GrayScaleImageModel : public StandardImageModel
{
    Q_OBJECT
public:
    explicit GrayScaleImageModel(const QList<QMap<int, QVariant> > &data, QObject *parent = 0);
    QModelIndexList parseDropData(QModelIndexList indexes);
    
signals:
    
public slots:
    
};

#endif // IMAGEFUSIONSOURSESMODEL_H
