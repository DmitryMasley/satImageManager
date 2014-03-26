#include "imagetree.h"
imagetree::imagetree():QTreeWidget()
{

}
imagetree::imagetree(QWidget *w):QTreeWidget(w)
{

}
void imagetree::addItemCustom()
{
    QString fileName = QFileDialog::getOpenFileName(0, QString("Open image"),  QString(""), QString("*.jpg;*.png;*.tif;*.tiff;*.jpeg"));
    if (fileName != "")
    {
        imageTreeNode* item = new imageTreeNode(fileName);
        this->addTopLevelItem(item);
        this->setCurrentItem(item);
    }
}
void imagetree::selectionChangedSlot()
{
    imageTreeNode* item =  (imageTreeNode*)this->selectedItems().at(0);
    Mat m = imread(ProcessingCore::convertToStdString(item->fileName), -1);
    if (item->channel>=0)
    {
        m = ProcessingCore::getChannel((Channels)item->channel, m);
    }
    QImage* image = ProcessingCore::convertToQImage(m);
    emit this->itemSelected(image);
}
