#ifndef STANDARDIMAGEITEM_H
#define STANDARDIMAGEITEM_H

#include <QObject>
#include <QStandardItem>

class StandardImageItem : public QStandardItem
{
public:
    explicit StandardImageItem();
    int type() const;

signals:

public slots:

};

#endif // STANDARDIMAGEITEM_H
