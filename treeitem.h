#ifndef TREEITEM_H
#define TREEITEM_H
#include "basicmodelitem.h"
#include "characteristicsitem.h"
#include <opencv2/core.hpp>
#include <QStringList>
#include "ProcessingCore.h"
#include <QVariant>
#include <QPixmap>
#include <QIcon>
#include <QFileInfo>
#include <QFile>
class TreeItem : public BasicModelItem
{
public:
    TreeItem(QString & filename, TreeItem *parent = 0);
    TreeItem(const QList<QList<QVariant> > & data, TreeItem *parent = 0, bool isRoot = false);
    TreeItem(TreeItem *item);
    ~TreeItem();

//    void appendChild(TreeItem *child);
//    void setParent(TreeItem *parent);
//    TreeItem *child(int row);
//    int childCount() const;
//    int columnCount() const;
//    QVariant data(int column, int role) const;
//    int row() const;
//    TreeItem *parent();
//    void remove();
    QList<CharacteristicsItem*> Characteristics;
    int containsImage(QString fileName);
    cv::Mat getCVImage();
    QList<QString> getHeaders();
    QStringList ChList;
private:
//    QList<TreeItem*> childItems;
    /*QList<QVariant> itemData;*/
//    QList<QList<QVariant> > itemData;
//    TreeItem *parentItem;
    QList<QString> _headers;
};
#endif // TREEITEM_H
