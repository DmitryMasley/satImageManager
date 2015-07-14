#include "mainwindow.h"
#include "controllerimagefusion.h"

ControllerImageFusion::ControllerImageFusion(Ui::MainWindow *ui,
                                             QMainWindow* MainWindow) :
    QObject(MainWindow)
{
    _MainView = ui->mainTreeView;
    _TargetSoursesList = ui->IF_sourses_list;
    _TargetResultsList = ui->IF_results_list;
    _PanList = ui->IF_pan_list;
    _AddToSourcesList = ui->IF_add_selected_to_list;
    _RemoveFromSourcesList = ui->IF_remove_from_source_list;
    _SetPan = ui->IF_set_pan;
    _StartButton = ui->IF_start;
    _Preview = ui->IF_preview;
    _Save = ui->IF_save;
    _AddColoredImage = ui->IF_add_color_image;
    _MainWindow = MainWindow;
    _UseNormalization = ui->IF_use_normalization;
    _WindowSize = ui->IF_windowSize;
    _OrthogonalizationType = ui->IF_orthogonalization_type;

    _TargetResultsList->setDragEnabled(true);
    _TargetResultsList->viewport()->setAcceptDrops(true);
    _TargetResultsList->setDropIndicatorShown(true);
    _TargetResultsList->setDefaultDropAction(Qt::MoveAction);

    QList<QList<QVariant> > modelHeaders;
    QList<QVariant> Name;
    Name << QString("File");
    modelHeaders.append(Name);


    _TargetSoursesModel = new GrayScaleImageModel(modelHeaders);
    _TargetSoursesList->setModel(_TargetSoursesModel);
    _TargetResultsModel = new ImageModel(modelHeaders);
    _TargetResultsList->setModel(_TargetResultsModel);
    _PanModel =  new ImageModel(modelHeaders);
    _PanList->setModel(_PanModel);

    // connect signals and slots
    QObject::connect(_AddToSourcesList, SIGNAL(clicked()),
                     this, SLOT(AddSelectedToSoursesList()));
    QObject::connect(_RemoveFromSourcesList, SIGNAL(clicked()),
                     this, SLOT(RemoveFromSoursesList()));
    QObject::connect(_StartButton, SIGNAL(clicked()),
                     this, SLOT(StartFuision()));
    QObject::connect(_SetPan, SIGNAL(clicked()),
                     this, SLOT(SetPanImage()));
    QObject::connect(_Preview, SIGNAL(clicked()),
                     this, SLOT(ResultPreview()));
    QObject::connect(_Save, SIGNAL(clicked()),
                     this, SLOT(SaveImage()));
    QObject::connect(_AddColoredImage, SIGNAL(clicked()),
                                              this, SLOT(AddColoredImageToResults()));

}
ControllerImageFusion::~ControllerImageFusion()
{
    delete _TargetSoursesModel;
    delete _TargetResultsModel;
}
void ControllerImageFusion::SetPanImage()
{
    MainWindow* main = static_cast<MainWindow*>(_MainWindow);
    ImageItem* item = main->getSelectedItem();
    if(item)
    {
        if (item->childCount()>0 || item->canHaveChildren())
        {
            QMessageBox msgBox;
            msgBox.setText("Panchromatic image (Mask) should be a gray scale image");
            msgBox.exec();
            return;
        }
        else
        {
            ImageItem* newItem = new ImageItem(*item);
            _PanModel->getRootNode()->empty();
            _PanModel->AddItem(newItem);
        }
    }
}
void ControllerImageFusion::AddSelectedToSoursesList()
{
    ImageItem* item = _MainView->GetSelectedItem();
    if (item!=0)
    {
        if (!item->canHaveChildren())
        {
            ImageItem* newItem = new ImageItem(*item);
            _TargetSoursesModel->AddItem(newItem);
        }
        else
        {
            for(int i=0; i<item->childCount(); i++)
            {
                ImageItem* newItem = new ImageItem(*(static_cast<ImageItem*>(item->child(i))));
                _TargetSoursesModel->AddItem(newItem);
            }
        }
    }
}
void ControllerImageFusion::RemoveFromSoursesList()
{
    QModelIndexList indexes =  _TargetSoursesList->getSelectedIndexes();
    int count = indexes.count();
    for (int i=0; i<count;i++)
    {
        QModelIndex index = indexes[i];
        if (index.isValid())
        {
            _TargetSoursesModel->removeItem(index);
        }
    }
}
ImageItem* ControllerImageFusion::getPanItem()
{
    ImageItem* pan = static_cast<ImageItem*>(_PanModel->getRootNode()->child(0));
    return pan;
}

