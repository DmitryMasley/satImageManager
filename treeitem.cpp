#include "treeitem.h"
#include "characteristicsitem.h"
using namespace std;
TreeItem::TreeItem(QString & filename, TreeItem *parent):BasicModelItem(parent)
{
//    if (parent)
//    {
//        _parent = parent;
//        _parent->appendChild(this);
//    }
//    else
//    {
//        _parent = 0;
//    }
    _headers << QString("Item Title")
             << QString("File Name")
             << QString("Channel");
    Mat m = imread(ProcessingCore::convertToStdString(filename), -1);
    Mat temp;
    m.copyTo(temp);
    int channelsCount = m.channels();
    QImage * image = ProcessingCore::convertToQImage(temp);
    QPixmap pixmap = QPixmap::fromImage(*image);
    QIcon ic = QIcon(pixmap.scaled(40, 40));
    QFileInfo pathInfo(filename);
    QString name(pathInfo.fileName());
    QList<QVariant> title;
    title << name << ic;
    QList<QVariant> file;
    file << filename;
    QList<QVariant> channel;
    int channelValue = channelsCount>1 ? -1 : -2;
    channel << channelValue;
    this->addData(title);
    this->addData(file);
    this->addData(channel);
    QHash<int, string> ChannelsStrings;
    ChannelsStrings[0] = "Blue";
    ChannelsStrings[1] = "Green";
    ChannelsStrings[2] = "Red";
    ChannelsStrings[3] = "Alpha";
    if (channelsCount>1)
    {
        for(int i=0; i<channelsCount;i++)
        {
            Mat ch = ProcessingCore::getChannel(Channels(i), m);
            QPixmap pix = QPixmap::fromImage(*(ProcessingCore::convertToQImage(ch)));
            QIcon icon = QIcon(pix.scaled(40, 40));
            QList<QVariant> title;
            title << QString("Channel ") + QString::fromStdString(ChannelsStrings[i]) + QString(" ") + name << icon;
            QList<QVariant> file;
            file << filename;
            QList<QVariant> channel;
            channel << i;

            QList<QList<QVariant> > data;
            data.append(title);
            data.append(file);
            data.append(channel);
            this->appendChild(new TreeItem(data));
        }
    }
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
TreeItem::TreeItem(const QList<QList<QVariant> > & data, TreeItem *parent, bool isRoot) : BasicModelItem(parent, isRoot)
{
//    if (parent)
//    {
//        _parent = parent;
//        _parent->appendChild(this);
//    }
//    else
//    {
//        _parent = 0;
//    }
    _headers << QString("Item Title")
             << QString("File Name")
             << QString("Channel");
    this->setItemData(data);
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
        data<<value;
        Characteristics.append(new CharacteristicsItem(data, ChList.value(i)));
    }
}
TreeItem::TreeItem(TreeItem *item):BasicModelItem()
{
    this->setChildren(item->getChildren());
    this->setItemData(item->getData());
    this->setParent(0);
}
TreeItem::~TreeItem()
{

}
int TreeItem::containsImage(QString fileName)
{
    int count = this->childCount();
    int index=-1;
    for(int i=0; i<count; i++)
    {
        if (fileName == this->child(i)->data(0, Qt::DisplayRole).toString())
        {
            index = i;
        }
    }
    return index;
}
cv::Mat TreeItem::getCVImage()
{
    Mat m;
    QString fileName = this->data(1, Qt::DisplayRole).toString();
    int channel = this->data(2, Qt::DisplayRole).toInt();
    QFile file(fileName);
    if (file.exists())
    {
        m = imread(ProcessingCore::convertToStdString(fileName), -1);
        if (channel>=0)
        {
            m = ProcessingCore::getChannel(Channels(channel), m);
        }
    }
    return m;
}
QList<QString> TreeItem::getHeaders()
{
    return _headers;
}
