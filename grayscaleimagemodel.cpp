#include "grayscaleimagemodel.h"

GrayScaleImageModel::GrayScaleImageModel(const QList<QMap<int, QVariant> > &data, QObject *parent) :
    StandardImageModel(data, parent)
{

}
QModelIndexList GrayScaleImageModel::parseDropData(QModelIndexList indexes)
{
    QModelIndexList newList;
    foreach (QModelIndex index, indexes)
    {
        StandardImageItem* item = static_cast<StandardImageItem* >(getItem(index));
        int count = item->childCount();
        if(count)
        {
            for(int i = 0; i<count; i++)
            {
                QModelIndex child = index.child(i, 0);
                newList.append(child);
            }
        } else {
            newList.append(index);
        }
    }
    return newList;

}
