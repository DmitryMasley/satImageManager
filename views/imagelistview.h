#ifndef IMAGELISTVIEW_H
#define IMAGELISTVIEW_H

#include <QObject>
#include <QtWidgets/QTreeView>
#include "lib/image/standardimageitem.h"

class ImageListView : public QTreeView
{
    Q_OBJECT
public:
    explicit ImageListView(QWidget *parent = 0);
    StandardImageItem* GetSelectedItem();
    QModelIndexList getSelectedIndexes();
    ~ImageListView();

signals:

public slots:
};

#endif // IMAGELISTVIEW_H
