#ifndef EDGEDETECTIONCONTROLLER_H
#define EDGEDETECTIONCONTROLLER_H

#include <QMainWindow>
#include <QObject>
#include "mainmodel.h"
#include "ui_mainwindow.h"
#include <opencv2/opencv.hpp>
#include <opencv2/core/cuda.hpp>


class edgeDetectionController : public QObject
{
    Q_OBJECT
public:
    explicit edgeDetectionController(Ui::MainWindow *ui,
                                     QMainWindow* mainWindow);
    ~edgeDetectionController();
    void initDetectionTypesList();
    Ui::MainWindow* UI;
    QMainWindow* MainWindow;
    cv::Mat sourceImage;
    cv::Mat edges;
    void getEdges();

signals:

public slots:
};

#endif // EDGEDETECTIONCONTROLLER_H
