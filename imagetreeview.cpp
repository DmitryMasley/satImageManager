#include "imagetreeview.h"
#include "imagetreemodel.h"
ImageTreeView::ImageTreeView(QWidget* container):QTreeView(container)
{

}
QModelIndexList ImageTreeView::getSelectedIndexes()
{
    return this->selectedIndexes();
}
ImageItem* ImageTreeView::GetSelectedItem()
{
    ImageItem *item=0;
    if (this->selectedIndexes().count())
    {
        QModelIndex index = this->selectedIndexes()[0];
        item = static_cast<ImageItem*>(index.internalPointer());
    }
    return item;
}
