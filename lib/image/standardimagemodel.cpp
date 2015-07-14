#include "standardimagemodel.h"

StandardImageModel::StandardImageModel(QObject *parent) :
    StandardModel(parent)
{
    StandardImageItem* root = new StandardImageItem();
    root->setRoot(true);
    setRoot(root);
}
#include "imagemodel.h"

StandardImageModel::StandardImageModel(const QList<QMap<int, QVariant> > &data, QObject *parent) :
StandardModel(parent)
{
    StandardImageItem* root = new StandardImageItem(data);
    root->setRoot(true);
    setRoot(root);
}
void StandardImageModel::AddBlankItem()
{
    this->addItem(new StandardImageItem(QString("Blank Image")));
}
void StandardImageModel::AddImage(const cv::Mat image, const QString fileName)
{
    emit layoutAboutToBeChanged();
    QFileInfo fileInfo(fileName);
    QString name = fileInfo.fileName();
    // find image if already in list and remove before append new one;
    StandardImageItem* child = this->findImage(fileName);
    if(child)
    {
        child->remove();
    }
    int channelsCount = image.channels();
    if(channelsCount>1)
    {
        StandardImageItem* multichannelImage = new StandardImageItem(name, fileName);
        vector<cv::Mat> imageChannels;
        cv::split(image, imageChannels);
        QHash<int, QString> ChannelsStrings;
        ChannelsStrings[0] = QString("Red");
        ChannelsStrings[1] = QString("Green");
        ChannelsStrings[2] = QString("Blue");
        ChannelsStrings[3] = QString("Alpha");
        for(int i = 0; i<channelsCount; i++)
        {
            StandardImageItem* child = new StandardImageItem(imageChannels[i], name+QString(" ")+ChannelsStrings[i], fileName, i);
            multichannelImage->appendChild(child);
        }
        this->root()->appendChild(multichannelImage);
    }
    else
    {
       StandardImageItem* item = new StandardImageItem(image, name, fileName, 0);
       this->addItem(item);
    }
    emit layoutChanged();
}
StandardImageItem* StandardImageModel::findImage(QString fileName)
{
    StandardImageItem* root = static_cast<StandardImageItem*>(this->root());
    return root->findImage(fileName);
}
