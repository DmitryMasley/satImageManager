#include "controllermultichannelimages.h"

ControllerMultichannelImages::ControllerMultichannelImages(QObject *parent) :
    QObject(parent)
{
    _model = new StandardImageModel();
}
ControllerMultichannelImages::ControllerMultichannelImages(Ui::MainWindow *ui, QMainWindow *mainWindow):
    QObject(mainWindow)
{
    QList<QMap<int, QVariant> > data;
    QMap<int, QVariant> column;
    column.insert(Qt::DisplayRole, QString("Image"));
    data << column;
    _model = new StandardImageModel(data);
    _imageView = ui->MI_TreeView;
    _imageView->setModel(_model);
    _imageView->setAcceptDrops(true);
}
ControllerMultichannelImages::~ControllerMultichannelImages()
{
    delete _model;
}
void ControllerMultichannelImages::imageAdded(Mat image, QString fileName){
    _model->AddImage(image, fileName);
}

