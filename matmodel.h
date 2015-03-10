#ifndef MATMODEL_H
#define MATMODEL_H
#include "stdafx.h"
#include <QObject>
#include "matmodelitem.h"
#include <QAbstractItemModel>
#include <QModelIndex>
#include <QVariant>
#include <opencv2/core.hpp>

class MatModel : public QAbstractItemModel
{
    Q_OBJECT
public:
    explicit MatModel(cv::Mat matrix, int type=NULL, QObject *parent = 0);
    virtual ~MatModel();
    QVariant data(const QModelIndex &index, int role) const;
    Qt::ItemFlags flags(const QModelIndex &index) const;
    QVariant headerData(int section, Qt::Orientation orientation,
                        int role = Qt::DisplayRole) const;
    QModelIndex index(int row, int column,
                      const QModelIndex &parent = QModelIndex()) const;
    QModelIndex parent(const QModelIndex &index) const;
    int rowCount(const QModelIndex &parent = QModelIndex()) const;
    int columnCount(const QModelIndex &parent = QModelIndex()) const;
signals:
    
public slots:
private:
    cv::Mat _matrix;
    int _type;
    MatModelItem* _item;
};

#endif // MATMODEL_H
