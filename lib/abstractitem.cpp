#include "abstractitem.h"

AbstractItem::AbstractItem(QObject *parent) :
    QObject(parent)
{
}
AbstractItem::AbstractItem(bool isRoot, QObject *parent) : QObject(parent)
{
    setRoot(isRoot);
}
AbstractItem::AbstractItem(QList<QMap<int, QVariant> > data, QObject *parent, bool isRoot) : QObject(parent)
{
    _data = data;
    setRoot(isRoot);
}
AbstractItem::AbstractItem(const AbstractItem &item)
{
//    this->setItemData(item.getData());
}

AbstractItem::~AbstractItem()
{

}
QString AbstractItem::getClassName()
{
    return this->staticMetaObject.className();
}
bool AbstractItem::root()
{
    return _root;
}
void AbstractItem::setRoot(bool isRoot)
{
    _root=isRoot;
    emit this->rootChanged();
}


void AbstractItem::appendChild(QObject *item, int row)
{
    item->setParent(this);
    this->onChildrenChanged();
}

AbstractItem* AbstractItem::child(int col)
{
    return this->getChildren().at(col);
}
int AbstractItem::childCount() const
{
    return this->children().count();
}
int AbstractItem::row()
{
    return this->parent()->children().indexOf(this);
}
int AbstractItem::columnCount() const
{
   return _data.count();
}
QVariant AbstractItem::data(int column, int role) const
{
    if (column < _data.size() &&  role < _data.value(column).size())
    {
        return _data.value(column).value(role, QVariant());
    }
    else
    {
        return QVariant();
    }
}
bool AbstractItem::setData(int column, const QVariant &value, int role)
{
    if (column < 0 || column >= _data.size())
        return false;
    QMap<int, QVariant> dataItem = _data.at(column);
    dataItem.insert(role, QVariant(value));
    _data.replace(column, dataItem);
    return true;
}
bool AbstractItem::setItemData(QList<QMap<int, QVariant> > data)
{
    _data = data;
    return true;
}
void AbstractItem::addData(QMap<int, QVariant> dataItem)
{
    _data.append(dataItem);
}
QList<QMap<int, QVariant> > AbstractItem::getData()
{
    return _data;
}

QObjectList AbstractItem::setChildren(QObjectList children)
{
    QObjectList prevChildren = this->children();
    // remove old children
    foreach (QObject* child, prevChildren) {
        child->setParent(0);
    }
    // set new
    foreach (QObject* child, children) {
        child->setParent(this);
    }
    return prevChildren;
}
void AbstractItem::removeChild(QObject* child)
{
   child->setParent(0);
   this->onChildrenChanged();
}

void AbstractItem::remove()
{
    if (this !=0)
    {
        this->setParent(0);
        delete this;
    }
}
void AbstractItem::empty()
{
    foreach (QObject* child, this->children()) {
        child->setParent(0);
    }
}
bool AbstractItem::removeChildren(int position, int count)
{
    if (position < 0 || position + count > this->children().size())
        return false;
    QObjectList children = this->children();
    for (int row = 0; row < count; ++row)
        delete children.takeAt(position);
    this->onChildrenChanged();
    return true;
}
bool AbstractItem::canAcceptDrops(QString type)
{
    return this->getType()== type && (root() || (this->canHaveChildren() && this->canAcceptMoreChildren()));
}
bool AbstractItem::canAcceptMoreChildren()
{
    return true;
}
void AbstractItem::onChildrenChanged()
{

}
bool AbstractItem::canHaveChildren()
{
    return false;
}
QStringList AbstractItem::getHeaders()
{
    return _headers;
}
void AbstractItem::setHeaders(QStringList headers)
{
    _headers = headers;
}
QString AbstractItem::getType()
{
    return this->metaObject()->className();
}
AbstractItem* AbstractItem::findItem(QVariant value, int column, int role)
{
    AbstractItem* child = 0;
    foreach (QObject* item, this->children())
    {
        AbstractItem* abstractItem = static_cast<AbstractItem*>(item);
        QVariant _value = abstractItem->data(column, role);
        if(value == _value)
        {
            child = abstractItem;
            break;
        }
    }
    return child;
}
QList<AbstractItem*> AbstractItem::getChildren()
{
    QList<AbstractItem*> children;
    QObjectList ch = QObject::children();
    foreach (QObject* child, ch) {
        children.append(static_cast<AbstractItem*>(child));
    }
    return children;
}
QMap<int, QVariant> AbstractItem::header() const
{
    return _header;
}
void AbstractItem::setHeader(QMap<int, QVariant> header)
{
    _header = header;
    emit headerChanged(header);
}
