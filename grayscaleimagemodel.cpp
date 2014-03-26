#include "grayscaleimagemodel.h"

GrayScaleImageModel::GrayScaleImageModel(const QList<QList<QVariant> > &data, QObject *parent) :
    ImageModel(data, parent)
{

}
QModelIndexList GrayScaleImageModel::parseDropData(QModelIndexList indexes)
{
    foreach (QModelIndex index, indexes)
    {
        ImageItem* item = static_cast<ImageItem* >(getItem(index));
        int count = item->childCount();
        if(count)
        {
            QModelIndexList newList;
            for(int i = 0; i<count; i++)
            {
                QModelIndex child = index.child(i, 0);
                newList.append(child);
            }
            return newList;
        }
    }
    return indexes;

}
