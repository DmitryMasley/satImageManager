#ifndef CONTROLLERCHARACTERISTICS_H
#define CONTROLLERCHARACTERISTICS_H
#include "stdafx.h"
#include <QObject>
#include "characteristicslist.h"
#include "characteristicstable.h"
#include "characteristicsproggresbar.h"
#include "characteristicsmodel.h"
#include "ui_mainwindow.h"
#include "ImagePropertiesEvaluating.h"
#include <QFileDialog>

class ControllerCharacteristics : public QObject
{
    Q_OBJECT
public:
    explicit ControllerCharacteristics(Ui::MainWindow *ui,
                                       QMainWindow* mainWindow);
    ~ControllerCharacteristics();
    typedef double (*ImagePropMethod) (cv::Mat&);
    QList<ImagePropMethod> ImgPropMethodsList;
    QPushButton* EvalStart;
    QPushButton* SaveResults;
    BasicListView* Characteristics;
    CharacteristicsTable* ResultsTable;
    QStringListModel* chListModel;
    CharacteristicsModel* TableModel;
    QMainWindow* _MainWindow;
signals:
    void caracteristicEvaluatred(int, int);
    void ChEvalStarted();
    void ChEvalProgressChanged(int value);
public slots:
    void evalCharacteristics();
    void setCharacteristicsModel(ImageItem*);
    void clearCharacteristicsModel();
    void saveResultsToFile();
};

#endif // CONTROLLERCHARACTERISTICS_H
