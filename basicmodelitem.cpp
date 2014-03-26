#include "basicmodelitem.h"

BasicModelItem::BasicModelItem(BasicModelItem *parent, bool isRoot)
{
    if(parent)
    {
        this->setParent(parent);
    }
    else
    {
        _parent = 0;
    }
    _isComposite = false;
    _isRoot = isRoot;
    this->setClassName();
}
BasicModelItem::BasicModelItem(QList<QList<QVariant> > data, BasicModelItem *parent, bool isRoot)
{
    if(parent)
    {
        this->setParent(parent);
    }
    else
    {
        _parent = 0;
    }
    _data = data;
    _isComposite = false;
    _isRoot = isRoot;
    this->setClassName();
}
BasicModelItem::BasicModelItem(BasicModelItem &item)
{
    this->setItemData(item.getData());
    this->setParent(0);
    this->setClassName();
}

BasicModelItem::~BasicModelItem()
{
    qDeleteAll(_children);
}
void BasicModelItem::setClassName(){
    this->setProperty("type", QString("BasicModelItem"));
}
QString BasicModelItem::getClassName()
{
    return this->property("type").toString();
}

bool BasicModelItem::isRoot()
{
    return _isRoot;
}

void BasicModelItem::appendChild(BasicModelItem *item, int row)
{
    if(!_children.contains(item))
    {
        if(row == -1)
        {
            _children.append(item);
        }
        else
        {
            _children.insert(row, item);
        }
    }
    item->setParent(this);
    this->onChildrenChanged();
}
void BasicModelItem::setParent(BasicModelItem *parent)
{
    _parent = parent;
    if (_parent && !_parent->_children.contains(this))
    {
        _parent->_children.append(this);
    }
}

BasicModelItem* BasicModelItem::child(int row)
{
    return _children.value(row);
}
int BasicModelItem::childCount() const
{
    return _children.count();
}
int BasicModelItem::row() const
{
    if (_parent)
        return _parent->_children.indexOf(const_cast<BasicModelItem*>(this));

    return 0;
}
int BasicModelItem::columnCount() const
{
   return _data.count();
}
QVariant BasicModelItem::data(int column, int role) const
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
bool BasicModelItem::setData(int column, const QVariant &value, int role)
{
    if (column < 0 || column >= _data.size())
        return false;
    QList<QVariant> dataItem = _data.at(column);
    dataItem[role] = QVariant(value);
    _data.replace(column, dataItem);
    return true;
}
BasicModelItem* BasicModelItem::parent()
{
    return _parent;
}
bool BasicModelItem::setItemData(QList<QList<QVariant> > data)
{
    _data = data;
    return true;
}
void BasicModelItem::addData(QList<QVariant> dataItem)
{
    _data.append(dataItem);
}
QList<QList<QVariant> > BasicModelItem::getData()
{
    return _data;
}

void BasicModelItem::setChildren(QList<BasicModelItem *> children)
{
    _children = children;
}
QList<BasicModelItem*> BasicModelItem::getChildren()
{
    return _children;
}
void BasicModelItem::removeChild(BasicModelItem* child)
{
   _children.removeOne(child);
   this->onChildrenChanged();
}

void BasicModelItem::remove()
{
    if (this !=0)
    {
        if(_parent !=0)
        {
            _parent->removeChild(this);
        }
        _parent = 0;
        delete this;
    }
}
void BasicModelItem::empty()
{
    this->removeChildren(0, this->childCount());
}
bool BasicModelItem::removeChildren(int position, int count)
{
    if (position < 0 || position + count > _children.size())
        return false;

    for (int row = 0; row < count; ++row)
        delete _children.takeAt(position);
    this->onChildrenChanged();
    return true;
}
bool BasicModelItem::canAcceptDrops()
{
    return isRoot() || (this->canHaveChildren() && this->canAcceptMoreChildren());
}
bool BasicModelItem::canAcceptMoreChildren()
{
    return true;
}
void BasicModelItem::onChildrenChanged()
{

}
bool BasicModelItem::canHaveChildren()
{
    return false;
}
QStringList BasicModelItem::getHeaders()
{
    return _headers;
}
void BasicModelItem::setHeaders(QStringList headers)
{
    _headers = headers;
}
QString BasicModelItem::getType()
{
    return this->property("type").toString();
}
BasicModelItem* BasicModelItem::findItem(QVariant value, int column, int role)
{
    BasicModelItem* child = 0;
    foreach (BasicModelItem* item, _children)
    {
        QVariant _value = item->data(column, role);
        if(value == _value)
        {
            child = item;
            break;
        }
    }
    return child;
}
