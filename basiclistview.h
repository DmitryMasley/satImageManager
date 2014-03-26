#ifndef BASICLISTVIEW_H
#define BASICLISTVIEW_H

#include <QtWidgets/QListView>

class BasicListView : public QListView
{
    Q_OBJECT
public:
    explicit BasicListView(QWidget *parent = 0);
    QModelIndexList getSelectedIndexes();
    
signals:
    
public slots:


};

#endif // BASICLISTVIEW_H
