    #include "imagemodel.h"

ImageModel::ImageModel(const QList<QList<QVariant> > &data, QObject *parent) :
    BasicModel(parent)
{
    setRootNode(new ImageItem(data, true));
}
void ImageModel::AddBlankItem()
{
    this->AddItem(new ImageItem(QString("Blank Image")));
}
void ImageModel::AddMultichannelImage(const cv::Mat image,const QString fileName)
{
    QFileInfo fileInfo(fileName);
    QString name = fileInfo.fileName();
    ImageItem* multichannelImage = new ImageItem(image, name, fileName);
    int channelsCount = image.channels();
    if(channelsCount>1)
    {
        QHash<int, QString> ChannelsStrings;
        ChannelsStrings[0] = QString("Blue");
        ChannelsStrings[1] = QString("Green");
        ChannelsStrings[2] = QString("Red");
        ChannelsStrings[3] = QString("Alpha");
        vector<cv::Mat> imageChannels;
        cv::split(image, imageChannels);
        for(int i = 0; i<channelsCount; i++)
        {
            ImageItem* child = new ImageItem(imageChannels[i], name+QString(" ")+ChannelsStrings[i], fileName, i);
            multichannelImage->appendChild(child);
        }
    }
    this->AddItem(multichannelImage);
}
void ImageModel::AddImage(const cv::Mat image, const QString fileName)
{
    QFileInfo fileInfo(fileName);
    QString name = fileInfo.fileName();
    // find image if already in list and remove before append new one;
    ImageItem* child = this->findImage(fileName);
    if(child)
    {
        child->remove();
    }
    int channelsCount = image.channels();
    if(channelsCount>1)
    {
        ImageItem* multichannelImage = new ImageItem(name, fileName);
        vector<cv::Mat> imageChannels;
        cv::split(image, imageChannels);
        QHash<int, QString> ChannelsStrings;
        ChannelsStrings[0] = QString("Red");
        ChannelsStrings[1] = QString("Green");
        ChannelsStrings[2] = QString("Blue");
        ChannelsStrings[3] = QString("Alpha");
        for(int i = 0; i<channelsCount; i++)
        {
            ImageItem* child = new ImageItem(imageChannels[i], name+QString(" ")+ChannelsStrings[i], fileName, i);
            multichannelImage->appendChild(child);
        }
        this->AddItem(multichannelImage);
    }
    else
    {
       ImageItem* item = new ImageItem(image, name, fileName, 0);
       this->AddItem(item);
    }
}
ImageItem* ImageModel::findImage(QString fileName)
{
    ImageItem* root = static_cast<ImageItem*>(_root);
    return root->findImage(fileName);
}