cv::Mat ControllerImageFusion::getImage(ImageItem* item)
{
    cv::Mat image = item->getCVImage();
    return image;
}
QString ControllerImageFusion::getName(ImageItem* item)
{
    QString panName = item->data(0, Qt::DisplayRole).toString();
    return panName;
}
cv::Mat ControllerImageFusion::getInputMatrix(int cols, int rows, int type, QList<BasicModelItem*> sources)
{
    cv::Mat inputMatrix = cv::Mat::zeros(rows*cols, sources.count()+1, type);
    cv::Mat temp;
    for(int i = 0; i<sources.count(); i++)
    {
        temp = static_cast<ImageItem*>(sources.at(i))->getCVImage();
        cv::resize(temp, temp, cv::Size(cols, rows), cv::INTER_NEAREST);
        inputMatrix.col(i+1) = temp.reshape(0, 1).t()*1;
    }
    temp.release();
    return inputMatrix;
}

void ControllerImageFusion::fusion()
{
    QList<BasicModelItem*> sources = _TargetSoursesModel->getRootNode()->getChildren();
    BasicModelItem* panRoot = _PanModel->getRootNode();
    if(!panRoot->childCount())
    {
        QMessageBox msgBox;
        msgBox.setText("Panchromatic image is not specified");
        msgBox.exec();
        return;
    }
    if(!sources.length())
    {
        QMessageBox msgBox;
        msgBox.setText("No images was added to process");
        msgBox.exec();
        return;
    }
    emit this->FusionStarted();
    // get pan info
    ImageItem* pan = static_cast<ImageItem*>(_PanModel->getRootNode()->child(0));
    QString panName = pan->getName();
    cv::Mat panImage = getImage(pan);
    int panRows = panImage.rows;
    int panType = panImage.type();

    //build input matrix
    cv::Mat inputMatrix = getInputMatrix(panImage.cols, panImage.rows, panImage.type(), sources);
    ImageFusionProcessor* processor = new ImageFusionProcessor(inputMatrix, panImage, panType, _OrthogonalizationType->currentIndex());
    QThread* thread = new QThread();
    processor->moveToThread(thread);
    processor->exec();
    processor->moveToThread(QApplication::instance()->thread());
    delete thread;
    cv::Mat result = processor->result;

    delete processor;

    emit this->FusionProgress(90);
    _TargetResultsModel->empty();
//    int windowSize = _WindowSize->value();
    for(int i = 0; i<result.cols; i++)
    {
        cv::Mat temp;
        ImageItem* sourceItem = static_cast<ImageItem*>(sources.at(i));
        result.col(i).copyTo(temp);
        temp = temp.reshape(0, panRows);
        if(_UseNormalization->isChecked())
        {
            cv::Mat source = sourceItem->getCVImage();
//            for(int i = 1; i<=windowSize; i++)
//            {
//                this->scaledNormalization(temp, source, i);
//                windowSize--;
//            }
            this->correctBritness(temp, source);
//            this->scaledNormalization(temp, source, 1);
        }
        _TargetResultsModel->AddImage(temp, sourceItem->getName()+QString(" - ")+panName);
    }

    emit this->FusionProgress(100);
}
void ControllerImageFusion::scaledNormalization(cv::Mat &image, cv::Mat source, int windowSize)
{
    if(windowSize <= 0)
    {
        return;
    }
    float colRatioDb = image.cols/source.cols;
    float rowRatioDb = image.rows/source.rows;
    float val;
    if(std::modf(colRatioDb, &val)!= 0 || std::modf(rowRatioDb, &val) != 0)
    {
        return;
    }
    int colRatio = (int)(colRatioDb);
    int rowRatio = (int)(rowRatioDb);
    if(colRatio<=1 || rowRatio<=1)
    {
        return;
    }
    cv::Mat sourceConverted;
    source.convertTo(sourceConverted, CV_32F);
    int rows = source.rows;
    int cols = source.cols;
    for(int i = 0; i<rows-windowSize+1; i++)
    {
        const float* Mi = sourceConverted.ptr<float>(i);
        for(int j = 0; j<cols-windowSize+1; j++)
        {
            cv::Mat temp = cv::Mat(image, cv::Rect(j*colRatio, i*rowRatio, colRatio*windowSize, rowRatio*windowSize));
            cv::Scalar mean = cv::mean(temp);
            if(windowSize == 1)
            {
                mean.val[0] = Mi[j]-mean.val[0];
            }
            else
            {
                cv::Mat sourseWindow = cv::Mat(sourceConverted, cv::Rect(j, i, windowSize, windowSize));
                cv::Scalar sourseWindowMean = cv::mean(sourseWindow);
                mean.val[0] = sourseWindowMean.val[0]-mean.val[0];
            }
            cv::add(temp, mean, temp);
        }
    }
}
void ControllerImageFusion::windowNormalization(cv::Mat &image, cv::Mat source)
{
    float colRatioDb = image.cols/source.cols;
    float rowRatioDb = image.rows/source.rows;
    float val;
    if(std::modf(colRatioDb, &val)!= 0 || std::modf(rowRatioDb, &val) != 0)
    {
        return;
    }
    int colRatio = (int)(colRatioDb);
    int rowRatio = (int)(rowRatioDb);
    if(colRatio<=1 || rowRatio<=1)
    {
        return;
    }
    cv::Mat sourceConverted;
    source.convertTo(sourceConverted, CV_32F);
    int rows = image.rows;
    int cols = image.cols;
    for(int i = 0; i<=rows-rowRatio; i++)
    {
        for(int j = 0; j<=cols-colRatio; j++)
        {
            cv::Mat temp = cv::Mat(image, cv::Rect(j, i, colRatio, rowRatio));
            cv::Scalar mean = cv::mean(temp);
            div_t  rowDiv = std::div(i, rowRatio);
            div_t  colDiv = std::div(j, colRatio);
            cv::Mat sourceTemp;
            // if we reached to the age do not go outside of the image
            int roiCols=2, roiRows=2;
            if(i==rows-rowRatio)
            {
               roiRows = 1;
            }
            if(j==cols-colRatio)
            {
                roiCols = 1;
            }
            cv::Mat sourceRoi = cv::Mat(sourceConverted, cv::Rect(colDiv.quot, rowDiv.quot, roiCols, roiRows));
            sourceRoi.copyTo(sourceTemp);

            sourceTemp.at<float>(0, 0) = sourceTemp.at<float>(0, 0)*(colRatio-colDiv.rem)*(rowRatio-rowDiv.rem);
            if(roiRows>1)
            {
                sourceTemp.at<float>(1, 0) = sourceTemp.at<float>(1, 0)*(colRatio-colDiv.rem)*(rowDiv.rem);
            }
            if(roiCols>1)
            {
                sourceTemp.at<float>(0, 1) = sourceTemp.at<float>(0, 1)*(colDiv.rem)*(rowRatio-rowDiv.rem);
            }
            if(roiCols>1 && roiRows>1)
            {
                sourceTemp.at<float>(1, 1) = sourceTemp.at<float>(1, 1)*(colDiv.rem)*(rowDiv.rem);
            }

            sourceTemp = sourceTemp*(1.0/(rowRatio*colRatio));
            cv::Scalar sourceMean = cv::sum(sourceTemp);

            mean.val[0] = sourceMean.val[0]-mean.val[0];
            cv::add(temp, mean, temp);
        }
    }
}

