#ifndef MAINMODEL_H
#define MAINMODEL_H
#include "stdafx.h";
#include <QRegExp>
#include "imagemodel.h"

class MainModel : public ImageModel
{
    Q_OBJECT
public:
    MainModel(const QList<QList<QVariant> > &data, QObject *parent=0);
    // check if drop can be accepted
    virtual bool dropMimeData(const QMimeData *data, Qt::DropAction action, int row, int column, const QModelIndex &parent);
    virtual QStringList mimeTypes() const;
    void AddImage(const Mat image, const QString fileName);
private:
    QString fileExtentions = ".*\\.jpg$|.*\\.png$|.*\\.tif$|.*\\.tiff$|.*\\.jpeg$";
signals:
    void imageAdded(cv::Mat,QString);
};

#endif // MAINMODEL_H
