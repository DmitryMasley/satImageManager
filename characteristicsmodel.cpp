#include "characteristicsmodel.h"

CharacteristicsModel::CharacteristicsModel():QAbstractItemModel()
{
    _root = new CharacteristicsItem();
    _root->appendChildren(_getDefaultItems());
    _currentItem = 0;
}
CharacteristicsModel::CharacteristicsModel(const QList<QList<QVariant> > &headers, QObject *parent):
    QAbstractItemModel(parent)
{

    _root = new CharacteristicsItem(headers);
    _root->appendChildren(_getDefaultItems());
    _currentItem = 0;
}
CharacteristicsModel::~CharacteristicsModel()
{
    delete _root;
}

QVariant CharacteristicsModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
        return QVariant();

    CharacteristicsItem *item = static_cast<CharacteristicsItem*>(index.internalPointer());

    return item->data(index.column(), role);
}
//Qt::ItemFlags CharacteristicsModel::flags(const QModelIndex &index) const
//{

//}
QVariant CharacteristicsModel::headerData(int section, Qt::Orientation orientation,
                    int role) const
{
    if (orientation == Qt::Vertical && role == Qt::DisplayRole)
    {
        return _root->child(section)->getHeader();
    }
    else if (orientation == Qt::Horizontal && role == Qt::DisplayRole)
    {
        return _root->data(section, role);
    }

    return QVariant();
}
QModelIndex CharacteristicsModel::index(int row, int column,
                  const QModelIndex &parent) const
{
    if (!hasIndex(row, column, parent))
        return QModelIndex();

    CharacteristicsItem *parentItem;

    if (!parent.isValid())
        parentItem = _root;
    else
        parentItem = static_cast<CharacteristicsItem*>(parent.internalPointer());

    CharacteristicsItem *childItem = parentItem->child(row);
    if (childItem)
        return createIndex(row, column, childItem);
    else
        return QModelIndex();
}
QModelIndex CharacteristicsModel::parent(const QModelIndex &index) const
{
   return QModelIndex();
}
int CharacteristicsModel::rowCount(const QModelIndex &parent) const
{
    return _root->childCount();
}
int CharacteristicsModel::columnCount(const QModelIndex &parent) const
{
    return _root->columnCount();
}
void CharacteristicsModel::appendItem(CharacteristicsItem* item)
{
    _root->appendChild(item);
    emit this->layoutChanged();
}
void CharacteristicsModel::appendItems(QList<CharacteristicsItem*> items)
{
    _root->appendChildren(items);
    emit this->layoutChanged();
}
void CharacteristicsModel::clear()
{
    _root->clearChildren();
}
void CharacteristicsModel::setCurrentItem(ImageItem* item)
{
    _currentItem = item;
}

ImageItem* CharacteristicsModel::getCurrentItem()
{
    return _currentItem;
}
void CharacteristicsModel::setCharacteristic(int row, QVariant data)
{
    _root->child(row)->setData(data);
    emit layoutChanged();
}
QList<CharacteristicsItem*> CharacteristicsModel::_getDefaultItems()
{
    QList<CharacteristicsItem*> Characteristics;
    QStringList ChList;
    ChList <<
//              QString("Shannon Entropy") <<
//              QString("Signal Entropy") <<
//              QString("Gradation using coefficient") <<
//              QString("Adaptation level of brightness") <<
//              QString("Max dynamic contrast");
                QString("Shannon Entropy") <<
                QString("Signal Entropy") <<
                QString("GUC") <<
                QString("ALB") <<
                QString("MDC");
    for (int i=0;i<ChList.count(); i++)
    {
        QList<QList<QVariant> > data;
        QList<QVariant> value;
        value << QVariant();
        data << value;
        Characteristics.append(new CharacteristicsItem(data, QString(ChList.value(i))));
    }
    return Characteristics;
}
void CharacteristicsModel::resetModel()
{
    this->clear();
    _root->appendChildren(_getDefaultItems());
    _currentItem = 0;
}
