#include "basicmodel.h"

BasicModel::BasicModel(QObject *parent) :
    QAbstractItemModel(parent)
{
    _root = new BasicModelItem(0, true);
}
BasicModel::BasicModel(QList<QList<QVariant> > headers, QObject *parent):
    QAbstractItemModel(parent)
{
    _root = new BasicModelItem(headers, 0, true);
}
BasicModel::BasicModel(QList<QList<QVariant> > _horisontalHeaders, QList<QList<QVariant> > _verticalHeaders, QObject *parent)
{
   _root = new BasicModelItem(_horisontalHeaders, 0, true);
   verticalHeaders = _verticalHeaders;
}
BasicModel::~BasicModel()
{
    delete _root;
}
void BasicModel::emptyHeaders(Qt::Orientation orientation)
{
    if(orientation == Qt::Vertical)
    {
        emit layoutAboutToBeChanged();
        verticalHeaders.clear();
        emit layoutChanged();
    }
}

QModelIndex BasicModel::index(int row, int column, const QModelIndex &parent) const
{
    if (!hasIndex(row, column, parent))
        return QModelIndex();
    BasicModelItem* parentItem;
    BasicModelItem *childItem;
    if (!parent.isValid())
    {
        parentItem = _root;
    }
    else
    {
        parentItem = getItem(parent);
    }
    childItem = parentItem->child(row);
    if (childItem)
        return createIndex(row, column, childItem);
    else
        return QModelIndex();
}
QModelIndex BasicModel::parent(const QModelIndex &index) const
{
    if (!index.isValid())
        return QModelIndex();

    BasicModelItem* childItem = getItem(index);
    BasicModelItem* parentItem = childItem->parent();

    if (parentItem == _root)
        return QModelIndex();

    return createIndex(parentItem->row(), 0, parentItem);
}
int BasicModel::rowCount(const QModelIndex &parent) const
{
    BasicModelItem* parentItem;
    if (parent.column() > 0)
        return 0;

    if (!parent.isValid())
        parentItem = _root;
    else
        parentItem = getItem(parent);
    return parentItem->childCount();
}
int BasicModel::columnCount(const QModelIndex &parent) const
{
     if (parent.isValid())
         return getItem(parent)->columnCount();
     else
         return _root->columnCount();
}
QVariant BasicModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
        return QVariant();
    BasicModelItem *item = getItem(index);
    return item->data(index.column(), role);
}
Qt::ItemFlags BasicModel::flags(const QModelIndex &index) const
{
    if (index.isValid())
    {
        return Qt::ItemIsEnabled | Qt::ItemIsSelectable | Qt::ItemIsDragEnabled | Qt::ItemIsDropEnabled;
    }
    else
    {
        return Qt::ItemIsDropEnabled;
    }

}
QVariant BasicModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if (orientation == Qt::Horizontal)
    {
        return _root->data(section, role);
    }
    else if(orientation == Qt::Vertical)
    {
        if(verticalHeaders.count()>section)
        {
            QList<QVariant> data = verticalHeaders.at(section);
            if(data.count()>role)
            {
                return data.at(role);
            }
        }
    }

    return QVariant();
}
BasicModelItem* BasicModel::getRootNode()
{
    return _root;
}
void BasicModel::setRootNode(BasicModelItem *item)
{
    delete _root;
    _root = item;
}

void BasicModel::setRootNodeData(QList<QList<QVariant> > data)
{
    _root->setItemData(data);
}

