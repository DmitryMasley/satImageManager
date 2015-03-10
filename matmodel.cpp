#include "matmodel.h"

MatModel::MatModel(cv::Mat matrix, int type, QObject *parent) :
    QAbstractItemModel(parent)
{
    _item = new MatModelItem();
    _item->value = matrix;
    _matrix = matrix;
    _type = CV_32F;
    _item->value.convertTo(_item->value, _type);
}
MatModel::~MatModel()
{
    delete _item;
}

QModelIndex MatModel::index(int row, int column, const QModelIndex &parent) const
{
    if (!hasIndex(row, column, parent))
    {
        return QModelIndex();
    }
    return createIndex(row, column, _item);
}
QModelIndex MatModel::parent(const QModelIndex &index) const
{
        return QModelIndex();
}
int MatModel::rowCount(const QModelIndex &parent) const
{
    return _matrix.rows;
}
int MatModel::columnCount(const QModelIndex &parent) const
{
    return _matrix.cols;
}
QVariant MatModel::data(const QModelIndex &index, int role) const
{
    QVariant result = QVariant();
    if (!index.isValid())
        return result;
    MatModelItem* item = static_cast<MatModelItem*>(index.internalPointer());
    if(role == Qt::DisplayRole)
    {
        result = QVariant(item->value.at<float>(index.row(), index.column()));
    }
    return result;
}
Qt::ItemFlags MatModel::flags(const QModelIndex &index) const
{
    if (!index.isValid())
        return 0;

    return Qt::ItemIsEnabled | Qt::ItemIsSelectable;
}
QVariant MatModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if (role == Qt::DisplayRole)
    {
        return QVariant(section);
    }
    return QVariant();
}

