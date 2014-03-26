#ifndef DDMIMEDATA_H
#define DDMIMEDATA_H
#include "stdafx.h"
#include <QMimeData>

class DDMimeData : public QMimeData
{
    Q_OBJECT
public:
    explicit DDMimeData();
    explicit DDMimeData(QList<QList<QList<QVariant> > > data);
    const QList<QList<QList<QVariant> > > getIndexesData();
    void setIndexesData(QList<QList<QList<QVariant> > > data);
    void setIndexes(QModelIndexList);
    QModelIndexList getIndexes();
    QList<QList<QList<QVariant> > > _data;
    QModelIndexList _indexes;
signals:
    
public slots:    
};

#endif // DDMIMEDATA_H
