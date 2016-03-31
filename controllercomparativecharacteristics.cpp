#include "controllercomparativecharacteristics.h"

ControllerComparativeCharacteristics::ControllerComparativeCharacteristics(Ui::MainWindow *ui, QMainWindow *mainWindow) :
    QObject(mainWindow)
{
    nextStep = ui->comp_char_widget_next;
    previousStep = ui->comp_char_widget_prev;
    setImg1 = ui->comp_char_set_img1;
    setImg2 = ui->comp_char_set_img2;
    img1View = ui->comp_char_img1_view;
    img2View = ui->comp_char_img2_view;
    characteristicsList = ui->comp_char_list;
    resultsTable = ui->comp_char_results_table;
    slidingWidget = ui->comp_char_widget;
    ssimMap = ui->comp_char_ssim_map;
    ssimMapContainer = ui->comp_char_ssim_map_container;
    _MainWindow = mainWindow;

    QList<QList<QVariant> > rootData;
        QList<QVariant> rootDataItem;
        rootDataItem << QVariant("Characteristic");
        rootData << rootDataItem;
    characteristicsModel = new BasicModel(rootData);

    QList<QList<QVariant> > rootResultData;
        QList<QVariant> rootResultDataItem;
        rootResultDataItem << QVariant("Value");
        rootResultData << rootResultDataItem;
    resultModel = new BasicModel(rootResultData);

    AddItemToTheList(QString("SSIM Index"), 0);
    AddItemToTheList(QString("Mean Difference"), 1);
    AddItemToTheList(QString("Normalized Correlation"), 2);
    AddItemToTheList(QString("Correlation Quality"), 3);
    AddItemToTheList(QString("Max Difference"), 4);
    AddItemToTheList(QString("Image Fidelity"), 5);
    AddItemToTheList(QString("Laplasian Mean Square Error"), 6);
    AddItemToTheList(QString("Mean Square Error"), 7);
    AddItemToTheList(QString("Peak Mean Square Error"), 8);
    AddItemToTheList(QString("Normalized Absolute Error"), 9);
    AddItemToTheList(QString("Normalized Mean Square Error"), 10);
    AddItemToTheList(QString("SNR"), 11);
    AddItemToTheList(QString("PSNR"), 12);


    characteristicsList->setModel(characteristicsModel);
    resultsTable->setModel(resultModel);
    QObject::connect(nextStep, SIGNAL(clicked()),
                     this, SLOT(goNext()));
    QObject::connect(previousStep, SIGNAL(clicked()),
                     this, SLOT(goPrev()));
    QObject::connect(setImg1, SIGNAL(clicked()),
                     this, SLOT(setFirstImage()));
    QObject::connect(slidingWidget, SIGNAL(animationStarted(int)),
                     this, SLOT(updateWidgetButtons(int)));
    QObject::connect(ui->comp_char_results_table_save, SIGNAL(clicked()),
                     this, SLOT(saveTable()));
    QObject::connect(ui->comp_char_ssim_map_save, SIGNAL(clicked()),
                     this, SLOT(saveSsimMap()));
}

ControllerComparativeCharacteristics::~ControllerComparativeCharacteristics()
{
    delete characteristicsModel;
    delete resultModel;
}

void ControllerComparativeCharacteristics::AddItemToTheList(QString name, int id_value)
{
    QList<QList<QVariant> > data;
    QList<QVariant> title;

    title << name;

    QList<QVariant> id;
    id << QVariant(id_value);

    data << title << id;
    BasicModelItem* item = new BasicModelItem(data);

    characteristicsModel->AddItem(item);
}

void ControllerComparativeCharacteristics::setFirstImage()
{

}
void ControllerComparativeCharacteristics::setSecondImage()
{

}
void ControllerComparativeCharacteristics::goPrev()
{
    switch(slidingWidget->currentIndex())
    {
        case 0:
            break;
        case 1:
            break;
    }
    slidingWidget->slideInPrev();
}
void ControllerComparativeCharacteristics::goNext()
{
    switch(slidingWidget->currentIndex())
    {
        case 0:
            if(!img1View->image || !img2View->image)
            {
               return;
            }
            break;
        case 1:
            if(!characteristicsList->getSelectedIndexes().count())
            {
                return;
            }
            this->calculate();
            break;
    }
    slidingWidget->slideInNext();
}
void ControllerComparativeCharacteristics::updateWidgetButtons(int index)
{
    switch(index)
    {
        case 0:
            nextStep->show();
            previousStep->hide();
            break;
        case 2:
            nextStep->hide();
            previousStep->show();
            break;
        default:
            nextStep->show();
            previousStep->show();
    }
}

