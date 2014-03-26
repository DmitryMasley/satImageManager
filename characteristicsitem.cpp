#include "characteristicsitem.h"
CharacteristicsItem::CharacteristicsItem()
{
}
CharacteristicsItem::CharacteristicsItem(const QList<QList<QVariant> > & data, QString header, CharacteristicsItem *parent)
{
    _data = data;
    _header = header;
    _parent = parent;
}
CharacteristicsItem::~CharacteristicsItem()
{
    qDeleteAll(_childItems);
}
int CharacteristicsItem::childCount() const
{
    return _childItems.count();
}
int CharacteristicsItem::columnCount() const
{
    return _data.count();
}
QVariant CharacteristicsItem::data(int column, int role) const
{
    if (column < _data.size() &&  role < _data.value(column).size())
    {
        return _data.value(column).value(role);
    }
    else
    {
        return QVariant();
    }
}
QString CharacteristicsItem::getHeader()
{
    return _header;
}
CharacteristicsItem* CharacteristicsItem::child(int row)
{
    return _childItems.value(row);
}
int CharacteristicsItem::row() const
{
    if (_parent)
        return _parent->_childItems.indexOf(const_cast<CharacteristicsItem*>(this));

    return 0;
}
void CharacteristicsItem::appendChild(CharacteristicsItem *child)
{
    if (!_childItems.contains(child))
    {
        _childItems.append(child);
        child->setParent(this);
    }
}
void CharacteristicsItem::appendChildren(QList<CharacteristicsItem *> children)
{
    this->_childItems.append(children);
}

void CharacteristicsItem::setParent(CharacteristicsItem *parent)
{
    _parent = parent;
}
void CharacteristicsItem::clearChildren()
{
    for (int i=0; i<_childItems.count(); i++)
    {
        _childItems.value(i)->setParent(0);
    }
    this->_childItems.clear();
}
void CharacteristicsItem::setData(QVariant data, int column, int role)
{
    this->_data[column][role] = data;
}
