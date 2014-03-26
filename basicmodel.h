#ifndef BASICMODEL_H
#define BASICMODEL_H
#include "stdafx.h"
#include <QObject>
struct DropPoint
{
    int row;
    int column;
    QModelIndex parent;
};

class BasicModel : public QAbstractItemModel
{
    Q_OBJECT
public:
    explicit BasicModel(QObject *parent = 0);
    explicit BasicModel(QList<QList<QVariant> > headers, QObject *parent = 0);
    explicit BasicModel(QList<QList<QVariant> > _horisontalHeaders, QList<QList<QVariant> > _verticalHeaders, QObject *parent = 0);
    void emptyHeaders(Qt::Orientation orientation);
    ~BasicModel();
    QVariant data(const QModelIndex &index, int role) const;
    QVariant headerData(int section, Qt::Orientation orientation,
                        int role = Qt::DisplayRole) const;
    QModelIndex index(int row, int column,
                      const QModelIndex &parent = QModelIndex()) const;
    QModelIndex parent(const QModelIndex &index) const;
    int rowCount(const QModelIndex &parent = QModelIndex()) const;
    int columnCount(const QModelIndex &parent = QModelIndex()) const;
    bool setData ( const QModelIndex & index, const QVariant & value, int role = Qt::EditRole );
    bool setItemData(const QModelIndex &index, const QList<QList<QVariant> > &data);
    BasicModelItem* getRootNode();
    void setRootNode(BasicModelItem* item);
    void setRootNodeData(QList<QList<QVariant> > data);
    void AddItem(BasicModelItem* item, BasicModelItem* parent = 0);
    virtual void AddBlankItem();
    void removeItem(QModelIndex item);
    BasicModelItem* getItem(const QModelIndex &index) const;
    Qt::ItemFlags flags(const QModelIndex &index) const;
    void empty();
//    bool insertColumns(int position, int columns, const QModelIndex &parent = QModelIndex());
//    bool removeColumns(int position, int columns, const QModelIndex &parent = QModelIndex());
    bool insertRows(int position, int rows, const QModelIndex &parent = QModelIndex());
    bool insertRows(int position, int rows, QList<QList<QVariant> >data, const QModelIndex &parent = QModelIndex());
    bool insertRows(int position, int rows, BasicModelItem* item, const QModelIndex &parent);
    bool removeRows(int position, int rows, const QModelIndex &parent = QModelIndex());
    virtual QStringList mimeTypes() const;
    virtual QMimeData* mimeData(const QModelIndexList &indexes) const;
    virtual bool dropMimeData(const QMimeData *data, Qt::DropAction action, int row, int column, const QModelIndex &parent);
    Qt::DropActions supportedDropActions() const;
    virtual bool canDropMimeData(const QMimeData * data,
                                             Qt::DropAction action,
                                             int row,
                                             int column,
                                             const QModelIndex & parent) const;
    BasicModelItem* createItem(QString type, QList<QList<QVariant> >data);
    QModelIndexList virtual parseDropData(QModelIndexList indexes);
    QList<QList<QVariant> > verticalHeaders;
protected:
    BasicModelItem* _root;
    DropPoint findParentForDrop(const QMimeData* data, Qt::DropAction action, int row, int column, const QModelIndex parent);
signals:
    
public slots:
private:
    
};

#endif // BASICMODEL_H
