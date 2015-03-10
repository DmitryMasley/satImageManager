#ifndef IMAGECHARACTERISTICSITEM_H
#define IMAGECHARACTERISTICSITEM_H
#include "stdafx.h"
#include <QList>
#include <QVariant>

class CharacteristicsItem
{
public:
    CharacteristicsItem();
    CharacteristicsItem(const QList<QList<QVariant> > & data, QString  header=QString(""), CharacteristicsItem *parent = 0);
    ~CharacteristicsItem();
    void appendChild(CharacteristicsItem *child);
    void appendChildren(QList<CharacteristicsItem *> children);
    void clearChildren();
    void setParent(CharacteristicsItem *parent);
    CharacteristicsItem *child(int row);
    int childCount() const;
    int columnCount() const;
    QVariant data(int column, int role) const;
    QString getHeader();
    int row() const;
    void setData(QVariant data, int column=0, int role=0);
    //ImageCharacteristicsItem *parent();
    //void remove();
private:
    QList<QList<QVariant> > _data;
    QString _header;
    CharacteristicsItem* _parent;
    QList<CharacteristicsItem*> _childItems;
};

#endif // IMAGECHARACTERISTICSITEM_H
