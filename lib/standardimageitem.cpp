#include "standardimageitem.h"

StandardImageItem::StandardImageItem() :
    QStandardItem()
{
}
int StandardImageItem::type() const
{
    return 1001;
}
