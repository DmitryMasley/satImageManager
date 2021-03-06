#include "mainmodel.h"

MainModel::MainModel(const QList<QMap<int, QVariant> > &data, QObject *parent) :
    StandardImageModel(data, parent)
{
}
bool MainModel::dropMimeData(const QMimeData *data, Qt::DropAction action, int row, int column, const QModelIndex &parent)
{
    // read only files
    if(!data->hasUrls())
    {
        return false;
    }
    QList<QUrl> urls = data->urls();
    foreach(QUrl url, urls)
    {
        QString fileName = url.toLocalFile();
        if(!fileName.isEmpty() && QFileInfo(fileName).exists())
        {
            QRegExp regex = QRegExp(this->fileExtentions);
            if(regex.exactMatch(fileName))
            {
                cv::Mat image = ProcessingCore::readImage(fileName);
                if(!!image.data)
                {
                    this->AddImage(image, fileName);
                }
            }

        }
    }
}
void MainModel::AddImage(const cv::Mat image, const QString fileName)
{
    StandardImageModel::AddImage(image, fileName);
    emit imageAdded(image, fileName);
}

QStringList MainModel::mimeTypes() const
{
    QStringList types;
    types << "image/tiff" << "image/png" << "image:jpeg" << "text/uri-list";
    return types;
}
