#include "controllermultichannel.h"

ControllerMultichannel::ControllerMultichannel(Ui::MainWindow *ui, QMainWindow *mainWindow) :
    QObject(mainWindow)
{
    _MainWindow = mainWindow;
    _TargetResultsList = ui->MI_TreeView;
    _AddColoredImage = ui->MI_addColorImage;
    _Save = ui->MI_save;
    _Preview = ui->MI_preview;

    _TargetResultsList->setDragEnabled(true);
    _TargetResultsList->viewport()->setAcceptDrops(true);
    _TargetResultsList->setDropIndicatorShown(true);
    _TargetResultsList->setDefaultDropAction(Qt::MoveAction);

    QList<QList<QVariant> > modelHeaders;
    QList<QVariant> Name;
    Name << QString("File");

    _TargetResultsModel = new ImageModel(modelHeaders);
    _TargetResultsList->setModel(_TargetResultsModel);

    QObject::connect(_Preview, SIGNAL(clicked()),
                     this, SLOT(ResultPreview()));
    QObject::connect(_Save, SIGNAL(clicked()),
                     this, SLOT(SaveImage()));
    QObject::connect(_AddColoredImage, SIGNAL(clicked()),
                                              this, SLOT(AddColoredImageToResults()));
}
ControllerMultichannel::~ControllerMultichannel()
{
    delete _TargetResultsModel;
}
void ControllerMultichannel::SaveImage()
{
    ImageItem *item=0;
    QModelIndexList selectedIndexes =_TargetResultsList->getSelectedIndexes();
    if (selectedIndexes.count())
    {
        QModelIndex index = selectedIndexes.first();
        item = static_cast<ImageItem*>(index.internalPointer());
        if(item->isValid())
        {
            cv::Mat image = item->getCVImage();
            QString fileName = QFileDialog::getSaveFileName(_MainWindow, QString("Save Image"), QString(), tr("Images (*.jpg *.png *.tif *.tiff *.jpeg);;(*.png);;(*.jpg *.jpeg);;(*.tif *.tiff)"));
            if(!fileName.isEmpty())
            {
                bool success = ProcessingCore::writeImage(fileName, image);
                if(success)
                {
                    emit this->imageSaved(fileName);
                }
            }
        }
    }
}
void ControllerMultichannel::ResultPreview()
{
    ImageItem *item=0;
    QModelIndexList selectedIndexes =_TargetResultsList->getSelectedIndexes();
    if (selectedIndexes.count())
    {
        QModelIndex index = selectedIndexes.first();
        item = static_cast<ImageItem*>(index.internalPointer());
        if(item->isValid())
        {
            QString name = item->data(0, Qt::DisplayRole).toString();
            cv::namedWindow(ProcessingCore::convertToStdString(name), cv::WINDOW_NORMAL | cv::WINDOW_KEEPRATIO);
            cv::imshow(ProcessingCore::convertToStdString(name), ProcessingCore::RGB2BGR(item->getCVImage()));
        }
    }
}
void ControllerMultichannel::AddColoredImageToResults()
{
    _TargetResultsModel->AddBlankItem();
    _TargetResultsList->expandAll();
}
