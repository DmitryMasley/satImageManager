#ifndef CONTROLLERFILTER_H
#define CONTROLLERFILTER_H
#include "stdafx.h"
#include <QObject>
#include "ui_mainwindow.h"

class ControllerFilter : public QObject
{
    Q_OBJECT
public:
    explicit ControllerFilter(Ui::MainWindow *ui,
                              QMainWindow* mainWindow);
    cv::Mat filterImage(cv::Mat image);
    cv::Mat BuildFilter(cv::Size imageSize);
signals:
    void imageSaved(QString fileName);
public slots:
    void setCurrentItem();
    void start();
    void save();
private:
    QObject* _parent;
    previewGraphicsView* _sourceView;
    previewGraphicsView* _resultView;
    QPushButton* _start;
    QPushButton* _setSelected;
    QPushButton* _save;
    QDoubleSpinBox* _LensRadius;
    QDoubleSpinBox* _OSWidth;
    QDoubleSpinBox* _WaveLength;
    QDoubleSpinBox* _DPI;
    ImageItem* _source;
    QMainWindow* _MainWindow;
    QTableView* _table1;
    QTableView* _table2;
    cv::Mat _result;
};

#endif // CONTROLLERFILTER_H
