#include "basictreeview.h"

BasicTreeView::BasicTreeView(QWidget *parent) :
    QTreeView(parent)
{
}
QModelIndexList BasicTreeView::getSelectedIndexes()
{
    return this->selectedIndexes();
}
