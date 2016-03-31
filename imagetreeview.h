#ifndef IMAGETREEVIEW_H
#define IMAGETREEVIEW_H
#include <QtWidgets/QTreeView>
#include "imageitem.h"
#include "lib/image/standardimagemodel.h"
#include "lib/image/standardimageitem.h"

class ImageTreeView : public QTreeView
{
      Q_OBJECT

public:
    ImageTreeView(QWidget* container);
    StandardImageItem* GetSelectedItem();
    QModelIndexList getSelectedIndexes();
private slots:

signals:
    void selectionChanged(const QItemSelection &selected, const QItemSelection &deselected);
};

#endif // IMAGETREEVIEW_H
