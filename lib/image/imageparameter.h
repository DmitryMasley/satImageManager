#ifndef IMAGEPARAMETER_H
#define IMAGEPARAMETER_H

#include <QObject>
#include "../abstractitem.h"

class ImageParameter : public AbstractItem
{
    Q_OBJECT
public:
    Q_INVOKABLE explicit ImageParameter(QObject *parent = 0);
    Q_INVOKABLE explicit ImageParameter(bool isRoot, QObject* parent = 0);
    Q_INVOKABLE explicit ImageParameter(QList<QMap<int, QVariant> > _data, QObject* parent = 0, bool isRoot = false);
    ~ImageParameter();

signals:

public slots:
};

#endif // IMAGEPARAMETER_H