void ControllerImageFusion::correctBritness(cv::Mat& image, cv::Mat source)
{
    float colRatioDb = image.cols/source.cols;
    float rowRatioDb = image.rows/source.rows;
    float val;

    if(std::modf(colRatioDb, &val)!= 0 || std::modf(rowRatioDb, &val) != 0)
    {
        return;
    }
    int colRatio = (int)(colRatioDb);
    int rowRatio = (int)(rowRatioDb);
    if(colRatio<=1 || rowRatio<=1)
    {
        return;
    }
    cv::Mat sourceConverted;
    source.convertTo(sourceConverted, CV_32F);
    int rows = source.rows;
    int cols = source.cols;
    for(int i = 0; i<rows-1; i++)
    {
        const float* Mi = sourceConverted.ptr<float>(i);
        for(int j = 0; j<cols-1; j++)
        {
            cv::Mat temp = cv::Mat(image, cv::Rect(j*colRatio, i*rowRatio, colRatio, rowRatio));
            cv::Scalar mean = cv::mean(temp);
            mean.val[0] = Mi[j]-mean.val[0];
            cv::add(temp, mean, temp);
        }
    }
}

void ControllerImageFusion::StartFuision()
{
    this->fusion();

}
void ControllerImageFusion::ResultPreview()
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
void ControllerImageFusion::AddColoredImageToResults()
{
    _TargetResultsModel->AddBlankItem();
}
void ControllerImageFusion::SaveImage()
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
