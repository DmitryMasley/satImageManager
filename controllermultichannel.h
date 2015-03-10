#ifndef CONTROLLERMULTICHANNEL_H
#define CONTROLLERMULTICHANNEL_H

#include "stdafx.h"
#include <QObject>
#include "ui_mainwindow.h"
#include "imagemodel.h"
#include <QFileDialog>

class ControllerMultichannel : public QObject
{
    Q_OBJECT
public:
    explicit ControllerMultichannel(Ui::MainWindow *ui,
                                    QMainWindow* mainWindow);
    ~ControllerMultichannel();
private:
    QMainWindow* _MainWindow;
    BasicTreeView* _TargetResultsList;
    ImageModel* _TargetResultsModel;
    QPushButton* _AddColoredImage;
    QPushButton* _Preview;
    QPushButton* _Save;
signals:
    void imageSaved(QString fileName);
    
public slots:
    void ResultPreview();
    void AddColoredImageToResults();
    void SaveImage();
    
};

#endif // CONTROLLERMULTICHANNEL_H
