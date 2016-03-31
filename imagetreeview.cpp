#include "imagetreeview.h"
#include "imagetreemodel.h"
ImageTreeView::ImageTreeView(QWidget* container):QTreeView(container)
{

}
QModelIndexList ImageTreeView::getSelectedIndexes()
{
    return this->selectedIndexes();
}
StandardImageItem *ImageTreeView::GetSelectedItem()
{
    StandardImageItem *item=0;
    if (this->selectedIndexes().count())
    {
        QModelIndex index = this->selectedIndexes()[0];
        item = static_cast<StandardImageItem*>(index.internalPointer());
    }
    return item;
}
