#include "previewgraphicsview.h"

previewGraphicsView::previewGraphicsView(bool gray, QWidget* w):QGraphicsView(w)
{
    image = 0;
    _gray = gray;
    QGraphicsScene* scene = new QGraphicsScene();
    this->setScene(scene);
}
previewGraphicsView::~previewGraphicsView()
{
    delete image;
    delete this->scene();
}
void previewGraphicsView::fitIntoView()
{
    fitImage();
}
void previewGraphicsView::setImageItem(ImageItem *item)
{
    image = item;
    showPreview(image->getQImage());
}
void previewGraphicsView::copyImageItem(ImageItem *item)
{
    delete image;
    image = new ImageItem(item->getData());
    showPreview(image->getQImage());
}
void previewGraphicsView::showPreview(QImage* img)
{
    currentImage = img;
    QList<QGraphicsItem*> items =  this->scene()->items(); int count = items.count();
    for (int i=0; i<count; i++)
    {
        delete items[i];
    }
    QPixmap pixmap = QPixmap::fromImage(*img);
    QGraphicsPixmapItem* imgitem = new QGraphicsPixmapItem(pixmap);
    this->scene()->addItem(imgitem);
    this->scene()->setSceneRect(0, 0, pixmap.width(), pixmap.height());
    fitImage();
}

void previewGraphicsView::showImage(QImage *img)
{
    this->showPreview(img);
}
void previewGraphicsView::fitImage()
{
    if(currentImage)
    {
        double imageHeight = currentImage->height()*1.1;
        double imageWidth = currentImage->width()*1.1;
        double sceneHeight = this->viewport()->height();
        double sceneWidth = this->viewport()->width();
        if(imageWidth && imageHeight)
        {
            double xRatio = sceneWidth/imageWidth;
            double yRatio = sceneHeight/imageHeight;
            h11 = h22 = std::min(xRatio, yRatio);
            this->setTransformationAnchor(QGraphicsView::AnchorUnderMouse);
            this->setTransform(QTransform(h11, h12, h21, h22, 0, 0));
        }
    }
}

void previewGraphicsView::resizeEvent(QResizeEvent *event)
{
    QGraphicsView::resizeEvent(event);
}
void previewGraphicsView::dragMoveEvent(QDragMoveEvent *event)
{
    const DDMimeData *mimeData = qobject_cast<const DDMimeData*>(event->mimeData());
    if(mimeData && mimeData->_indexes.count())
    {
        event->accept();
    }
}
void previewGraphicsView::dropEvent(QDropEvent *event)
{
    const DDMimeData *mimeData = qobject_cast<const DDMimeData*>(event->mimeData());
    if(mimeData && mimeData->_data.count())
    {
        QList<QList<QVariant> > data  = mimeData->_data.first();
        if(this->_gray)
        {
            // check if we have colored image. If so, prevent to add it to the view.
            cv::Mat image = data.at(1).at(0).value<cv::Mat>();
            if(image.channels()>1)
            {
                return;
            }
        }
        delete image;
        image = new ImageItem(data);
        showPreview(image->getQImage());
        emit this->imageChanged(image);
    }
}

void previewGraphicsView::wheelEvent(QWheelEvent *event)
{
    const int degrees = event->delta();
    int steps  = degrees;
    if(steps>0)
    {
        h11 = (h11 >= maxFactor) ? h11 : (h11*scaleFactor);
        h22 = (h22 >= maxFactor) ? h22 : (h22*scaleFactor);
    }
    else
    {
        h11 = (h11 <= minFactor) ? minFactor : (h11/scaleFactor);
        h22 = (h22 <= minFactor) ? minFactor : (h22/scaleFactor);
    }
    this->setTransformationAnchor(QGraphicsView::AnchorUnderMouse);
    this->setTransform(QTransform(h11, h12, h21, h22, 0, 0));
}
