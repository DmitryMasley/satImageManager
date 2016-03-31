#include "imagelistview.h"

ImageListView::ImageListView(QWidget *parent) : QTreeView(parent)
{

}

ImageListView::~ImageListView()
{

}

StandardImageItem* ImageListView::GetSelectedItem(){
    StandardImageItem *item=0;
    if (this->selectedIndexes().count())
    {
        QModelIndex index = this->selectedIndexes()[0];
        item = static_cast<StandardImageItem*>(index.internalPointer());
    }
    return item;
}
QModelIndexList ImageListView::getSelectedIndexes(){
        return this->selectedIndexes();
}
