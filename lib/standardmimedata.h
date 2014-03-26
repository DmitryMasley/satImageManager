#ifndef STANDARDMIMEDATA_H
#define STANDARDMIMEDATA_H
#include <QMimeData>
#include <QModelIndexList>
class StandardMimeData : public QMimeData
{
    Q_OBJECT
public:
    explicit StandardMimeData();
    ~StandardMimeData();
    void setIndexes(QModelIndexList);
    QModelIndexList getIndexes() const;
private:
    QModelIndexList _indexes;
signals:

public slots:

};

#endif // STANDARDMIMEDATA_H
