#ifndef IMAGEFUSIONCONTROLLER_H
#define IMAGEFUSIONCONTROLLER_H
#include <QObject>
#include "stdafx.h"
#include "imagetreeview.h"
#include "ui_mainwindow.h"
#include "imagefusionprocessor.h"

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
    void correctBritness(Mat &image, Mat source);
    void scaledNormalization(Mat &image, Mat source, int windowSize = 2);
    void windowNormalization(Mat &image, Mat source);
    Mat getPanImage();
    QString getName(ImageItem* item);
    ImageItem* getPanItem();
    Mat getInputMatrix(int cols, int rows, int type, QList<BasicModelItem *> sources);
    Mat getImage(ImageItem* item);
};

#endif // IMAGEFUSIONCONTROLLER_H
