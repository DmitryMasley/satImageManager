#include "standardmodel.h"

StandardModel::StandardModel(QObject *parent) :
    QAbstractItemModel(parent)
{
    this->setRoot(new AbstractItem());
}
StandardModel::StandardModel(AbstractItem *rootObj, QObject *parent) :
    QAbstractItemModel(parent)
{
    this->setRoot(rootObj);
}
AbstractItem* StandardModel::root() const
{
    return _root;
}
void StandardModel::setRoot(AbstractItem *rootObj)
{
    delete _root;
    _root = rootObj;
    rootObj->setParent(this);
    emit rootChanged(rootObj);
}
AbstractItem* StandardModel::getItem(const QModelIndex &index) const
{
    if (index.isValid())
    {
        return static_cast<AbstractItem*>(index.internalPointer());
    }
    else
    {
        return this->root();
    }
}

QModelIndex StandardModel::index(int row, int column, const QModelIndex &parent) const
{
    if (!this->hasIndex(row, column, parent))
        return QModelIndex();
    AbstractItem *parentItem;
    AbstractItem *childItem;
    if (!parent.isValid())
    {
        parentItem = this->root();
    }
    else
    {
        parentItem = this->getItem(parent);
    }
    childItem = parentItem->child(row);
    if (childItem)
        return this->createIndex(row, column, childItem);
    else
        return QModelIndex();
}
QVariant StandardModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
        return QVariant();
    AbstractItem *item = getItem(index);
    return item->data(index.column(), role);
}
QVariant StandardModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    QVariant result;
    if (orientation == Qt::Horizontal)
    {
        result = _root->data(section, role);
    }
    else if(orientation == Qt::Vertical)
    {
        if(_root->children().count()>section)
        {
            QObject* child = _root->children().at(section);
            // if child inherits AbstractItem try to get header from it;
            if(child->inherits("AbstractItem")){
                AbstractItem* ch = static_cast<AbstractItem*>(child);
                QMap<int, QVariant> header = ch->header();
                if(header.contains(role))
                {
                    result = header.value(role, QVariant());
                }
            }
            else
            {
                // otherwise try to get QObject property
                result = child->property("header");
            }
        }
    }

    return result;
}
QModelIndex StandardModel::parent(const QModelIndex &index) const
{
    if (!index.isValid())
        return QModelIndex();

    AbstractItem* childItem = getItem(index);
    AbstractItem* parentItem = static_cast<AbstractItem*>(childItem->parent());

    if (parentItem == _root)
        return QModelIndex();

    return createIndex(parentItem->row(), 0, parentItem);
}
int StandardModel::rowCount(const QModelIndex &parent) const
{
    QObject* parentItem;
    if (parent.column() > 0)
        return 0;

    if (!parent.isValid())
        parentItem = _root;
    else
        parentItem = getItem(parent);
    return parentItem->children().count();
}
int StandardModel::columnCount(const QModelIndex &parent) const
{
    if (parent.isValid())
        return getItem(parent)->columnCount();
    else
        return _root->columnCount();
}
bool StandardModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
    if(index.isValid())
    {
        AbstractItem* item = getItem(index);
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
bool StandardModel::setItemData(const QModelIndex &index, const QList<QMap<int, QVariant> > &data)
{
    if(index.isValid())
    {
        AbstractItem* item = getItem(index);
        if(item->setItemData(data))
        {
            emit this->dataChanged(index, index);
            return true;
        }
    }
    return false;
}
bool StandardModel::insertRows(int position, int rows, const QModelIndex &parent){
    AbstractItem* parentItem = getItem(parent);
    beginInsertRows(parent, position, position+rows-1);
    for (int row = 0; row < rows; ++row)
    {
        AbstractItem* child = this->createItem();
        // uppend child to the end of the list using standard setParent
        if(child !=0){
            parentItem->appendChild(child);
            // insert new child in new position
            QObjectList children = parentItem->children();
            int index = children.indexOf(child);
            if(index!=-1) {
                QObject* child = children.takeAt(index);
                children.insert(position, child);
            }
        }
        else
        {
            delete child;
        }

    }
    endInsertRows();
    return true;
}
bool StandardModel::removeRows(int position, int rows, const QModelIndex &parent){
    bool success;
    AbstractItem* parentItem = getItem(parent);

    beginRemoveRows(parent, position, position+rows-1);
    success = parentItem->removeChildren(position, rows);
    endRemoveRows();
//    emit this->layoutChanged();
    return success;
}
QStringList StandardModel::mimeTypes() const{
    QStringList types;
    types << "QByteArray";
    types << this->getItemClassName();
    return types;
}
QMimeData* StandardModel::mimeData(const QModelIndexList &indexes) const
{
    StandardMimeData *mimeData = new StandardMimeData();
    QByteArray array;
    QModelIndexList newIndexList;
    foreach (QModelIndex index, indexes) {
        newIndexList << index;
    }
    mimeData->setText(getItemClassName());
    mimeData->setData(getItemClassName(), array);
    mimeData->setIndes(newIndexList);
    return mimeData;
}
QString StandardModel::getItemClassName() const {
    return _root->getType();
}
QModelIndexList StandardModel::parseDropData(QModelIndexList indexes){
    return indexes;
}
Qt::DropActions StandardModel::supportedDropActions() const
{
    return Qt::CopyAction | Qt::MoveAction;
}
bool StandardModel::canDropMimeData(const QMimeData *data, Qt::DropAction action, int row, int column, const QModelIndex &parent) const
{
    AbstractItem* parentItem = getItem(parent);
    return parentItem->canAcceptDrops(data->text());
}
InsertPoint StandardModel::findParentForDrop(const QMimeData* data, Qt::DropAction action, int row, int column, QModelIndex parent)
{
    InsertPoint point;
    if(canDropMimeData(data, action, row, column, parent))
    {
        point.parent = parent;
        point.row = row;
        point.column = column;
    }
    else
    {
        if(!parent.isValid())
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
bool StandardModel::dropMimeData(const QMimeData *data, Qt::DropAction action, int row, int column, const QModelIndex &parent)
{
    const StandardMimeData *mimeData = static_cast<const  StandardMimeData*>(data);
    if(action == Qt::IgnoreAction)
    {
        return false;
    }
    // accept only the same types, as items in model
    if(!data->hasFormat(getItemClassName()))
    {
        return false;
    }
    const QModelIndexList indexData = mimeData->getIndexes();
    QModelIndexList indexes = parseDropData(indexData);

    InsertPoint point = findParentForDrop(data, action, row, column, parent);
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
            AbstractItem* item = getItem(index);
            insertItem(beginRow, item, point.parent);
            beginRow++;
        }
    }
    return true;
}
void StandardModel::insertItem(int row, AbstractItem *itemToCopy, QModelIndex parent)
{
    // add empty item
   this->insertRows(row, 1, parent);
    // get this item index
    QModelIndex item;
    if(parent.isValid())
    {
        item = parent.child(row, 0);
    }
    else
    {
        item = index(row, 0, parent);
    }
   //set data to item
   getItem(item)->setItemData(itemToCopy->getData());
   // lets do this for childer recursively
   for(int i = 0; i < itemToCopy->childCount(); i++){
       AbstractItem* child = itemToCopy->child(i);
       this->insertItem(i, child, item);
   }

}
AbstractItem* StandardModel::createItem(){
    // make a new instance of the same type as root element
    QObject* newItem = _root->metaObject()->newInstance();
    if(newItem->inherits("AbstractItem"))
    {
        return qobject_cast<AbstractItem* >(newItem);
    }
    else
    {
        return new AbstractItem();
    }
}
void StandardModel::empty()
{
    beginResetModel();
    int childCount = _root->childCount();
    if(childCount>0)
    {
        this->removeRows(0, childCount, QModelIndex());
    }
    endResetModel();
}
void StandardModel::addItem(AbstractItem *item, AbstractItem *parent)
{
    if (parent==0)
    {
        parent = _root;
    }
    emit layoutAboutToBeChanged();
    parent->appendChild(item);
    emit this->layoutChanged();
}
Qt::ItemFlags StandardModel::flags(const QModelIndex &index) const
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
