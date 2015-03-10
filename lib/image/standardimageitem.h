#ifndef STANDARDIMAGEITEM_H
#define STANDARDIMAGEITEM_H

#include <QObject>
#include "../abstractitem.h"
#include <opencv2/imgproc/imgproc.hpp> // Gaussian Blur
#include <opencv2/core/core.hpp> // Basic OpenCV structures (cv::Mat, Scalar)
#include <opencv2/highgui/highgui.hpp> // OpenCV window I/O
#include <opencv2/imgproc/imgproc_c.h>
#include <opencv2/core/mat.hpp>
using namespace cv;
class StandardImageItem : public AbstractItem
{
    Q_OBJECT
public:
    Q_INVOKABLE explicit StandardImageItem(QObject *parent = 0);
    Q_INVOKABLE explicit StandardImageItem(Mat image, QString name, QString fileName=QString(), bool isRoot = false, QObject *parent = 0);
    Q_INVOKABLE explicit StandardImageItem(QString name, QString fileName=QString(), bool isRoot = false, QObject *parent = 0);
    Q_INVOKABLE explicit StandardImageItem(const QList<QMap<int, QVariant> > &data, bool isRoot = false);
    Q_INVOKABLE explicit StandardImageItem(StandardImageItem& item);
    Q_PROPERTY(bool _isMultiChannel READ isMultichannel WRITE setIsMultichannel)

    ~StandardImageItem();
    Mat getCVImage();
    void setCVImage(Mat image);
    void clearImage();
    QImage* getQImage();
    QString getName();
    bool isValid();
    bool canHaveChildren();
    StandardImageItem* findImage(QString fileName);
    void initImageData(Mat image, QString name, QString fileName=QString());
    void initImageData(QString name, QString fileName=QString());
    int getChannel();
    bool isMultichannel();
    void setIsMultichannel(bool value);
    QStringList ChList;

signals:
protected:
    bool virtual canAcceptMoreChildren();
    void onChildrenChanged();

public slots:
private:
   QImage* _tempimage = 0;
   bool _isMultiChannel = false;
   void _addCharacteristicsModel();
};

#endif // STANDARDIMAGEITEM_H
