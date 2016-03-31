#ifndef WORKSPACE_H
#define WORKSPACE_H

#include <QDialog>
#include "lib/image/standardimagemodel.h"
#include <QFileDialog>
#include "../ProcessingCore.h"

namespace Ui {
class Workspace;
}

class Workspace : public QDialog
{
    Q_OBJECT

public:
    explicit Workspace(QWidget *parent = 0);
    ~Workspace();
    StandardImageModel* imageListModel;
public slots:
    void AddImage();
private:
    Ui::Workspace *ui;
    QList<QMap<int, QVariant> > getHeaders();
    void setUpDragAndDrop();
    void bindEvents();
signals:
    void ImageAdded(cv::Mat image, QString fileName);
};

#endif // WORKSPACE_H
