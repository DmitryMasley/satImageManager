#include "basiclistview.h"

BasicListView::BasicListView(QWidget *parent) :
    QListView(parent)
{
}
QModelIndexList BasicListView::getSelectedIndexes()
{
    return this->selectedIndexes();
}
