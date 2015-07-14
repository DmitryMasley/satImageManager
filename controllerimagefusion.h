#ifndef IMAGEFUSIONCONTROLLER_H
#define IMAGEFUSIONCONTROLLER_H
#include <QObject>
#include "stdafx.h"
#include <opencv2/opencv.hpp>
#include <opencv2/core/cuda.hpp>
#include "imagetreeview.h"
#include "ui_mainwindow.h"
#include "imagemodel.h"
#include "imageFusion/imagefusionprocessor.h"

class ControllerImageFusion : public QObject
{
    Q_OBJECT
public:
    explicit ControllerImageFusion(Ui::MainWindow* ui,
                                   QMainWindow *MainWindow);
    ~ControllerImageFusion();
signals:
    void FusionStarted();
    void FusionEnd();
    void FusionProgress(int progress);
    void imageSaved(QString fileName);
public slots:
    void AddSelectedToSoursesList();
    void RemoveFromSoursesList();
    void StartFuision();
    void SetPanImage();
    void ResultPreview();
    void AddColoredImageToResults();
    void SaveImage();
private:
    ImageTreeView* _MainView;
    BasicListView* _TargetSoursesList;
    BasicTreeView* _TargetResultsList;
    QListView* _PanList;
    QPushButton* _AddToSourcesList;
    QPushButton* _RemoveFromSourcesList;
    QPushButton* _SetPan;
    QPushButton* _StartButton;
    QPushButton* _Preview;
    QPushButton* _Save;
    QPushButton* _AddColoredImage;
    ImageModel* _TargetSoursesModel;
    ImageModel* _TargetResultsModel;
    ImageModel* _PanModel;
    QMainWindow* _MainWindow;
    QCheckBox* _UseNormalization;
    QSpinBox* _WindowSize;
    QObject* _parent;
    QComboBox* _OrthogonalizationType;
    void fusion();
    void correctBritness(cv::Mat &image, cv::Mat source);
    void scaledNormalization(cv::Mat &image, cv::Mat source, int windowSize = 2);
    void windowNormalization(cv::Mat &image, cv::Mat source);
    cv::Mat getPanImage();
    QString getName(ImageItem* item);
    ImageItem* getPanItem();
    cv::Mat getInputMatrix(int cols, int rows, int type, QList<BasicModelItem *> sources);
    cv::Mat getImage(ImageItem* item);
};

#endif // IMAGEFUSIONCONTROLLER_H
