#ifndef HELPERDIALOG_H
#define HELPERDIALOG_H

#include <QDialog>
#include "stdafx.h"
#include "matmodel.h"

namespace Ui {
class HelperDialog;
}

class HelperDialog : public QDialog
{
    Q_OBJECT
    
public:
    explicit HelperDialog(MatModel* disp, MatModel* entropy, QString title = "Test", QWidget *parent = 0);
    ~HelperDialog();
    
private:
    Ui::HelperDialog *ui;
    MatModel* Disp;
};

#endif // HELPERDIALOG_H
