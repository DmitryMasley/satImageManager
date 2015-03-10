#ifndef CHARACTERISTICSLIST_H
#define CHARACTERISTICSLIST_H
#include "stdafx.h"
#include <QObject>
#include <QListView>
class CharacteristicsList : public QListView
{
    Q_OBJECT

public:
    CharacteristicsList(QWidget* container);
signals:

private slots:

};

#endif // CHARACTERISTICSLIST_H
