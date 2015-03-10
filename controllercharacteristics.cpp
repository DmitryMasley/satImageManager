#include "controllercharacteristics.h"

ControllerCharacteristics::ControllerCharacteristics(Ui::MainWindow* ui,
                                                     QMainWindow* mainWindow) :
    QObject(mainWindow)
{
    ImgPropMethodsList << (ImagePropertiesEvaluating::ShannonEntropyEval);
    ImgPropMethodsList << (ImagePropertiesEvaluating::SignalEntropyEval);
    ImgPropMethodsList << (ImagePropertiesEvaluating::GradiationsUsingCoefficientEval);
    ImgPropMethodsList << (ImagePropertiesEvaluating::AdaptationLevelEval);
    ImgPropMethodsList << (ImagePropertiesEvaluating::MaxDynamicContrastEval);

    EvalStart = ui->evaluateParams;
    SaveResults = ui->saveParams;
    Characteristics = ui->ChrList;
    ResultsTable = ui->ChResultsTable;
    _MainWindow = mainWindow;

    // Characteristics List
    QStringList list;
    list <<
            QString("Shannon entropy") <<
            QString("Signal entropy") <<
            QString("Gradation using coefficient") <<
            QString("Adaptation level of brightness") <<
            QString("Max dynamic contrast");
    chListModel = new QStringListModel();
    chListModel->setStringList(list);
    Characteristics->setModel(chListModel);

    // Characteristics result model
    QList<QList<QVariant> > chmodelHeaders;
    QList<QVariant> Value;
    Value << QString("Value");
    chmodelHeaders << Value;
    TableModel = new CharacteristicsModel(chmodelHeaders);
    ResultsTable->setModel(TableModel);

    // connect signals and slots
    QObject::connect(EvalStart, SIGNAL(clicked()),
                     this, SLOT(evalCharacteristics()));
    QObject::connect(SaveResults, SIGNAL(clicked()),
                     this, SLOT(saveResultsToFile()));

}
ControllerCharacteristics::~ControllerCharacteristics()
{
    delete chListModel;
    delete TableModel;
}
void ControllerCharacteristics::evalCharacteristics()
{
    QModelIndexList characteristicsSelection = Characteristics->getSelectedIndexes();
    ImageItem* item = TableModel->getCurrentItem();
    if (item && item->parent())
    {
        cv::Mat image = item->getCVImage();
        int chrCount = characteristicsSelection.count();

        cv::Mat m; double chr=0;
        emit caracteristicEvaluatred(0, chrCount);
        emit ChEvalStarted();
        for (int i=0; i<chrCount; i++)
        {
            if (ImgPropMethodsList.count()>characteristicsSelection.value(i).row())
            {

                chr = ImgPropMethodsList[characteristicsSelection.value(i).row()](image);
                TableModel->setCharacteristic(characteristicsSelection.value(i).row(), QVariant(chr));
                chr = 0;
            }
            else
            {
                TableModel->setCharacteristic(characteristicsSelection.value(i).row(), QVariant());
            }
            emit caracteristicEvaluatred(i+1, chrCount);
            emit ChEvalProgressChanged((int)(100*(i+1)/chrCount));
            QCoreApplication::processEvents();
        }
    }

}
void ControllerCharacteristics::setCharacteristicsModel(ImageItem* item)
{
    TableModel->clear();
    TableModel->appendItems(item->Characteristics);
    TableModel->setCurrentItem(item);
}
void ControllerCharacteristics::clearCharacteristicsModel()
{
    TableModel->resetModel();
}
void ControllerCharacteristics::saveResultsToFile()
{
    QString fileName = QFileDialog::getSaveFileName(_MainWindow,
                                                    QString("Save image characteristics"),  QString(""),
                                                    QString("Text(*.txt);;Web-page(*.html);;Open document text(*.odt)"));
    if (fileName != QString(""))
    {
        QTextDocumentWriter docWriter(fileName);
        QTextDocument* document = new QTextDocument();
        ImageItem* item = TableModel->getCurrentItem();
        QList<QString> headers = item->getHeaders();
        QTextCursor* cursor = new QTextCursor(document);
        QTextTable* table = cursor->insertTable(headers.count()+item->Characteristics.count(), 2);
        for(int i = 0; i<headers.count(); i++)
        {
            table->cellAt(i,0).firstCursorPosition().insertText(headers.value(i));;
            table->cellAt(i,1).firstCursorPosition().insertText(item->data(i, Qt::DisplayRole).toString());
        }
        for(int i = 0; i<item->Characteristics.count(); i++)
        {
            table->cellAt(i+headers.count(),0).firstCursorPosition().insertText(item->ChList.value(i));;
            table->cellAt(i+headers.count(),1).firstCursorPosition().insertText(item->Characteristics.value(i)->data(0, 0).toString());
        }
        docWriter.setCodec(QTextCodec::codecForName("UTF-8"));
        docWriter.write(document);
    }
}
