#ifndef IMAGETREE_H
#define IMAGETREE_H
#include <QTreeWidget>
#include "imagetreenode.h"
using namespace cv;
class imagetree : public QTreeWidget
{
    Q_OBJECT

public:
    imagetree();
    imagetree(QWidget* w);
private:
    imageTreeNode* createTreeImageItem(QString fileName);
signals:
    void itemSelected(QImage* img);
private slots:
    void addItemCustom();
    void selectionChangedSlot();
};

#endif // IMAGETREE_H