void ControllerComparativeCharacteristics::calculate()
{
    if(img1View->image && img2View->image)
    {
        cv::Mat firstImage  = img1View->image->getCVImage();
        cv::Mat secondImage = img2View->image->getCVImage();
        resultModel->emptyHeaders(Qt::Vertical);
        resultModel->empty();
        if(firstImage.cols != secondImage.cols || firstImage.rows != secondImage.rows)
        {
            cv::resize(secondImage, secondImage, cv::Size(firstImage.cols, firstImage.rows), 0, 0);
        }
        QModelIndexList selected =  characteristicsList->getSelectedIndexes();
        ssimMapContainer->setVisible(false);

        foreach (QModelIndex prop, selected)
        {
            BasicModelItem* listItem = characteristicsModel->getItem(prop);
            QString name = listItem->data(0, 0).toString();
            int id = listItem->data(1, 0).toInt();
            QList<QList<QVariant> > data;
            QList<QVariant> value;
            QList<QVariant> header;
            BasicModelItem* item;
            switch(id)
            {
                case 0:
                {
                    cv::Mat mask;
                    cv::Mat ssim_map;
//                    double ssim_Index = ProcessingCore::calcSSIM(firstImage, secondImage, mask, ssim_map);
                    cv::Scalar ssim_Index = ProcessingCore::getMSSIM(firstImage, secondImage, ssim_map);
                    AddResultToTable(ssim_Index[0], name);
                    ssimMapContainer->setVisible(true);
                    ssimMap->setImageItem(new StandardImageItem(ssim_map, QString("SSIM Map")));
                    break;
                }
                case 1:
                {
                    double meanDiff = ProcessingCore::meanDiff(firstImage, secondImage);
                    AddResultToTable(meanDiff, name);
                    break;
                }
                case 2:
                {
                    double normCorrelation = ProcessingCore::normCorrelation(firstImage, secondImage);
                    AddResultToTable(normCorrelation, name);
                    break;
                }
                case 3:
                {
                    double corQty = ProcessingCore::correlationQuality(firstImage, secondImage);
                    AddResultToTable(corQty, name);
                    break;
                }
                case 4:
                {
                    double maxDiff = ProcessingCore::maxDiff(firstImage, secondImage);
                    AddResultToTable(maxDiff, name);
                    break;
                }
                case 5:
                {
                    double imgFty = ProcessingCore::imageFidelity(firstImage, secondImage);
                    AddResultToTable(imgFty, name);
                    break;
                }
                case 6:
                {
                    double laplMeanSqError = ProcessingCore::laplMeanSqError(firstImage, secondImage);
                    AddResultToTable(laplMeanSqError, name);
                    break;
                }
                case 7:
                {
                    double meanSqError = ProcessingCore::meanSqError(firstImage, secondImage);
                    AddResultToTable(meanSqError, name);
                    break;
                }
                case 8:
                {
                    double peakMeanSqError = ProcessingCore::peakMeanSqError(firstImage, secondImage);
                    AddResultToTable(peakMeanSqError, name);
                    break;
                }
                case 9:
                {
                    double normalizedAbsoluteError = ProcessingCore::normalizedAbsoluteError(firstImage, secondImage);
                    AddResultToTable(normalizedAbsoluteError, name);
                    break;
                }
                case 10:
                {
                    double normalizedMeanSquareError = ProcessingCore::normalizedMeanSquareError(firstImage, secondImage);
                    AddResultToTable(normalizedMeanSquareError, name);
                    break;
                }
                case 11:
                {
                    double snr = ProcessingCore::snr(firstImage, secondImage);
                    AddResultToTable(snr, name);
                    break;
                }
                case 12:
                {
                    double psnr = ProcessingCore::psnr(firstImage, secondImage);
                    AddResultToTable(psnr, name);
                    break;
                }
            }
        }

    }
}
void ControllerComparativeCharacteristics::AddResultToTable(double value, QString header)
{
    QList<QList<QVariant> > data;
    QList<QVariant> table_value;
    QList<QVariant> table_header;
    BasicModelItem* item;

    table_value << QVariant(value);
    data << table_value;
    item = new BasicModelItem(data);

    resultModel->AddItem(item);

    table_header << QVariant(header);
    resultModel->verticalHeaders.append(table_header);

}
void ControllerComparativeCharacteristics::saveSsimMap()
{
    if(ssimMap->image)
    {
        cv::Mat image = ssimMap->image->getCVImage();
        QString fileName = QFileDialog::getSaveFileName(_MainWindow, QString("Save Image"), QString(), tr("Images (*.jpg *.png *.tif *.tiff *.jpeg);;(*.png);;(*.jpg *.jpeg);;(*.tif *.tiff)"));
        if(!fileName.isEmpty())
        {
            bool success = ProcessingCore::writeImage(fileName, image);
            if(success)
            {

            }
        }
    }
}
void ControllerComparativeCharacteristics::saveTable()
{
    QString fileName = QFileDialog::getSaveFileName(_MainWindow,
                                                    QString("Save image characteristics"),  QString(""),
                                                    QString("Text(*.txt);;Web-page(*.html);;Open document text(*.odt)"));
    if (fileName != QString(""))
    {
        QTextDocumentWriter docWriter(fileName);
        QTextDocument* document = new QTextDocument();
        QTextCursor* cursor = new QTextCursor(document);
        int chrCount = resultModel->rowCount();
        QTextTable* table = cursor->insertTable(resultModel->rowCount(), 2);
        for(int i = 0; i<chrCount; i++)
        {
            QString header = resultModel->verticalHeaders.at(i).at(0).toString();
            table->cellAt(i,0).firstCursorPosition().insertText(header);
            table->cellAt(i,1).firstCursorPosition().insertText(resultModel->getRootNode()->child(i)->data(0, 0).toString());
        }
        docWriter.setCodec(QTextCodec::codecForName("UTF-8"));
        docWriter.write(document);
    }
}
