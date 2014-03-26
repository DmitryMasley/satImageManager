#ifndef MATMODELITEM_H
#define MATMODELITEM_H
#include "stdafx.h"
#include <QObject>

class MatModelItem : public QObject
{
    Q_OBJECT
public:
    explicit MatModelItem(QObject *parent = 0);
    Mat value;
signals:
    
public slots:
    
};

#endif // MATMODELITEM_H
