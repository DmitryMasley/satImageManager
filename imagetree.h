#ifndef IMAGETREE_H
#define IMAGETREE_H
#include <QTreeWidget>
#include <QFileDialog>
#include <opencv2/core.hpp>
#include "ProcessingCore.h"
#include "imagetreenode.h"
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
