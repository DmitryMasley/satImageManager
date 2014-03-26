#include "imagetreemodel.h"

ImageTreeModel::ImageTreeModel(const QList<QList<QVariant> > &data, QObject *parent)
    : BasicModel(parent)
{
    TreeItem* root = new TreeItem(data,0, true);
    this->setRootNode(root);
}
ImageTreeModel::~ImageTreeModel()
{
}
void ImageTreeModel::AddImage(QString fileName)
{
    if (static_cast<TreeItem*>(this->getRootNode())->containsImage(fileName) == -1)
    {
        TreeItem* newitem = new TreeItem(fileName);
        this->AddItem(newitem);
    }
}
void ImageTreeModel::AddBlankItem()
{
    this->AddItem(new ImageItem(QString("Blank Item")));
}
