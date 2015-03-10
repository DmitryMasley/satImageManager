#ifndef IMAGEITEM_H
#define IMAGEITEM_H
#include "stdafx.h"
#include <opencv2/core.hpp>
#include <opencv2/core/mat.hpp>
#include <opencv2/core/cuda.hpp>
#include "basicmodelitem.h"
#include "ProcessingCore.h"
#include <QString>

#include <QObject>
#include "metatypes.h"
#include "characteristicsitem.h"

class ImageItem : public BasicModelItem
{
    Q_OBJECT
public:
    explicit ImageItem(cv::Mat image, QString name, QString fileName=QString(), int channel = -1, ImageItem *parent = 0, bool isRoot = false);
    explicit ImageItem(QString name, QString fileName=QString(), bool isColored = true, bool isRoot = false);
    explicit ImageItem(const QList<QList<QVariant> > &data, bool isRoot = false);
    explicit ImageItem(ImageItem& item);
    virtual void setClassName();
    ~ImageItem();
    cv::Mat getCVImage();
    void setCVImage(cv::Mat image);
    void clearImage();
    QImage* getQImage();
    QString getName();
    bool isValid();
    bool canHaveChildren();
    bool isMultichannel();
    ImageItem* findImage(QString fileName);
    void initImageData(cv::Mat image, QString name, QString fileName=QString(), int channel=-1);
    void initImageData(QString name, QString fileName=QString());
    int getChannel();
    QList<CharacteristicsItem*> Characteristics;
    QStringList ChList;

signals:
protected:
    bool virtual canAcceptMoreChildren();
    void onChildrenChanged();
    
public slots:
private:
   QImage* _tempimage=0;
   bool _isColored;
   bool _isRoot;
   void _addCharacteristicsModel();
};

#endif // IMAGEITEM_H
