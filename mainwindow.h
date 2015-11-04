#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "QtAwesome.h"
#include <QMainWindow>
#include <QFileDialog>
#include <QProgressDialog>
#include <stdafx.h>
#include <opencv2/opencv.hpp>
#include "imagetreemodel.h"
#include "controllermain.h"
#include "imageFusion/controllerimagefusion.h"
#include "controllerfilter.h"
#include "controllercomparativecharacteristics.h"
#include "controllercharacteristics.h"
#include "controllermultichannel.h"
#include "./multichannel/controllermultichannelimages.h"
#include "./controllers/edgedetectioncontroller.h"
#include "metatypes.h"
#include "workspace.h"
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ControllerMain* mainController;
    ControllerImageFusion* imageFusionController;
    ControllerCharacteristics* characteristicsController;
    ControllerFilter* filterController;
    ControllerComparativeCharacteristics* comparativeCharacteristicsController;
    ControllerMultichannelImages* multiChannelController;
    edgeDetectionController* edgeDetectionCntlr;
    ImageItem *getSelectedItem();
    QtAwesome* awesome;
    void dropEvent(QDropEvent *event);
    ~MainWindow();
private slots:

private:
    Ui::MainWindow *ui;
    ImageTreeModel* IF_sourse_list_model;
    QProgressDialog* _modalProgress;
    bool _progress;
signals:
    void progressStatus(bool);
public slots:
    void openModalProgress();
    void ProgressChanged(int value);
};

#endif // MAINWINDOW_H
