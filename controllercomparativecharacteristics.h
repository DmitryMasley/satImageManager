#ifndef CONTROLLERCOMPARATIVECHARACTERISTICS_H
#define CONTROLLERCOMPARATIVECHARACTERISTICS_H
#include "stdafx.h"
#include <QObject>
#include "ui_mainwindow.h"
#include "basicmodel.h"
#include <QFileDialog>
#include <QTextDocumentWriter>
#include <QTextDocument>
#include <QTextCursor>
#include <QTextTable>
#include <QTextCodec>
#include "lib/standardmodel.h"
#include "lib/image/standardimageitem.h"

class ControllerComparativeCharacteristics : public QObject
{
    Q_OBJECT
public:
    explicit ControllerComparativeCharacteristics(Ui::MainWindow *ui,
                                                  QMainWindow* mainWindow);
    ~ControllerComparativeCharacteristics();

    QPushButton* nextStep;
    QPushButton* previousStep;
    QPushButton* setImg1;
    QPushButton* setImg2;
    previewGraphicsView* img1View;
    previewGraphicsView* img2View;
    BasicListView* characteristicsList;
    QTableView* resultsTable;
    SlidingStackedWidget* slidingWidget;
    BasicModel* characteristicsModel;
    BasicModel* resultModel;
    previewGraphicsView* ssimMap;
    QGroupBox* ssimMapContainer;
    QMainWindow* _MainWindow;
    void AddItemToTheList(QString name, int id_value);
    void AddResultToTable(double value, QString header);
    void calculate();
signals:
    
public slots:
    void setFirstImage();
    void setSecondImage();
    void goNext();
    void goPrev();
    void updateWidgetButtons(int index);
    void saveTable();
    void saveSsimMap();
};

#endif // COPMARATIVECHARACTERISTICSCONTROLLER_H
