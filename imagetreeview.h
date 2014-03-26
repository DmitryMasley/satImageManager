#ifndef IMAGETREEVIEW_H
#define IMAGETREEVIEW_H
#include <QtWidgets/QTreeView>
#include "imageitem.h"

class ImageTreeView : public QTreeView
{
      Q_OBJECT

public:
    ImageTreeView(QWidget* container);
    ImageItem* GetSelectedItem();
    QModelIndexList getSelectedIndexes();
private slots:

signals:
    void selectionChanged(const QItemSelection &selected, const QItemSelection &deselected);
};

#endif // IMAGETREEVIEW_H
