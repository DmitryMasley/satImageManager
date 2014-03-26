#ifndef CONTROLLERMULTICHANNELIMAGES_H
#define CONTROLLERMULTICHANNELIMAGES_H
#include <QObject>
#include "ui_mainwindow.h"
#include "../lib/image/standardimagemodel.h"

class ControllerMultichannelImages : public QObject
{
    Q_OBJECT
public:
    explicit ControllerMultichannelImages(QObject* parent=0);
    explicit ControllerMultichannelImages(Ui::MainWindow *ui,
                              QMainWindow* mainWindow);
    ~ControllerMultichannelImages();
private:
    StandardImageModel* _model;
    QTreeView* _imageView;
private slots:
    void imageAdded(cv::Mat image, QString fileName);
};

#endif // CONTROLLERMULTICHANNELIMAGES_H
