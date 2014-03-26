/********************************************************************************
** Form generated from reading UI file 'helperdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.1.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HELPERDIALOG_H
#define UI_HELPERDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QTableView>

QT_BEGIN_NAMESPACE

class Ui_HelperDialog
{
public:
    QHBoxLayout *horizontalLayout;
    QTableView *dispertion_table;

    void setupUi(QDialog *HelperDialog)
    {
        if (HelperDialog->objectName().isEmpty())
            HelperDialog->setObjectName(QStringLiteral("HelperDialog"));
        HelperDialog->setWindowModality(Qt::WindowModal);
        HelperDialog->resize(827, 604);
        horizontalLayout = new QHBoxLayout(HelperDialog);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        dispertion_table = new QTableView(HelperDialog);
        dispertion_table->setObjectName(QStringLiteral("dispertion_table"));

        horizontalLayout->addWidget(dispertion_table);


        retranslateUi(HelperDialog);

        QMetaObject::connectSlotsByName(HelperDialog);
    } // setupUi

    void retranslateUi(QDialog *HelperDialog)
    {
        HelperDialog->setWindowTitle(QApplication::translate("HelperDialog", "Dialog", 0));
    } // retranslateUi

};

namespace Ui {
    class HelperDialog: public Ui_HelperDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HELPERDIALOG_H
