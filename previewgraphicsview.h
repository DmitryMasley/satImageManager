#ifndef PREVIEWGRAPHICSVIEW_H
#define PREVIEWGRAPHICSVIEW_H
#include "stdafx.h"
#include <QGraphicsView>
#include "metatypes.h"
#include <QGraphicsPixmapItem>
#include "ddmimedata.h"
#include <QDropEvent>
#include <QDragMoveEvent>
#include <QWheelEvent>
#include "lib/image/standardimageitem.h"
#include "lib/standardmimedata.h"
class previewGraphicsView : public QGraphicsView
{
    Q_OBJECT

public:
    previewGraphicsView(bool gray = false, QWidget* w = 0);
    ~previewGraphicsView();
    bool _gray=false;
    void showImage(QImage* img);
    void resizeEvent(QResizeEvent *event);
    void dragMoveEvent(QDragMoveEvent *event);
    void dropEvent(QDropEvent *event);
    void wheelEvent(QWheelEvent *event);
    StandardImageItem* image;
    void fitImage();
    void setImageItem(StandardImageItem* item);
    void copyImageItem(StandardImageItem* item);
private slots:
    void showPreview(QImage* img);
    void fitIntoView();
private:
    qreal h11 = 1.0;
    qreal h12 = 0;
    qreal h21 = 0;
    qreal h22 = 1.0;
    qreal minFactor = 0.001;
    qreal maxFactor = 10.0;
    double scaleFactor = 1.25;
    QImage* currentImage = 0;
signals:
    void imageChanged(StandardImageItem* item);
};

#endif // PREVIEWGRAPHICSVIEW_H
