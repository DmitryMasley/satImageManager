#ifndef CONTROLLERMAIN_H
#define CONTROLLERMAIN_H
#include "stdafx.h"
#include <QObject>
#include "mainmodel.h"
#include "ui_mainwindow.h"

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
    void MainViewSelectionChanged(ImageItem*);
    void SelectionRemoved();
    void ImageAdded(cv::Mat, QString);
public slots:
    void mainViewSelectionChanged(const QItemSelection &selected, const QItemSelection &deselected);
    void RemoveSelectedImage();
    void AddImage();
    void UpdateMainViewColumn();
    void viewCurrentImage();
    void loadSavedImage(QString fileName);
    
};

#endif // CONTROLLERMAIN_H
