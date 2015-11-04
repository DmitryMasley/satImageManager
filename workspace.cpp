#include "workspace.h"
#include "ui_workspace.h"

Workspace::Workspace(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Workspace)
{
    ui->setupUi(this);
}

Workspace::~Workspace()
{
    delete ui;
}
