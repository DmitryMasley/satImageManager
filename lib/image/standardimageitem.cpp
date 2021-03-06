#include "standardimageitem.h"
#include "imageitem.h"
StandardImageItem::StandardImageItem(QObject *parent) :
    AbstractItem(parent)
{
}

StandardImageItem::StandardImageItem(Mat image, QString name, QString fileName, bool isRoot, QObject *parent) :
    AbstractItem(parent)
{
    setRoot(isRoot);
    this->initImageData(image, name, fileName);

}
StandardImageItem::StandardImageItem(QString name, QString fileName, bool isRoot, QObject *parent) :
    AbstractItem(parent)
{
    setRoot(isRoot);
    initImageData(name, fileName);
}
StandardImageItem::StandardImageItem(const QList<QMap<int, QVariant> > &data, bool isRoot) :
    AbstractItem()
{
    setRoot(isRoot);
    QStringList headers;
    headers << QString("Item Title");
    setHeaders(headers);
    setItemData(data);
    Mat image = getCVImage();
    delete _tempimage;
    _tempimage = ProcessingCore::convertToQImage(image);
}
StandardImageItem::StandardImageItem(StandardImageItem &item):AbstractItem(item)
{
    QStringList headers;
    headers << QString("Item Title");
    setHeaders(headers);
    setItemData(item.getData());
    Mat image = getCVImage();
    delete _tempimage;
    _tempimage = ProcessingCore::convertToQImage(image);
}

StandardImageItem::~StandardImageItem()
{
    delete _tempimage;
}
bool StandardImageItem::isMultichannel(){
    return _isMultiChannel;
}
void StandardImageItem::setIsMultichannel(bool value){
    _isMultiChannel = value;
}
Mat StandardImageItem::getCVImage()
{
    Mat image;
    QVariant imageValue = data(1, 0);
    if(imageValue.isValid())
    {
        image = data(1, 0).value<Mat>();
    }
    return image;
}
void StandardImageItem::setCVImage(Mat image)
{
    setData(1, QVariant::fromValue(image), 0);
    QImage* _qimage = ProcessingCore::convertToQImage(image);
    QPixmap pixmap = QPixmap::fromImage(*_qimage);
    QIcon ic = QIcon(pixmap.scaled(40, 40));
    setData(0, ic, 1);
    delete _tempimage;
    _tempimage = ProcessingCore::convertToQImage(image);
}
void StandardImageItem::clearImage()
{
    QIcon icon;
    icon.addFile(QStringLiteral(":/resource/icons/images/icons.png"), QSize(), QIcon::Normal, QIcon::Off);
    this->setData(0, QVariant(icon), 1);
    setData(1, QVariant(), 0);
    delete _tempimage;
    _tempimage = 0;
}
QImage* StandardImageItem::getQImage()
{
    return _tempimage;
}
bool StandardImageItem::canAcceptMoreChildren()
{
    bool result = false;
    if((canHaveChildren() && this->childCount()<4) || this->root())
    {
        result = true;
    }
    return result;
}
void StandardImageItem::onChildrenChanged()
{
    int count = this->childCount();
    if(canHaveChildren() && !root())
    {
        if(count == 4 || count == 3)
        {
            Mat image;
            Mat firstChannel = static_cast<StandardImageItem*>(child(0))->getCVImage();
            int rows = firstChannel.rows;
            int cols = firstChannel.cols;
            vector<Mat> channels;
            for(int i = 0; i<count; i++)
            {
                Mat channel;
                channel = static_cast<StandardImageItem*>(child(i))->getCVImage();
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
bool StandardImageItem::isValid()
{
    QVariant value = data(1, 0);
    Mat image = value.value<Mat>();
    return value.isValid() && image.rows && image.cols;
}
bool StandardImageItem::canHaveChildren()
{
    return isMultichannel() || root();
}
void StandardImageItem::_addCharacteristicsModel()
{
//    qDeleteAll(Characteristics);
    ChList <<
              QString("Shannon Entropy") <<
              QString("Signal Entropy") <<
              QString("GStandardImageItemradation using coefficient") <<
              QString("Adaptation level of brightness") <<
              QString("Max dynamic contrast");

    for (int i=0;i<ChList.count(); i++)
    {
        QList<QList<QVariant> > data;
        QList<QVariant> value;
        value << QVariant();
        data << value;
//        Characteristics.append(new CharacteristicsItem(data, QString(ChList.value(i))));
    }
}
QString StandardImageItem::getName()
{
    return this->data(0, Qt::DisplayRole).toString();
}
QString StandardImageItem::getFileName(){
     return this->data(2, Qt::DisplayRole).toString();
}

void StandardImageItem::initImageData(Mat image, QString name, QString fileName)
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

    QList<QMap<int, QVariant> > emptyData;
    this->setItemData(emptyData);

    //item title
    QMap<int, QVariant> data;
    data.insert(Qt::DisplayRole, name);
    data.insert(Qt::DecorationRole, icon);
    this->addData(data);

    //image data
    QMap<int, QVariant> imageData;
    imageData.insert(Qt::DisplayRole, QVariant(QVariant::fromValue(image)));
    this->addData(imageData);
    _addCharacteristicsModel();

    //file data
    QMap<int, QVariant> fileData;
    fileData.insert(Qt::DisplayRole, fileName);
    this->addData(fileData);

    //headers
    QStringList headers;
    headers << QString("Item Title");
    setHeaders(headers);

    _tempimage = ProcessingCore::convertToQImage(image);
}
void StandardImageItem::initImageData(QString name, QString fileName)
{
    QIcon icon;
    Mat image;
    icon.addFile(QStringLiteral(":/resource/icons/images/icons.png"), QSize(), QIcon::Normal, QIcon::Off);
    initImageData(image, name, fileName);
}
int StandardImageItem::getChannel()
{
    return this->data(3, 0).toInt();
}
StandardImageItem* StandardImageItem::findImage(QString fileName)
{
    StandardImageItem* result = 0;
    AbstractItem* item = this->findItem(QVariant(fileName), 2, 0);
    if(item)
    {
        result = static_cast<StandardImageItem*>(item);
    }
    return result;
}
