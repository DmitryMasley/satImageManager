#ifndef CONTROLLERMAIN_H
#define CONTROLLERMAIN_H
#include "stdafx.h"
#include <QObject>
#include "mainmodel.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include "ProcessingCore.h"

class ControllerMain : public QObject
{
    Q_OBJECT
public:
    explicit ControllerMain(Ui::MainWindow *ui,
                            QMainWindow* mainWindow);
    ~ControllerMain();

    ImageTreeView* MainView;
    QAction* Add;
    QAction* Remove;
    QAction* ActionPreview;
    previewGraphicsView* Preview;
    MainModel* MainViewModel;
    QToolBar* MainToolbar;
    QMainWindow* MainWindow;
signals:
    void MainViewSelectionChanged(QImage*);
    void MainViewSelectionChanged(StandardImageItem*);
    void SelectionRemoved();
    void ImageAdded(cv::Mat, QString);
    void ImageAdded();
public slots:
    void mainViewSelectionChanged(const QItemSelection &selected, const QItemSelection &deselected);
    void RemoveSelectedImage();
    void AddImage();
    void UpdateMainViewColumn();
    void viewCurrentImage();
    void loadSavedImage(QString fileName);
    
};

#endif // CONTROLLERMAIN_H
