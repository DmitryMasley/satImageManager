#ifndef IMAGETREENODE_H
#define IMAGETREENODE_H
#include "stdafx.h"
#include <QtWidgets/QTreeWidget>
class imageTreeNode : public QTreeWidgetItem
{
public:
    imageTreeNode();
    imageTreeNode(int type);
    imageTreeNode(QString file);
    imageTreeNode(int ch, QString file, QImage* img);
    int channel;
    QImage* image;
    QString fileName;
};

#endif // IMAGETREENODE_H
