#include "helperdialog.h"
#include "ui_helperdialog.h"

HelperDialog::HelperDialog(MatModel *disp, MatModel *entropy, QString title, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::HelperDialog)
{
    ui->setupUi(this);
    Disp = disp;
    ui->dispertion_table->setModel(Disp);
    this->setWindowTitle(title);
}

HelperDialog::~HelperDialog()
{
    delete ui;
    delete Disp;
}
