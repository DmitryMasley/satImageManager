#ifndef BASEMODELITEM_H
#define BASEMODELITEM_H

#include <QObject>

class BasicModelItem : public QObject
{
    Q_OBJECT
public:
    explicit BasicModelItem(BasicModelItem* parent = 0, bool isRoot = false);
    explicit BasicModelItem(QList<QList<QVariant> > data, BasicModelItem* parent = 0, bool isRoot = false);
    explicit BasicModelItem(BasicModelItem& item);
    QList<QMap<int, QVariant> > _row;
    bool isRoot();
    ~BasicModelItem();
    virtual void setClassName();
    QString getClassName();
    void appendChild(BasicModelItem* item, int row=-1);
    void setParent(BasicModelItem* parent);
    BasicModelItem* child(int row);
    int childCount() const;
    int columnCount() const;
    QVariant data(int column, int role) const;
    bool setData(int column, const QVariant &value, int role);
    int row() const;
    BasicModelItem* parent();
    void remove();
    void removeChild(BasicModelItem* child);
    bool removeChildren(int position, int count);
    bool setItemData(QList<QList<QVariant> > data);
    void addData(QList<QVariant> dataItem);
    QList<QList<QVariant> > getData();
    void setChildren(QList<BasicModelItem*> children);
    QList<BasicModelItem*> getChildren();
    bool canAcceptDrops();
    void empty(); // clear all children
    QStringList getHeaders();
    void setHeaders(QStringList headers);
    QString getType();
    BasicModelItem* findItem(QVariant value, int column, int role);
protected:
    bool _isComposite;
    bool virtual canAcceptMoreChildren();
    void virtual onChildrenChanged();
    bool virtual canHaveChildren();
    bool _isRoot;
    QList<BasicModelItem*> _children;
    QList<QList<QVariant> > _data;
    BasicModelItem* _parent;
    QStringList _headers;
    QString _type;
signals:
    
public slots:
private:   
};

#endif // BASEMODELITEM_H
