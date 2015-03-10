#include "imageitem.h"

ImageItem::ImageItem(cv::Mat image, QString name, QString fileName, int channel, ImageItem *parent, bool isRoot) :
    BasicModelItem(parent, isRoot)
{
    this->initImageData(image, name, fileName, channel);

}
ImageItem::ImageItem(QString name, QString fileName, bool isColored, bool isRoot): BasicModelItem(0, isRoot)
{
    initImageData(name, fileName);
}
ImageItem::ImageItem(const QList<QList<QVariant> > &data, bool isRoot): BasicModelItem(0, isRoot)
{
    QStringList headers;
    headers << QString("Item Title");
    setHeaders(headers);
    setItemData(data);
    cv::Mat image = getCVImage();
    if(_tempimage!=0){
        delete _tempimage;
    }
    _tempimage = ProcessingCore::convertToQImage(image);
}
ImageItem::ImageItem(ImageItem &item):BasicModelItem(item)
{
    QStringList headers;
    headers << QString("Item Title");
    setHeaders(headers);
    setItemData(item.getData());
    cv::Mat image = getCVImage();
    delete _tempimage;
    _tempimage = ProcessingCore::convertToQImage(image);
}
void ImageItem::setClassName()
{
    this->setProperty("type", QString("ImageItem"));
}

ImageItem::~ImageItem()
{
    delete _tempimage;
}
cv::Mat ImageItem::getCVImage()
{
    cv::Mat image;
    QVariant imageValue = data(1, 0);
    if(imageValue.isValid())
    {
        image = data(1, 0).value<cv::Mat>();
    }
    return image;
}
void ImageItem::setCVImage(cv::Mat image)
{
    setData(1, QVariant::fromValue(image), 0);
    QImage* _qimage = ProcessingCore::convertToQImage(image);
    QPixmap pixmap = QPixmap::fromImage(*_qimage);
    QIcon ic = QIcon(pixmap.scaled(40, 40));
    setData(0, ic, 1);
    delete _tempimage;
    _tempimage = ProcessingCore::convertToQImage(image);
}
void ImageItem::clearImage()
{
    QIcon icon;
    icon.addFile(QStringLiteral(":/resource/icons/images/icons.png"), QSize(), QIcon::Normal, QIcon::Off);
    this->setData(0, QVariant(icon), 1);
    setData(1, QVariant(), 0);
    delete _tempimage;
    _tempimage = 0;
}
QImage* ImageItem::getQImage()
{
    return _tempimage;
}
bool ImageItem::canAcceptMoreChildren()
{
    bool result = false;
    if((canHaveChildren() && this->childCount()<4) || this->isRoot())
    {
        result = true;
    }
    return result;
}
void ImageItem::onChildrenChanged()
{
    int count = this->childCount();
    if(canHaveChildren() && !isRoot())
    {
        if(count == 4 || count == 3)
        {
            cv::Mat image;
            cv::Mat firstChannel = static_cast<ImageItem*>(child(0))->getCVImage();
            int rows = firstChannel.rows;
            int cols = firstChannel.cols;
            vector<cv::Mat> channels;
            for(int i = 0; i<count; i++)
            {
                cv::Mat channel;
                channel = static_cast<ImageItem*>(child(i))->getCVImage();               
                if(channel.cols != cols || channel.rows != rows)
                {
                    clearImage();
                    return;
                    //do not alocate other data
//                    cv::resize(channel, channel, Size(cols,rows));
                }
                channels.push_back(channel);
            }
            cv::merge(channels, image);
            setCVImage(image);
        }
        else
        {
            clearImage();
        }
    }
}
bool ImageItem::isValid()
{
    QVariant value = data(1, 0);
    cv::Mat image = value.value<cv::Mat>();
    return value.isValid() && image.rows && image.cols;
}
bool ImageItem::canHaveChildren()
{
    int channel = getChannel();
    return getChannel()==-1;
}
void ImageItem::_addCharacteristicsModel()
{
    qDeleteAll(Characteristics);
    ChList <<
              QString("Shannon Entropy") <<
              QString("Signal Entropy") <<
              QString("Gradation using coefficient") <<
              QString("Adaptation level of brightness") <<
              QString("Max dynamic contrast");

    for (int i=0;i<ChList.count(); i++)
    {
        QList<QList<QVariant> > data;
        QList<QVariant> value;
        value << QVariant();
        data << value;
        Characteristics.append(new CharacteristicsItem(data, QString(ChList.value(i))));
    }
}
bool ImageItem::isMultichannel()
{
    cv::Mat image = this->getCVImage();
    return this->childCount()>0 && image.channels() > 1;
}
QString ImageItem::getName()
{
    return this->data(0, Qt::DisplayRole).toString();
}

void ImageItem::initImageData(cv::Mat image, QString name, QString fileName, int channel)
{
    QIcon icon;
    if(image.rows && image.cols)
    {
        icon = ProcessingCore::convertToQIcon(image);
    }
    else
    {
        icon.addFile(QStringLiteral(":/resource/icons/images/icons.png"), QSize(), QIcon::Normal, QIcon::Off);
    }

    QList<QList<QVariant> > emptyData;
    this->setItemData(emptyData);

    //item title
    QList<QVariant> data;
    data << name << icon;
    this->addData(data);

    //image data
    QList<QVariant> imageData;
    imageData << QVariant(QVariant::fromValue(image));
    this->addData(imageData);
    _addCharacteristicsModel();

    //file data
    QList<QVariant> fileData;
    fileData << fileName;
    this->addData(fileData);

    //channels data
    QList<QVariant> channelsData;
    channelsData << channel;
    this->addData(channelsData);

    //headers
    QStringList headers;
    headers << QString("Item Title");
    setHeaders(headers);

    _tempimage = ProcessingCore::convertToQImage(image);
}
void ImageItem::initImageData(QString name, QString fileName)
{
    QIcon icon;
    cv::Mat image;
    icon.addFile(QStringLiteral(":/resource/icons/images/icons.png"), QSize(), QIcon::Normal, QIcon::Off);
    initImageData(image, name, fileName);
}
int ImageItem::getChannel()
{
    return this->data(3, 0).toInt();
}
ImageItem* ImageItem::findImage(QString fileName)
{
    ImageItem* result = 0;
    BasicModelItem* item = this->findItem(QVariant(fileName), 0, 0);
    if(item)
    {
        result = static_cast<ImageItem*>(item);
    }
    return result;
}
