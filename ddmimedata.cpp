#include "ddmimedata.h"

DDMimeData::DDMimeData() :
    QMimeData()
{

}
DDMimeData::DDMimeData(QList<QList<QList<QVariant> > > data):
    QMimeData()
{
    _data = data;
}

const QList<QList<QList<QVariant> > > DDMimeData::getIndexesData()
{
    QList<QList<QList<QVariant> > > data = _data;
    return data;
}
void DDMimeData::setIndexesData(QList<QList<QList<QVariant> > > data)
{
    _data = data;
}
void DDMimeData::setIndexes(QModelIndexList indexes)
{
    _indexes = indexes;
}
QModelIndexList DDMimeData::getIndexes()
{
    return _indexes;
}
