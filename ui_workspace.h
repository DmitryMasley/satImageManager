/********************************************************************************
** Form generated from reading UI file 'workspace.ui'
**
** Created by: Qt User Interface Compiler version 5.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WORKSPACE_H
#define UI_WORKSPACE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include "imagetreeview.h"

QT_BEGIN_NAMESPACE

class Ui_Workspace
{
public:
    QVBoxLayout *verticalLayout;
    QFrame *frame_2;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *workspace_add;
    QPushButton *workspace_remove;
    ImageTreeView *treeView;
    QFrame *frame;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *workspace_ok;
    QPushButton *workspace_cancel;

    void setupUi(QDialog *Workspace)
    {
        if (Workspace->objectName().isEmpty())
            Workspace->setObjectName(QStringLiteral("Workspace"));
        Workspace->resize(458, 563);
        Workspace->setModal(true);
        verticalLayout = new QVBoxLayout(Workspace);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        frame_2 = new QFrame(Workspace);
        frame_2->setObjectName(QStringLiteral("frame_2"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(frame_2->sizePolicy().hasHeightForWidth());
        frame_2->setSizePolicy(sizePolicy);
        frame_2->setMinimumSize(QSize(0, 40));
        frame_2->setFrameShape(QFrame::NoFrame);
        frame_2->setFrameShadow(QFrame::Raised);
        frame_2->setLineWidth(60);
        frame_2->setMidLineWidth(60);
        horizontalLayout = new QHBoxLayout(frame_2);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setSizeConstraint(QLayout::SetDefaultConstraint);
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        workspace_add = new QPushButton(frame_2);
        workspace_add->setObjectName(QStringLiteral("workspace_add"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(workspace_add->sizePolicy().hasHeightForWidth());
        workspace_add->setSizePolicy(sizePolicy1);

        horizontalLayout->addWidget(workspace_add);

        workspace_remove = new QPushButton(frame_2);
        workspace_remove->setObjectName(QStringLiteral("workspace_remove"));
        sizePolicy1.setHeightForWidth(workspace_remove->sizePolicy().hasHeightForWidth());
        workspace_remove->setSizePolicy(sizePolicy1);

        horizontalLayout->addWidget(workspace_remove);


        verticalLayout->addWidget(frame_2);

        treeView = new ImageTreeView(Workspace);
        treeView->setObjectName(QStringLiteral("treeView"));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(1);
        sizePolicy2.setHeightForWidth(treeView->sizePolicy().hasHeightForWidth());
        treeView->setSizePolicy(sizePolicy2);

        verticalLayout->addWidget(treeView);

        frame = new QFrame(Workspace);
        frame->setObjectName(QStringLiteral("frame"));
        sizePolicy.setHeightForWidth(frame->sizePolicy().hasHeightForWidth());
        frame->setSizePolicy(sizePolicy);
        frame->setMinimumSize(QSize(0, 40));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        frame->setLineWidth(10);
        frame->setMidLineWidth(10);
        horizontalLayout_2 = new QHBoxLayout(frame);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);

        workspace_ok = new QPushButton(frame);
        workspace_ok->setObjectName(QStringLiteral("workspace_ok"));
        sizePolicy1.setHeightForWidth(workspace_ok->sizePolicy().hasHeightForWidth());
        workspace_ok->setSizePolicy(sizePolicy1);

        horizontalLayout_2->addWidget(workspace_ok);

        workspace_cancel = new QPushButton(frame);
        workspace_cancel->setObjectName(QStringLiteral("workspace_cancel"));
        sizePolicy1.setHeightForWidth(workspace_cancel->sizePolicy().hasHeightForWidth());
        workspace_cancel->setSizePolicy(sizePolicy1);

        horizontalLayout_2->addWidget(workspace_cancel);


        verticalLayout->addWidget(frame);


        retranslateUi(Workspace);

        QMetaObject::connectSlotsByName(Workspace);
    } // setupUi

    void retranslateUi(QDialog *Workspace)
    {
        Workspace->setWindowTitle(QApplication::translate("Workspace", "Dialog", 0));
        workspace_add->setText(QApplication::translate("Workspace", "Open a File", 0));
        workspace_remove->setText(QApplication::translate("Workspace", "Remove", 0));
        workspace_ok->setText(QApplication::translate("Workspace", "Ok", 0));
        workspace_cancel->setText(QApplication::translate("Workspace", "Cancel", 0));
    } // retranslateUi

};

namespace Ui {
    class Workspace: public Ui_Workspace {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WORKSPACE_H
