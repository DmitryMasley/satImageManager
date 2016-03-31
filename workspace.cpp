#include "workspace.h"
#include "ui_workspace.h"

Workspace::Workspace(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Workspace)
{
    ui->setupUi(this);
    // image tree model
    imageListModel = new StandardImageModel(this->getHeaders());
    this->ui->workspace_image_list->setModel(imageListModel);
    this->setUpDragAndDrop();
    this->bindEvents();

}
Workspace::~Workspace()
{
    delete ui;
    delete imageListModel;
}
QList<QMap<int, QVariant> > Workspace::getHeaders(){
    QList<QMap<int, QVariant> > modelHeaders;
    QMap<int, QVariant> Name;
    Name.insert(0,  QString("File"));
    modelHeaders.append(Name);
    return modelHeaders;
}
void Workspace::setUpDragAndDrop(){
    this->ui->workspace_image_list->setAcceptDrops(true);
    this->ui->workspace_image_list->setAcceptDrops(true);
    this->ui->workspace_image_list->setDropIndicatorShown(true);
}
void Workspace::bindEvents(){
    QObject::connect(this->ui->workspace_add, SIGNAL(clicked()), this, SLOT(AddImage()));
}
void Workspace::AddImage(){
    QStringList fileNames = QFileDialog::getOpenFileNames(this, tr("Open image"),  "//", tr("Images (*.jpg *.png *.tif *.tiff *.jpeg)"));
    if (fileNames.count())
    {
        foreach (QString fileName, fileNames) {
            cv::Mat image = ProcessingCore::readImage(fileName);
            imageListModel->AddImage(image, fileName);
            emit ImageAdded(image, fileName);
        }
    }
}
