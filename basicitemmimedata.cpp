#include "basicitemmimedata.h"

BasicItemMimeData::BasicItemMimeData(QList<QList<QVariant> > _data, QString _type, QList<BasicItemMimeData* > _children, QObject *parent) :
    QObject(parent)
{
    data = _data;
    type = _type;
    children = _children;
}
