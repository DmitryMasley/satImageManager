#ifndef BASICITEMMIMEDATA_H
#define BASICITEMMIMEDATA_H

#include <QObject>

class BasicItemMimeData : public QObject
{
    Q_OBJECT
public:
    explicit BasicItemMimeData(QList<QList<QVariant> > _data,
                               QString _type=QString(),
                               QList<BasicItemMimeData* > _children = QList<BasicItemMimeData* >(),
                               QObject *parent = 0);
    QList<QList<QVariant> > data;
    QString type;
    QList<BasicItemMimeData* > children;
signals:
    
public slots:
    
};

#endif // BASICITEMMIMEDATA_H
