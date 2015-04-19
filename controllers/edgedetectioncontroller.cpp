#include "edgedetectioncontroller.h"

edgeDetectionController::edgeDetectionController(Ui::MainWindow *ui, QMainWindow *mainWindow) : QObject(mainWindow)
{
    UI=ui;
    MainWindow = mainWindow;
    this->initDetectionTypesList();
}
void edgeDetectionController::initDetectionTypesList()
{
    UI->edge_detection_type->addItem(QString("Canny"), QString("canny"));
}

edgeDetectionController::~edgeDetectionController()
{

}
void edgeDetectionController::getEdges(){
    cv::Canny(sourceImage, edges, 100, 200);
}

