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
    Mat filterImage(Mat image);
    Mat BuildFilter(Size imageSize);
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
    Mat _result;
};

#endif // CONTROLLERFILTER_H
