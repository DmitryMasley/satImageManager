#include "edgedetectioncontroller.h"

edgeDetectionController::edgeDetectionController(Ui::MainWindow *ui, QMainWindow *mainWindow) : QObject(mainWindow)
{
    UI=ui;
    MainWindow = mainWindow;
    this->initDetectionTypesList();
    QObject::connect(ui->edge_get, SIGNAL(clicked()),
                     this, SLOT(getEdges()));
    QObject::connect(ui->edges_source, SIGNAL(imageChanged(ImageItem*)),
                     this, SLOT(sourceImageChanged(ImageItem*)));

}
void edgeDetectionController::initDetectionTypesList()
{
    UI->edge_detection_type->addItem(QString("Canny"), QString("canny"));
    UI->edge_detection_type->setCurrentIndex(0);
}
void edgeDetectionController::getEdges(){
    if(sourceImage.cols>0 && sourceImage.rows>0){
        QVariant data = UI->edge_detection_type->currentData();
        if(data.toString() == "canny"){
            edges = this->getCannyEdges(sourceImage);
            cv::imshow("Canny Edges", edges);
        }
    }
}
void edgeDetectionController::sourceImageChanged(ImageItem *item){
    sourceImage = item->getCVImage();
}

edgeDetectionController::~edgeDetectionController()
{

}
cv::Mat edgeDetectionController::getCannyEdges(cv::Mat source){
    cv::Mat result;
    cv::Canny(source, result, 100, 200);
    return result;
}

