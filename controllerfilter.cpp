#include "mainwindow.h"
#include "controllerfilter.h"

ControllerFilter::ControllerFilter(Ui::MainWindow* ui,
                                   QMainWindow* mainWindow) :
    QObject(mainWindow)
{
    _sourceView = ui->filter_source_view;
    _resultView = ui->filter_result_view;
    _start = ui->filter_start;
    _save = ui->filter_save;
    _setSelected = ui->filter_set_current_image;
    _LensRadius = ui->filter_lens_radius;
    _OSWidth = ui->filter_os_width;
    _WaveLength = ui->filter_wavelength;
    _DPI = ui->matrix_dpi;
    _source = 0;
    _MainWindow = mainWindow;
//    _table1 = ui->tableView;
//    _table2 = ui->tableView_2;


    QObject::connect(_setSelected, SIGNAL(clicked()),
                     this, SLOT(setCurrentItem()));
    QObject::connect(_start, SIGNAL(clicked()),
                     this, SLOT(start()));
    QObject::connect(_save, SIGNAL(clicked()),
                     this, SLOT(save()));
}
void ControllerFilter::setCurrentItem()
{
    MainWindow* main = static_cast<MainWindow*>(_MainWindow);
    StandardImageItem* item = main->getSelectedItem();
    if(item)
    {
        _sourceView->copyImageItem(item);
    }
}
void ControllerFilter::start()
{
    if(_sourceView->image)
    {
        MainWindow* main = static_cast<MainWindow*>(_MainWindow);
        main->openModalProgress();
        cv::Mat image = _sourceView->image->getCVImage();
        _result = filterImage(image);
        QImage* img = ProcessingCore::convertToQImage(_result);
        _resultView->showImage(img);
        main->ProgressChanged(100);
    }
}
cv::Mat ControllerFilter::filterImage(cv::Mat image)
{
    int cols = image.cols;
    int rows = image.rows;
    cv::Mat imageFFT = ProcessingCore::FFT(image);
    cv::Mat filter = this->BuildFilter(imageFFT.size());

    vector<cv::Mat> channels;
    cv::split(imageFFT, channels);
//    Mat magn;
//    cv::magnitude(channels[0], channels[1], magn);
//    delete _table2->model();
//    _table2->setModel(new MatModel(magn));
//    double max;
//    cv::minMaxLoc(magn, NULL, &max);
//    double c = 255/(std::log(1.0+max));
//    cv::log((magn+1), magn);
//    magn=magn*c;
//    magn.convertTo(magn, CV_8U);
//    delete _table1->model();
//    _table1->setModel(new MatModel(magn));

    cv::divide(channels[0], filter, channels[0]);
    cv::divide(channels[1], filter, channels[1]);
    cv::merge(channels, imageFFT);
    cv::Mat imageIFFT = ProcessingCore::IFT(imageFFT, image.type());
    imageIFFT = imageIFFT(cv::Rect(0, 0, cols, rows));
    return imageIFFT;
}
cv::Mat ControllerFilter::BuildFilter(cv::Size imageSize)
{
    cv::Mat filter = cv::Mat::ones(imageSize, CV_64F);
    double dpi = _DPI->value()/2.54E-2;
    double lambda = _WaveLength->value()*1E-9;
    double D = _LensRadius->value()*1E-3;
    double d = _OSWidth->value()*1E-3;
    double PI = 4.*atan(1.);
    for(int i = 0; i < imageSize.height; i++)
    {
        double* Mi = filter.ptr<double>(i);
        for(int j = 0; j < imageSize.width; j++)
        {
//            if(i>(imageSize.height/10) && j>(imageSize.width/10))
//            {
//                Mi[j] = 100;
//            }
//            else
//            {
//                Mi[j] = 1;
//            }
            double f = std::sqrt(std::pow(dpi*(j+1)/imageSize.width, 2)+std::pow(dpi*(i+1)/imageSize.height, 2))/*/imageSize.area()*/;
            f =f*d*lambda/D;
            if(f>1)
            {
                Mi[j] = 0;
            }
            else
            {
                Mi[j] = (2/PI)*(acos(f)-f*sqrt(1-f*f));
            }
        }
    }
    return filter;
}
void ControllerFilter::save()
{
    if(_result.cols && _result.rows)
    {
        QString fileName = QFileDialog::getSaveFileName(_MainWindow, QString("Save Image"), QString(), tr("Images (*.jpg *.png *.tif *.tiff *.jpeg);;(*.png);;(*.jpg *.jpeg);;(*.tif *.tiff)"));
        if(!fileName.isEmpty())
        {
            bool success = ProcessingCore::writeImage(fileName, _result);
            if(success)
            {
                emit this->imageSaved(fileName);
            }
        }
    }
}
