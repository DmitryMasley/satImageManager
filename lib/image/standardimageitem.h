#ifndef STANDARDIMAGEITEM_H
#define STANDARDIMAGEITEM_H

#include <QObject>
#include "../abstractitem.h"
#include <opencv2/imgproc/imgproc.hpp> // Gaussian Blur
#include <opencv2/core/core.hpp> // Basic OpenCV structures (cv::Mat, Scalar)
#include <opencv2/highgui/highgui.hpp> // OpenCV window I/O
#include <opencv2/imgproc/imgproc_c.h>
#include <opencv2/gpu/gpu.hpp>
using namespace cv;
class StandardImageItem : public AbstractItem
{
    Q_OBJECT
public:
    Q_INVOKABLE explicit StandardImageItem(QObject *parent = 0);
    Q_INVOKABLE explicit StandardImageItem(Mat image, QString name, QString fileName=QString(), int channel = -1, QObject *parent = 0, bool isRoot = false);
    Q_INVOKABLE explicit StandardImageItem(QString name, QString fileName=QString(), bool isColored = true, bool isRoot = false);
    Q_INVOKABLE explicit StandardImageItem(const QList<QMap<int, QVariant> > &data, bool isRoot = false);
    Q_INVOKABLE explicit StandardImageItem(StandardImageItem& item);
    ~StandardImageItem();
    Mat getCVImage();
    void setCVImage(Mat image);
    void clearImage();
    QImage* getQImage();
    QString getName();
    bool isValid();
    bool canHaveChildren();
    bool isMultichannel();
    StandardImageItem* findImage(QString fileName);
    void initImageData(Mat image, QString name, QString fileName=QString(), int channel=-1);
    void initImageData(QString name, QString fileName=QString());
    int getChannel();
    QStringList ChList;

signals:
protected:
    bool virtual canAcceptMoreChildren();
    void onChildrenChanged();

public slots:
private:
   QImage* _tempimage = 0;
   bool _isColored;
   bool _isRoot;
   void _addCharacteristicsModel();
};

#endif // STANDARDIMAGEITEM_H
