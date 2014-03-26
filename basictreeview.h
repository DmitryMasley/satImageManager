#ifndef BASICTREEVIEW_H
#define BASICTREEVIEW_H
#include "stdafx.h"
#include <QTreeView>

class BasicTreeView : public QTreeView
{
    Q_OBJECT
public:
    explicit BasicTreeView(QWidget *parent = 0);
    QModelIndexList getSelectedIndexes();
signals:
    
public slots:
    
};

#endif // BASICTREEVIEW_H
