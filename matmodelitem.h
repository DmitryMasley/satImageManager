#ifndef MATMODELITEM_H
#define MATMODELITEM_H
#include "stdafx.h"
#include <opencv2/core.hpp>
#include <QObject>

class MatModelItem : public QObject
{
    Q_OBJECT
public:
    explicit MatModelItem(QObject *parent = 0);
    cv::Mat value;
signals:
    
public slots:
    
};

#endif // MATMODELITEM_H
