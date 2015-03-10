#ifndef IMAGETREEMODEL_H
#define IMAGETREEMODEL_H
#include "treeitem.h"
#include "basicmodel.h"
#include "imageitem.h"

class ImageTreeModel:public BasicModel
{
    Q_OBJECT

public:
    ImageTreeModel(const QList<QList<QVariant> > &data, QObject *parent = 0);
    ~ImageTreeModel();
    void AddImage(QString fileName);
    void AddBlankItem();
private:
};

#endif // IMAGETREEMODEL_H
