#ifndef WORKSPACE_H
#define WORKSPACE_H

#include <QDialog>

namespace Ui {
class Workspace;
}

class Workspace : public QDialog
{
    Q_OBJECT

public:
    explicit Workspace(QWidget *parent = 0);
    ~Workspace();

private:
    Ui::Workspace *ui;
};

#endif // WORKSPACE_H