void BasicModel::AddItem(BasicModelItem* item, BasicModelItem* parent)
{
    if (parent==0)
    {
        parent = _root;
    }
    emit layoutAboutToBeChanged();
    parent->appendChild(item);
    emit this->layoutChanged();

}
void BasicModel::removeItem(QModelIndex item)
{
    if(item.isValid())
    {
        QModelIndex parent = item.parent();
        removeRows(item.row(), 1, parent);
    }
}
BasicModelItem* BasicModel::getItem(const QModelIndex &index) const
{
    if (index.isValid())
    {
        BasicModelItem *item = static_cast<BasicModelItem*>(index.internalPointer());
        return item;
    }
    return _root;
}
bool BasicModel::insertRows(int position, int rows, const QModelIndex &parent)
{
    BasicModelItem* parentItem = getItem(parent);
    beginInsertRows(parent, position, position+rows-1);
    for (int row = 0; row < rows; ++row)
    {
        parentItem->appendChild(new BasicModelItem());
    }
    endInsertRows();
    return true;
}
bool BasicModel::insertRows(int position, int rows, QList<QList<QVariant> >data, const QModelIndex &parent)
{
    BasicModelItem* parentItem = getItem(parent);
    beginInsertRows(parent, position, position+rows-1);
    for (int row = 0; row < rows; ++row)
    {
        parentItem->appendChild(createItem(QString("ImageItem"), data), position);
        position++;
    }
    endInsertRows();
    return true;
}
bool BasicModel::insertRows(int position, int rows, BasicModelItem* item, const QModelIndex &parent)
{
    BasicModelItem* parentItem = getItem(parent);
    beginInsertRows(parent, position, position+rows-1);
    for (int row = 0; row < rows; ++row)
    {
        BasicModelItem* newItem = createItem(item->getType(), item->getData());
        parentItem->appendChild(newItem, position);
        int count = item->childCount();
        for(int i = 0; i<count;i++)
        {
            BasicModelItem* child = item->child(i);
            newItem->appendChild(createItem(child->getType(), child->getData()), i);
        }
        position++;
    }
    endInsertRows();
    return true;
}
bool BasicModel::removeRows(int position, int rows, const QModelIndex &parent)
{
    bool success;
    BasicModelItem* parentItem = getItem(parent);

    beginRemoveRows(parent, position, position+rows-1);
    success = parentItem->removeChildren(position, rows);
    endRemoveRows();
//    emit this->layoutChanged();
    return success;
}
bool BasicModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
    if(index.isValid())
    {
        BasicModelItem* item = getItem(index);
        if(item->setData(index.column(), value, role))
        {
            QVector<int> roles;
            roles << role;
            emit this->dataChanged(index, index, roles);
            return true;
        }
    }
    return false;
}
bool BasicModel::setItemData(const QModelIndex &index, const QList<QList<QVariant> > &data)
{
    if(index.isValid())
    {
        BasicModelItem* item = getItem(index);
        if(item->setItemData(data))
        {
            emit this->dataChanged(index, index);
            return true;
        }
    }
    return false;
}
void BasicModel::empty()
{
    beginResetModel();
    int childCount = _root->childCount();
    if(childCount>0)
    {
        this->removeRows(0, childCount, QModelIndex());
    }
    endResetModel();
}
QStringList BasicModel::mimeTypes() const
{
    QStringList types;
    types << "QByteArray";
    return types;
}
bool BasicModel::canDropMimeData(const QMimeData *data, Qt::DropAction action, int row, int column, const QModelIndex &parent) const
{
    const DDMimeData *mimeData = qobject_cast<const  DDMimeData*>(data);
    const QList<QList<QList<QVariant> > > DDdata = mimeData->_data;
    BasicModelItem* parentItem = getItem(parent);
    return parentItem->canAcceptDrops();
}
QMimeData* BasicModel::mimeData(const QModelIndexList &indexes) const
{
    DDMimeData *mimeData = new DDMimeData();
    QList<QList<QList<QVariant> > > indexesData;
    QByteArray encodedData;

    foreach (QModelIndex index, indexes)
    {
        if (index.isValid())
        {
            BasicModelItem* item = getItem(index);
            indexesData << item->getData();
        }
    }
    mimeData->setIndexesData(indexesData);
    QModelIndexList newList;
    newList.append(indexes.first());
    mimeData->setIndexes(newList);

    mimeData->setData("QByteArray", encodedData);
    return mimeData;
}
DropPoint BasicModel::findParentForDrop(const QMimeData* data, Qt::DropAction action, int row, int column, QModelIndex parent)
{
    DropPoint point;
    if(canDropMimeData(data, action, row, column, parent))
    {
        point.parent = parent;
        point.row = row;
        point.column = column;
    }
    else
    {
        if(getItem(parent)->isRoot())
        {
            point.parent = QModelIndex();
            point.row = -1;
            point.column = -1;
        }
        else
        {
            point = findParentForDrop(data, action, parent.row(), parent.column(), parent.parent());
        }
    }
    return point;
}
QModelIndexList BasicModel::parseDropData(QModelIndexList indexes)
{
    return indexes;
}

bool BasicModel::dropMimeData(const QMimeData* data,
                              Qt::DropAction action, int row, int column, const QModelIndex &parent)
{
    const DDMimeData *mimeData = qobject_cast<const  DDMimeData*>(data);
    if(action == Qt::IgnoreAction)
    {
        return false;
    }
    if(!data->hasFormat("QByteArray"))
    {
        return false;
    }
    QModelIndexList indexData = mimeData->_indexes;
    QModelIndexList indexes = parseDropData(indexData);

    DropPoint point = findParentForDrop(data, action, row, column, parent);
//    const QList<QList<QList<QVariant> > > DDdata = mimeData->_data;
    int beginRow;
    if (point.row != -1)
    {
        beginRow = point.row;
    }
    else
    {
        beginRow = rowCount(point.parent);
    }
    foreach (QModelIndex index, indexes)
    {
        if(index.isValid())
        {
            BasicModelItem* item = getItem(index);
            insertRows(beginRow, 1, item, point.parent);
            beginRow++;
        }
    }
    return true;
}
Qt::DropActions BasicModel::supportedDropActions() const
{
 return Qt::CopyAction | Qt::MoveAction;
}
void BasicModel::AddBlankItem()
{

}
BasicModelItem* BasicModel::createItem(QString type, QList<QList<QVariant> > data)
{
    if(type == "ImageItem")
    {
        return new ImageItem(data);
    }
    return new BasicModelItem(data);
}
