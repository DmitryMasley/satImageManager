#include "mainwindow.h"
#include "ui_mainwindow.h"
using namespace cv;
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    QFontDatabase database;
    int id = database.addApplicationFont(":/resource/icons/fonts/FontAwesome.otf");


    awesome = new QtAwesome(QApplication::instance());
    awesome->initFontAwesome();
    qRegisterMetaTypeStreamOperators<QList<QList<QVariant> > >("QList<QList<QVariant> >");
//    qRegisterMetaTypeStreamOperators<cv::Mat>("Mat");
    ui->setupUi(this);
    QVariantMap options;
    options.insert( "color" , QColor("white"));
    ui->actionAdd->setIcon(awesome->icon(fa::plus, options));
    ui->actionRemove->setIcon(awesome->icon(fa::remove, options));
    ui->actionPreview->setIcon(awesome->icon(fa::image, options));
    ui->menu_file->addAction(ui->actionAdd);
    ui->menu_file->addAction(ui->actionRemove);
    ui->menu_file->addAction(ui->actionPreview);
//    Mat x = Mat::zeros(8, 3, CV_32FC1);
//    x.at<float>(0, 0) = 5.0;
//    cv::SVD xSVD = cv::SVD(x);
////     we got it in as vector, transform it to diagonal matrix
//           Mat W=Mat::zeros(xSVD.w.rows,xSVD.w.rows,CV_32FC1);
//           for(int i=0;i<xSVD.w.rows;i++)
//           {
//               W.at<float>(i,i)=xSVD.w.at<float>(i);
//           }
//           x = xSVD.u*W*xSVD.vt;
    // modal progress dialog
    _modalProgress = new QProgressDialog(QString("Processing..."),
                                         QString(/*"Abort"*/),
                                         0,
                                         INT_MAX,
                                         static_cast<QWidget*>(this));
    _modalProgress->setWindowTitle(QString("Operation in progress"));
    QProgressBar* bar = new QProgressBar(_modalProgress);
    bar->setRange(0, 100);
    bar->setValue(0);
    bar->setAlignment(Qt::AlignHCenter | Qt::AlignCenter);
    bar->setFormat(QString("%p%"));
    _modalProgress->setBar(bar);
    _modalProgress->setMinimumWidth(350);
    _modalProgress->setWindowModality(Qt::WindowModal);

    imageFusionController = new ControllerImageFusion(ui,
                                                      this);

    characteristicsController = new ControllerCharacteristics(ui,this);
    mainController = new ControllerMain(ui,this);
    filterController = new ControllerFilter(ui,this);
    comparativeCharacteristicsController = new ControllerComparativeCharacteristics(ui, this);
    multiChannelController = new ControllerMultichannelImages(ui, this);
    edgeDetectionCntlr = new edgeDetectionController(ui, this);

    // controllers connections
    QObject::connect(mainController, SIGNAL(MainViewSelectionChanged(ImageItem*)),
                     characteristicsController, SLOT(setCharacteristicsModel(ImageItem*)));
    QObject::connect(mainController, SIGNAL(SelectionRemoved()),
                     characteristicsController, SLOT(clearCharacteristicsModel()));
    QObject::connect(imageFusionController, SIGNAL(FusionStarted()),
                     this, SLOT(openModalProgress()));
    QObject::connect(imageFusionController, SIGNAL(FusionProgress(int)),
                     this, SLOT(ProgressChanged(int)));
    // progress events
    QObject::connect(characteristicsController, SIGNAL(ChEvalStarted()),
                     this, SLOT(openModalProgress()));
    QObject::connect(characteristicsController, SIGNAL(ChEvalProgressChanged(int)),
                     this, SLOT(ProgressChanged(int)));
    QObject::connect(imageFusionController, SIGNAL(FusionStarted()),
                     this, SLOT(openModalProgress()));
    QObject::connect(imageFusionController, SIGNAL(FusionProgress(int)),
                     this, SLOT(ProgressChanged(int)));
    QObject::connect(imageFusionController, SIGNAL(imageSaved(QString)),
                     mainController, SLOT(loadSavedImage(QString)));
    QObject::connect(filterController, SIGNAL(imageSaved(QString)),
                     mainController, SLOT(loadSavedImage(QString)));
    QObject::connect(mainController, SIGNAL(ImageAdded(cv::Mat,QString)),
                     multiChannelController, SLOT(imageAdded(cv::Mat,QString)));
}

MainWindow::~MainWindow()
{
    delete ui;
    delete imageFusionController;
    delete characteristicsController;
    delete mainController;
    delete _modalProgress;
    delete multiChannelController;
    delete awesome;
}
void MainWindow::openModalProgress()
{
    _modalProgress->setValue(0);
    _modalProgress->show();
}
void MainWindow::ProgressChanged(int value)
{
   _modalProgress->setValue(value);
}
ImageItem* MainWindow::getSelectedItem()
{
    return ui->mainTreeView->GetSelectedItem();
}
void MainWindow::dropEvent(QDropEvent *event)
{
    const QMimeData* mimeData = event->mimeData();
    if(mimeData->hasUrls())
    {
        QStringList pathList;
        QList<QUrl> urlList = mimeData->urls();

        foreach (QUrl url, urlList) {
            pathList.append(url.toLocalFile());
        }
        foreach (QString path, pathList) {
            mainController->loadSavedImage(path);
        }
    }
}
