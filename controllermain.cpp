#include "controllermain.h"

ControllerMain::ControllerMain(Ui::MainWindow* ui,
                               QMainWindow *mainWindow) :
    QObject(mainWindow)
{
    MainView = ui->mainTreeView;
    Preview = ui->previewArea;
    MainToolbar = ui->mainToolBar;
    Add = ui->actionAdd;
    Remove = ui->actionRemove;
    ActionPreview = ui->actionPreview;
    MainWindow = mainWindow;
    QTabWidget* tab = ui->operations;

    // image tree model
    QList<QMap<int, QVariant> > modelHeaders;
    QMap<int, QVariant> Name;
    Name.insert(0, QString("File"));
    modelHeaders.append(Name);
    MainViewModel = new MainModel(modelHeaders);
    MainView->setAcceptDrops(true);
    MainView->viewport()->setAcceptDrops(true);
    MainView->setDropIndicatorShown(true);
    MainView->setModel(MainViewModel);

    MainToolbar->setFloatable(false);
    QObject::connect(tab, SIGNAL(currentChanged(int)),
                     Preview, SLOT(fitIntoView()));
    // connect signals and slots
    QObject::connect(Add, SIGNAL(triggered()),
                     this, SLOT(AddImage()));
    QObject::connect(Remove, SIGNAL(triggered()),
                     this, SLOT(RemoveSelectedImage()));
    QObject::connect(ActionPreview, SIGNAL(triggered()),
                     this, SLOT(viewCurrentImage()));
    QObject::connect(MainView, SIGNAL(selectionChanged(QItemSelection,QItemSelection)),
                     this, SLOT(mainViewSelectionChanged(QItemSelection,QItemSelection)));
    QObject::connect(this, SIGNAL(MainViewSelectionChanged(QImage*)),
                     Preview, SLOT(showPreview(QImage*)));
    QObject::connect(MainView, SIGNAL(expanded(QModelIndex)), this, SLOT(UpdateMainViewColumn()));
    QObject::connect(MainView, SIGNAL(collapsed(QModelIndex)), this, SLOT(UpdateMainViewColumn()));
    QObject::connect(this, SIGNAL(ImageAdded()), this, SLOT(UpdateMainViewColumn()));
    QObject::connect(this, SIGNAL(SelectionRemoved()), this, SLOT(UpdateMainViewColumn()));
    QObject::connect(MainViewModel, SIGNAL(layoutChanged()), this, SLOT(UpdateMainViewColumn()));
}
ControllerMain::~ControllerMain()
{
    delete MainViewModel;
}

void ControllerMain::UpdateMainViewColumn()
{
    MainView->resizeColumnToContents(0);
}

void ControllerMain::mainViewSelectionChanged(const QItemSelection &selected, const QItemSelection &deselected)
{
    QModelIndexList indexes = selected.indexes();

    if (!indexes.isEmpty())
    {
        QModelIndex index = indexes.first();
        if(index.isValid())
        {
            StandardImageItem* item =  static_cast<StandardImageItem*>(index.internalPointer());
            item->getQImage();
            emit MainViewSelectionChanged(item);
            emit MainViewSelectionChanged(item->getQImage());
        }
    }
    else
    {
        emit MainViewSelectionChanged(new QImage());
        emit SelectionRemoved();
    }
}
void ControllerMain::RemoveSelectedImage()
{
    QModelIndexList list =  MainView->getSelectedIndexes();
    if (!list.isEmpty())
    {
        QModelIndex index = list[0];
        if (index.isValid())
        {
            QModelIndex parent = index.parent();
            if (parent.isValid())
            {
                MainViewModel->removeItem(parent);
            }
            else
            {
                MainViewModel->removeItem(index);
            }
//            MainView->clearSelection();
        }
    }
}
void ControllerMain::AddImage()
{
    QStringList fileNames = QFileDialog::getOpenFileNames(this->MainWindow, tr("Open image"),  "//", tr("Images (*.jpg *.png *.tif *.tiff *.jpeg)"));
    if (fileNames.count())
    {
        foreach (QString fileName, fileNames) {
            cv::Mat image = ProcessingCore::readImage(fileName);
            MainViewModel->AddImage(image, fileName);
            emit ImageAdded(image, fileName);
        }
    }
}
void ControllerMain::viewCurrentImage()
{
    QModelIndexList indexes = MainView->getSelectedIndexes();

    if (!indexes.isEmpty())
    {
        QModelIndex index = indexes.first();
        if(index.isValid())
        {
            StandardImageItem* item =  static_cast<StandardImageItem*>(index.internalPointer());
            QString name = item->data(0, 0).toString();
            cv::namedWindow(ProcessingCore::convertToStdString(name), cv::WINDOW_NORMAL | cv::WINDOW_KEEPRATIO);
            cv::imshow(ProcessingCore::convertToStdString(name), ProcessingCore::RGB2BGR(item->getCVImage()));
        }
    }
}
void ControllerMain::loadSavedImage(QString fileName)
{
    cv::Mat image = ProcessingCore::readImage(fileName);
    MainViewModel->AddImage(image, fileName);
}
