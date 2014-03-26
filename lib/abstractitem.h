#ifndef ABSTRACTITEM_H
#define ABSTRACTITEM_H

#include <QObject>
#include <QMap>

typedef QMap<int, QVariant> IntStringMap;
class AbstractItem : public QObject
{
    Q_OBJECT
public:
    Q_INVOKABLE explicit AbstractItem(QObject *parent = 0);
    Q_INVOKABLE explicit AbstractItem(bool isRoot, QObject* parent = 0);
    Q_INVOKABLE explicit AbstractItem(QList<QMap<int, QVariant> > _data, QObject* parent = 0, bool isRoot = false);
    Q_INVOKABLE explicit AbstractItem(const AbstractItem& item);
    Q_PROPERTY(IntStringMap _header READ header WRITE setHeader NOTIFY headerChanged)

    ~AbstractItem();
    QMap<int, QVariant> header() const;
    void setHeader(QMap<int, QVariant> header);
    bool isRoot(); // depracted
    QList<AbstractItem*> getChildren();
    AbstractItem *child(int col);
    int childCount() const;
    int columnCount() const;
    void appendChild(QObject* item, int row=-1);
    void removeChild(QObject *child);
    bool removeChildren(int position, int count);
    QObjectList setChildren(QObjectList children);
    void empty(); // clear all children

    QString getClassName();

    QVariant data(int column, int role) const;
    bool setData(int column, const QVariant &value, int role);

    int row();
    void remove();

    bool setItemData(QList<QMap<int, QVariant> > data);
    void addData(QMap<int, QVariant> dataItem);
    QList<QMap<int, QVariant> > getData();


    bool canAcceptDrops(QString type = QString());
    QStringList getHeaders();
    void setHeaders(QStringList headers);
    QString getType();
    AbstractItem* findItem(QVariant value, int column, int role);
protected:
    bool _isComposite;
    bool virtual canAcceptMoreChildren();
    void virtual onChildrenChanged();
    bool virtual canHaveChildren();
    bool _isRoot; // depracted
    QList<QMap<int, QVariant> > _data;
    QStringList _headers;
    QString _type;
    QMap<int, QVariant> _header;
signals:
    void headerChanged(QMap<int, QVariant> header);
public slots:
private:

};

#endif // ABSTRACTITEM_H
