#include "imagetreenode.h"

imageTreeNode::imageTreeNode():QTreeWidgetItem()
{
}
imageTreeNode::imageTreeNode(int type):QTreeWidgetItem(type)
{

}
imageTreeNode::imageTreeNode(int ch, QString file, QImage* img):QTreeWidgetItem(1)
{
    channel = ch;
    fileName = file;
    this->setText(1,  "Channel "+QString::number(ch));
    QPixmap pixmap = QPixmap::fromImage(*img);
    QIcon ic = QIcon(pixmap.scaled(40, 40));
    this->setIcon(0, ic);
}

imageTreeNode::imageTreeNode(QString file):QTreeWidgetItem(1)
{
    channel = -1;
    fileName = file;
    Mat m = imread(ProcessingCore::convertToStdString(fileName), -1);
        this->setText(1, fileName);
        image = ProcessingCore::convertToQImage(m);
        QPixmap pixmap = QPixmap::fromImage(*image);
        QIcon ic = QIcon(pixmap.scaled(40, 40));
        this->setIcon(0, ic);

        int channelsCount = m.channels();
        if (channelsCount>1)
        {
            std::vector<QImage*> channels = ProcessingCore::splitToQImage(m);
            for(int i=0; i<channelsCount;i++)
            {
                this->addChild(new imageTreeNode(i, fileName, channels[i]));
            }
        }


}
