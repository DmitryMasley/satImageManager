#ifndef IMAGECHARACTERISTICSMODEL_H
#define IMAGECHARACTERISTICSMODEL_H
#include "stdafx.h"

class CharacteristicsModel : public QAbstractItemModel
{
public:
    CharacteristicsModel();
    CharacteristicsModel(const QList<QList<QVariant> > &headers, QObject* parent = 0);
    ~CharacteristicsModel();

    //minimum model members

    QVariant data(const QModelIndex &index, int role) const;
//    Qt::ItemFlags flags(const QModelIndex &index) const;
    QVariant headerData(int section, Qt::Orientation orientation,
                        int role = Qt::DisplayRole) const;
    QModelIndex index(int row, int column,
                      const QModelIndex &parent = QModelIndex()) const;
    QModelIndex parent(const QModelIndex &index) const;
    int rowCount(const QModelIndex &parent = QModelIndex()) const;
    int columnCount(const QModelIndex &parent = QModelIndex()) const;

    //additional functions
    void appendItem(CharacteristicsItem* item);
    void appendItems(QList<CharacteristicsItem*> items);
    void clear();
    void setCurrentItem(ImageItem *item=0);
    ImageItem* getCurrentItem();
    void setCharacteristic(int row, QVariant data);
    void resetModel();
private:
    //void setupModelData(const QStringList &lines, TreeItem *parent);
    CharacteristicsItem* _root;
    QList<QList<QVariant> > _items;
    ImageItem* _currentItem;
    QList<CharacteristicsItem*> _getDefaultItems();
};

#endif // IMAGECHARACTERISTICSMODEL_H
