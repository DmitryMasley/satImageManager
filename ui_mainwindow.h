/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QLocale>
#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableView>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "basiclistview.h"
#include "basictreeview.h"
#include "characteristicstable.h"
#include "imagetreeview.h"
#include "previewgraphicsview.h"
#include "slidingstackedwidget.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionRemove;
    QAction *actionAdd;
    QAction *actionPreview;
    QWidget *centralWidget;
    QGridLayout *gridLayout_3;
    QFrame *line;
    QTabWidget *operations;
    QWidget *preview_tab;
    QGridLayout *gridLayout_2;
    previewGraphicsView *previewArea;
    QWidget *characteristics_tab;
    QGridLayout *gridLayout_12;
    QGroupBox *groupBox_4;
    QHBoxLayout *horizontalLayout_2;
    BasicListView *ChrList;
    QGroupBox *groupBox_5;
    QHBoxLayout *horizontalLayout_3;
    CharacteristicsTable *ChResultsTable;
    QPushButton *evaluateParams;
    QSpacerItem *horizontalSpacer_4;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *saveParams;
    QWidget *image_fusion;
    QGridLayout *gridLayout_5;
    QGroupBox *groupBox_2;
    QFormLayout *formLayout_2;
    QPushButton *IF_set_pan;
    BasicListView *IF_pan_list;
    QCheckBox *IF_use_normalization;
    QPushButton *IF_start;
    QSpinBox *IF_windowSize;
    QGroupBox *groupBox_3;
    QGridLayout *gridLayout_6;
    QPushButton *IF_save;
    QPushButton *IF_preview;
    BasicTreeView *IF_results_list;
    QPushButton *IF_add_color_image;
    QGroupBox *groupBox_10;
    QComboBox *IF_orthogonalization_type;
    QGroupBox *groupBox;
    QGridLayout *gridLayout_4;
    QPushButton *IF_remove_from_source_list;
    QPushButton *IF_add_selected_to_list;
    BasicListView *IF_sourses_list;
    QWidget *satelite_image_filter;
    QGridLayout *gridLayout_7;
    QFrame *frame;
    QGridLayout *gridLayout_8;
    QPushButton *filter_set_current_image;
    QSpacerItem *horizontalSpacer_7;
    QPushButton *filter_start;
    previewGraphicsView *filter_source_view;
    previewGraphicsView *filter_result_view;
    QGroupBox *filter_controls;
    QFrame *frame_2;
    QFormLayout *formLayout;
    QLabel *label;
    QDoubleSpinBox *filter_lens_radius;
    QLabel *label_2;
    QDoubleSpinBox *filter_os_width;
    QLabel *label_3;
    QDoubleSpinBox *filter_wavelength;
    QLabel *dpi_label;
    QDoubleSpinBox *matrix_dpi;
    QSpacerItem *horizontalSpacer_5;
    QPushButton *filter_save;
    QWidget *multispecrum_images;
    QGridLayout *gridLayout_14;
    QGroupBox *groupBox_8;
    QGridLayout *gridLayout_13;
    QPushButton *MI_addColorImage;
    BasicTreeView *MI_TreeView;
    QPushButton *MI_preview;
    QPushButton *MI_save;
    QWidget *comparative_characteristics;
    QHBoxLayout *horizontalLayout_6;
    QPushButton *comp_char_widget_prev;
    SlidingStackedWidget *comp_char_widget;
    QWidget *page;
    QGridLayout *gridLayout_16;
    QFrame *frame_5;
    QVBoxLayout *verticalLayout_2;
    QGroupBox *groupBox_11;
    QGridLayout *gridLayout;
    QPushButton *comp_char_set_img1;
    previewGraphicsView *comp_char_img1_view;
    QGroupBox *groupBox_12;
    QGridLayout *gridLayout_9;
    QPushButton *comp_char_set_img2;
    previewGraphicsView *comp_char_img2_view;
    QWidget *page_2;
    QHBoxLayout *horizontalLayout_5;
    QGroupBox *groupBox_6;
    QHBoxLayout *horizontalLayout_4;
    BasicListView *comp_char_list;
    QGroupBox *groupBox_7;
    QSpinBox *spinBox;
    QWidget *page_3;
    QVBoxLayout *verticalLayout;
    QGroupBox *comp_char_ssim_map_container;
    QGridLayout *gridLayout_10;
    QPushButton *comp_char_ssim_map_save;
    QSpacerItem *horizontalSpacer;
    previewGraphicsView *comp_char_ssim_map;
    QGroupBox *groupBox_9;
    QGridLayout *gridLayout_11;
    QPushButton *comp_char_results_table_save;
    QSpacerItem *horizontalSpacer_2;
    QTableView *comp_char_results_table;
    QPushButton *comp_char_widget_next;
    QWidget *contours;
    QGridLayout *gridLayout_15;
    QFrame *frame_3;
    QHBoxLayout *horizontalLayout;
    QLabel *label_4;
    QComboBox *edge_detection_type;
    QPushButton *edge_get;
    QFrame *frame_4;
    previewGraphicsView *edges_source;
    ImageTreeView *mainTreeView;
    QMenuBar *menuBar;
    QMenu *menu_file;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1052, 715);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        MainWindow->setMinimumSize(QSize(750, 550));
        MainWindow->setCursor(QCursor(Qt::ArrowCursor));
        QIcon icon;
        icon.addFile(QStringLiteral(":/resource/icons/images/icons.png"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindow->setWindowIcon(icon);
        MainWindow->setStyleSheet(QLatin1String("MainWindow\n"
"{\n"
"\n"
"}\n"
"#comp_char_widget_prev {\n"
"	font: 20pt \"FontAwesome\";\n"
"}\n"
"#comp_char_widget_next {\n"
"	font: 20pt \"FontAwesome\";\n"
"}\n"
"MainWindow QGroupBox\n"
"{\n"
"	border:1px solid rgb(120, 120, 120);\n"
"	border-radius:3px;	\n"
"	margin-top: 3ex;	\n"
"}\n"
"MainWindow QGroupBox::title\n"
"{\n"
"	subcontrol-origin: margin;\n"
"    subcontrol-position: top center;\n"
"}\n"
"MainWindow QProgressBar \n"
"{	\n"
"	color:white;\n"
"	background:qlineargradient(spread:pad, x1:1, y1:0, x2:1, y2:1, stop:0 rgba(186, 62, 0, 255), stop:1 rgba(255, 80, 0, 255));\n"
"	font-weight:bold;\n"
"	border:2px solid rgb(120, 120, 120);\n"
"	border-radius:3px;	\n"
"}\n"
"MainWindow QProgressBar::chunk \n"
"{	\n"
"	background:qlineargradient(spread:pad, x1:1, y1:1, x2:1, y2:0, stop:0 rgba(51, 98, 141, 255), stop:1 rgba(93, 155, 218, 255));\n"
"}\n"
"MainWindow QListView, QTableView, QTreeView\n"
"{\n"
"	border:2px solid rgb(120, 120, 120);\n"
"	border-radius:0px;	\n"
"}\n"
"MainWindow QListView:focus"
                        ", QTableView:focus, QTreeView:focus\n"
"{\n"
"	border-color:rgb(53, 106, 159);\n"
"	border-style:outset;\n"
"	\n"
"}\n"
"MainWindow QListView:blur, QTableView:blur, QTreeView:blur::item:selected\n"
"{\n"
"	color:white;	\n"
"}\n"
"MainWindow QListView::item, QTreeView::item,  QTableView::item\n"
"{	\n"
"	padding:4px;\n"
"}\n"
"MainWindow QListView::item::hover:!selected, QTreeView::item::hover:!selected\n"
"{\n"
"	color:white;\n"
"background:qlineargradient(spread:pad, x1:1, y1:1, x2:1, y2:0, stop:0 rgba(51, 98, 141, 255), stop:1 rgba(93, 155, 218, 255));\n"
"}\n"
"MainWindow QListView::item, QTreeView::item\n"
"{\n"
"	background : qlineargradient(spread:pad, x1:1, y1:1, x2:1, y2:0, stop:0 rgba(120, 120, 120, 255), stop:1 rgba(147, 147, 147, 255));\n"
"	border-bottom:1px solid rgb(255, 255, 255);\n"
"	color:white;\n"
"}\n"
"MainWindow QListView::item:selected, QTreeView::item:selected\n"
"{\n"
"	background:qlineargradient(spread:pad, x1:1, y1:0, x2:1, y2:1, stop:0 rgba(186, 62, 0, 255), stop:1 rgba(255, 80, 0, "
                        "255));\n"
"	color:white;\n"
"}\n"
"MainWindow QPushButton, QToolButton \n"
"{\n"
"	color:white;\n"
"	padding:10px 15px;	\n"
"	border:1px solid rgb(89, 89, 89);	\n"
"	background-color: qlineargradient(spread:pad, x1:1, y1:1, x2:1, y2:0, stop:0 rgba(100, 100, 100, 255), stop:1 rgba(127, 127, 127, 255));\n"
"	border-radius:2px;\n"
"}\n"
"MainWindow  QPushButton:hover:!pressed, QToolButton:hover:!pressed\n"
"{\n"
"	color:white;\n"
"	background:qlineargradient(spread:pad, x1:1, y1:1, x2:1, y2:0, stop:0 rgba(51, 98, 141, 255), stop:1 rgba(93, 155, 218, 255));\n"
"	border:1px solid rgb(100, 100, 100);\n"
"}\n"
"MainWindow  QPushButton:hover:pressed,  QToolButton:hover:pressed\n"
"{\n"
"	color:white;\n"
"	border-color:rgb(36, 70, 100);\n"
"	background:qlineargradient(spread:pad, x1:1, y1:0, x2:1, y2:1, stop:0 rgba(186, 62, 0, 255), stop:1 rgba(255, 80, 0, 255));\n"
"	border-style: inset;\n"
"}\n"
"MainWindow QTabBar::tab\n"
"{\n"
"	padding:10px;\n"
"	color:white;\n"
"	background: qlineargradient(spread:pad, x1:1, y1:1"
                        ", x2:1, y2:0, stop:0 rgba(120, 120, 120, 255), stop:1 rgba(147, 147, 147, 255));\n"
"	border:1px solid rgb(255, 255, 255);\n"
"}\n"
"MainWindow QTabBar::tab:hover:!selected\n"
"{\n"
"	background:qlineargradient(spread:pad, x1:1, y1:1, x2:1, y2:0, stop:0 rgba(51, 98, 141, 255), stop:1 rgba(93, 155, 218, 255));\n"
"	border:1px solid rgb(100, 100, 100)\n"
"}\n"
"MainWindow QTabBar::tab:selected\n"
"{\n"
"	background:qlineargradient(spread:pad, x1:1, y1:0, x2:1, y2:1, stop:0 rgba(186, 62, 0, 255), stop:1 rgba(255, 80, 0, 255));\n"
"	border:1px solid rgb(43, 90, 131);\n"
"}\n"
"MainWindow QToolTip\n"
"{\n"
"	border:1px solid rgb(53, 106, 159);\n"
"	color: rgb(53, 106, 159);	\n"
"	font-weight:bold;\n"
"	background-color: rgb(216, 232, 255);\n"
"}\n"
"MainWindow QButton {\n"
"	min-height:30px;\n"
"}"));
        MainWindow->setDockNestingEnabled(true);
        MainWindow->setDockOptions(QMainWindow::AllowNestedDocks|QMainWindow::AllowTabbedDocks|QMainWindow::AnimatedDocks|QMainWindow::ForceTabbedDocks);
        MainWindow->setUnifiedTitleAndToolBarOnMac(true);
        actionRemove = new QAction(MainWindow);
        actionRemove->setObjectName(QStringLiteral("actionRemove"));
        actionRemove->setCheckable(false);
        actionRemove->setEnabled(true);
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/resource/icons/images/Delete-icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionRemove->setIcon(icon1);
        actionAdd = new QAction(MainWindow);
        actionAdd->setObjectName(QStringLiteral("actionAdd"));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/resource/icons/images/Add-icon (1).png"), QSize(), QIcon::Normal, QIcon::Off);
        actionAdd->setIcon(icon2);
        actionPreview = new QAction(MainWindow);
        actionPreview->setObjectName(QStringLiteral("actionPreview"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayout_3 = new QGridLayout(centralWidget);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        line = new QFrame(centralWidget);
        line->setObjectName(QStringLiteral("line"));
        line->setFrameShape(QFrame::VLine);
        line->setFrameShadow(QFrame::Sunken);

        gridLayout_3->addWidget(line, 0, 2, 1, 1);

        operations = new QTabWidget(centralWidget);
        operations->setObjectName(QStringLiteral("operations"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::MinimumExpanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(2);
        sizePolicy1.setHeightForWidth(operations->sizePolicy().hasHeightForWidth());
        operations->setSizePolicy(sizePolicy1);
        operations->setLocale(QLocale(QLocale::English, QLocale::UnitedStates));
        operations->setTabPosition(QTabWidget::North);
        operations->setTabShape(QTabWidget::Triangular);
        operations->setElideMode(Qt::ElideNone);
        preview_tab = new QWidget();
        preview_tab->setObjectName(QStringLiteral("preview_tab"));
        gridLayout_2 = new QGridLayout(preview_tab);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        previewArea = new previewGraphicsView(preview_tab);
        previewArea->setObjectName(QStringLiteral("previewArea"));
        QBrush brush(QColor(43, 90, 131, 255));
        brush.setStyle(Qt::SolidPattern);
        previewArea->setBackgroundBrush(brush);
        QBrush brush1(QColor(0, 0, 0, 255));
        brush1.setStyle(Qt::NoBrush);
        previewArea->setForegroundBrush(brush1);
        previewArea->setAlignment(Qt::AlignJustify|Qt::AlignVCenter);
        previewArea->setDragMode(QGraphicsView::ScrollHandDrag);
        previewArea->setResizeAnchor(QGraphicsView::AnchorUnderMouse);
        previewArea->setViewportUpdateMode(QGraphicsView::FullViewportUpdate);

        gridLayout_2->addWidget(previewArea, 0, 0, 1, 1);

        operations->addTab(preview_tab, QString());
        characteristics_tab = new QWidget();
        characteristics_tab->setObjectName(QStringLiteral("characteristics_tab"));
        gridLayout_12 = new QGridLayout(characteristics_tab);
        gridLayout_12->setSpacing(6);
        gridLayout_12->setContentsMargins(11, 11, 11, 11);
        gridLayout_12->setObjectName(QStringLiteral("gridLayout_12"));
        groupBox_4 = new QGroupBox(characteristics_tab);
        groupBox_4->setObjectName(QStringLiteral("groupBox_4"));
        groupBox_4->setAlignment(Qt::AlignCenter);
        horizontalLayout_2 = new QHBoxLayout(groupBox_4);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        ChrList = new BasicListView(groupBox_4);
        ChrList->setObjectName(QStringLiteral("ChrList"));
        ChrList->setEditTriggers(QAbstractItemView::NoEditTriggers);
        ChrList->setTabKeyNavigation(true);
        ChrList->setSelectionMode(QAbstractItemView::MultiSelection);
        ChrList->setIconSize(QSize(20, 20));
        ChrList->setFlow(QListView::TopToBottom);
        ChrList->setViewMode(QListView::ListMode);

        horizontalLayout_2->addWidget(ChrList);


        gridLayout_12->addWidget(groupBox_4, 0, 0, 1, 2);

        groupBox_5 = new QGroupBox(characteristics_tab);
        groupBox_5->setObjectName(QStringLiteral("groupBox_5"));
        groupBox_5->setAlignment(Qt::AlignCenter);
        horizontalLayout_3 = new QHBoxLayout(groupBox_5);
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        ChResultsTable = new CharacteristicsTable(groupBox_5);
        ChResultsTable->setObjectName(QStringLiteral("ChResultsTable"));
        ChResultsTable->setMinimumSize(QSize(0, 0));
        ChResultsTable->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        ChResultsTable->setEditTriggers(QAbstractItemView::NoEditTriggers);
        ChResultsTable->setAlternatingRowColors(true);
        ChResultsTable->setSelectionBehavior(QAbstractItemView::SelectRows);
        ChResultsTable->setHorizontalScrollMode(QAbstractItemView::ScrollPerPixel);
        ChResultsTable->setSortingEnabled(true);
        ChResultsTable->horizontalHeader()->setCascadingSectionResizes(true);
        ChResultsTable->horizontalHeader()->setDefaultSectionSize(100);
        ChResultsTable->horizontalHeader()->setMinimumSectionSize(100);
        ChResultsTable->horizontalHeader()->setProperty("showSortIndicator", QVariant(true));
        ChResultsTable->horizontalHeader()->setStretchLastSection(true);
        ChResultsTable->verticalHeader()->setCascadingSectionResizes(true);
        ChResultsTable->verticalHeader()->setDefaultSectionSize(36);
        ChResultsTable->verticalHeader()->setMinimumSectionSize(36);
        ChResultsTable->verticalHeader()->setProperty("showSortIndicator", QVariant(false));
        ChResultsTable->verticalHeader()->setStretchLastSection(false);

        horizontalLayout_3->addWidget(ChResultsTable);


        gridLayout_12->addWidget(groupBox_5, 0, 2, 1, 2);

        evaluateParams = new QPushButton(characteristics_tab);
        evaluateParams->setObjectName(QStringLiteral("evaluateParams"));
        QSizePolicy sizePolicy2(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(1);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(evaluateParams->sizePolicy().hasHeightForWidth());
        evaluateParams->setSizePolicy(sizePolicy2);
        evaluateParams->setMinimumSize(QSize(0, 0));
        evaluateParams->setMaximumSize(QSize(16777215, 16777215));
        evaluateParams->setSizeIncrement(QSize(0, 0));
        evaluateParams->setBaseSize(QSize(0, 0));
        evaluateParams->setLayoutDirection(Qt::LeftToRight);

        gridLayout_12->addWidget(evaluateParams, 1, 0, 1, 1);

        horizontalSpacer_4 = new QSpacerItem(260, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_12->addItem(horizontalSpacer_4, 1, 1, 1, 1);

        horizontalSpacer_3 = new QSpacerItem(260, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_12->addItem(horizontalSpacer_3, 1, 2, 1, 1);

        saveParams = new QPushButton(characteristics_tab);
        saveParams->setObjectName(QStringLiteral("saveParams"));
        sizePolicy2.setHeightForWidth(saveParams->sizePolicy().hasHeightForWidth());
        saveParams->setSizePolicy(sizePolicy2);

        gridLayout_12->addWidget(saveParams, 1, 3, 1, 1);

        operations->addTab(characteristics_tab, QString());
        image_fusion = new QWidget();
        image_fusion->setObjectName(QStringLiteral("image_fusion"));
        gridLayout_5 = new QGridLayout(image_fusion);
        gridLayout_5->setSpacing(6);
        gridLayout_5->setContentsMargins(11, 11, 11, 11);
        gridLayout_5->setObjectName(QStringLiteral("gridLayout_5"));
        groupBox_2 = new QGroupBox(image_fusion);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        QSizePolicy sizePolicy3(QSizePolicy::Preferred, QSizePolicy::Expanding);
        sizePolicy3.setHorizontalStretch(1);
        sizePolicy3.setVerticalStretch(4);
        sizePolicy3.setHeightForWidth(groupBox_2->sizePolicy().hasHeightForWidth());
        groupBox_2->setSizePolicy(sizePolicy3);
        groupBox_2->setMinimumSize(QSize(0, 80));
        groupBox_2->setMaximumSize(QSize(16777215, 80));
        groupBox_2->setAlignment(Qt::AlignCenter);
        formLayout_2 = new QFormLayout(groupBox_2);
        formLayout_2->setSpacing(6);
        formLayout_2->setContentsMargins(11, 11, 11, 11);
        formLayout_2->setObjectName(QStringLiteral("formLayout_2"));
        formLayout_2->setFieldGrowthPolicy(QFormLayout::AllNonFixedFieldsGrow);
        IF_set_pan = new QPushButton(groupBox_2);
        IF_set_pan->setObjectName(QStringLiteral("IF_set_pan"));
        QSizePolicy sizePolicy4(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy4.setHorizontalStretch(1);
        sizePolicy4.setVerticalStretch(1);
        sizePolicy4.setHeightForWidth(IF_set_pan->sizePolicy().hasHeightForWidth());
        IF_set_pan->setSizePolicy(sizePolicy4);
        IF_set_pan->setMinimumSize(QSize(0, 50));
        IF_set_pan->setMaximumSize(QSize(16777215, 50));

        formLayout_2->setWidget(0, QFormLayout::LabelRole, IF_set_pan);

        IF_pan_list = new BasicListView(groupBox_2);
        IF_pan_list->setObjectName(QStringLiteral("IF_pan_list"));
        IF_pan_list->setEnabled(true);
        QSizePolicy sizePolicy5(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy5.setHorizontalStretch(2);
        sizePolicy5.setVerticalStretch(1);
        sizePolicy5.setHeightForWidth(IF_pan_list->sizePolicy().hasHeightForWidth());
        IF_pan_list->setSizePolicy(sizePolicy5);
        IF_pan_list->setMinimumSize(QSize(0, 50));
        IF_pan_list->setMaximumSize(QSize(16777215, 50));
        IF_pan_list->setSelectionMode(QAbstractItemView::NoSelection);
        IF_pan_list->setIconSize(QSize(40, 40));
        IF_pan_list->setGridSize(QSize(40, 40));

        formLayout_2->setWidget(0, QFormLayout::FieldRole, IF_pan_list);


        gridLayout_5->addWidget(groupBox_2, 2, 0, 1, 1);

        IF_use_normalization = new QCheckBox(image_fusion);
        IF_use_normalization->setObjectName(QStringLiteral("IF_use_normalization"));
        QSizePolicy sizePolicy6(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy6.setHorizontalStretch(1);
        sizePolicy6.setVerticalStretch(0);
        sizePolicy6.setHeightForWidth(IF_use_normalization->sizePolicy().hasHeightForWidth());
        IF_use_normalization->setSizePolicy(sizePolicy6);

        gridLayout_5->addWidget(IF_use_normalization, 4, 0, 1, 1);

        IF_start = new QPushButton(image_fusion);
        IF_start->setObjectName(QStringLiteral("IF_start"));
        sizePolicy.setHeightForWidth(IF_start->sizePolicy().hasHeightForWidth());
        IF_start->setSizePolicy(sizePolicy);
        IF_start->setAutoRepeat(true);
        IF_start->setAutoExclusive(true);

        gridLayout_5->addWidget(IF_start, 5, 0, 1, 1);

        IF_windowSize = new QSpinBox(image_fusion);
        IF_windowSize->setObjectName(QStringLiteral("IF_windowSize"));
        sizePolicy6.setHeightForWidth(IF_windowSize->sizePolicy().hasHeightForWidth());
        IF_windowSize->setSizePolicy(sizePolicy6);

        gridLayout_5->addWidget(IF_windowSize, 3, 0, 1, 1);

        groupBox_3 = new QGroupBox(image_fusion);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        QSizePolicy sizePolicy7(QSizePolicy::Preferred, QSizePolicy::Expanding);
        sizePolicy7.setHorizontalStretch(1);
        sizePolicy7.setVerticalStretch(2);
        sizePolicy7.setHeightForWidth(groupBox_3->sizePolicy().hasHeightForWidth());
        groupBox_3->setSizePolicy(sizePolicy7);
        groupBox_3->setAlignment(Qt::AlignCenter);
        gridLayout_6 = new QGridLayout(groupBox_3);
        gridLayout_6->setSpacing(6);
        gridLayout_6->setContentsMargins(11, 11, 11, 11);
        gridLayout_6->setObjectName(QStringLiteral("gridLayout_6"));
        IF_save = new QPushButton(groupBox_3);
        IF_save->setObjectName(QStringLiteral("IF_save"));
        sizePolicy.setHeightForWidth(IF_save->sizePolicy().hasHeightForWidth());
        IF_save->setSizePolicy(sizePolicy);

        gridLayout_6->addWidget(IF_save, 2, 2, 1, 1);

        IF_preview = new QPushButton(groupBox_3);
        IF_preview->setObjectName(QStringLiteral("IF_preview"));
        sizePolicy.setHeightForWidth(IF_preview->sizePolicy().hasHeightForWidth());
        IF_preview->setSizePolicy(sizePolicy);

        gridLayout_6->addWidget(IF_preview, 2, 1, 1, 1);

        IF_results_list = new BasicTreeView(groupBox_3);
        IF_results_list->setObjectName(QStringLiteral("IF_results_list"));
        QSizePolicy sizePolicy8(QSizePolicy::MinimumExpanding, QSizePolicy::Expanding);
        sizePolicy8.setHorizontalStretch(0);
        sizePolicy8.setVerticalStretch(0);
        sizePolicy8.setHeightForWidth(IF_results_list->sizePolicy().hasHeightForWidth());
        IF_results_list->setSizePolicy(sizePolicy8);
        IF_results_list->setDragEnabled(true);
        IF_results_list->setDragDropOverwriteMode(false);
        IF_results_list->setDragDropMode(QAbstractItemView::InternalMove);
        IF_results_list->setDefaultDropAction(Qt::MoveAction);
        IF_results_list->setIconSize(QSize(40, 40));
        IF_results_list->setAutoExpandDelay(500);
        IF_results_list->setIndentation(20);
        IF_results_list->setAnimated(true);
        IF_results_list->header()->setVisible(false);
        IF_results_list->header()->setCascadingSectionResizes(false);
        IF_results_list->header()->setDefaultSectionSize(200);
        IF_results_list->header()->setStretchLastSection(true);

        gridLayout_6->addWidget(IF_results_list, 1, 0, 1, 3);

        IF_add_color_image = new QPushButton(groupBox_3);
        IF_add_color_image->setObjectName(QStringLiteral("IF_add_color_image"));

        gridLayout_6->addWidget(IF_add_color_image, 0, 0, 1, 1);


        gridLayout_5->addWidget(groupBox_3, 0, 2, 6, 1);

        groupBox_10 = new QGroupBox(image_fusion);
        groupBox_10->setObjectName(QStringLiteral("groupBox_10"));
        QSizePolicy sizePolicy9(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy9.setHorizontalStretch(0);
        sizePolicy9.setVerticalStretch(0);
        sizePolicy9.setHeightForWidth(groupBox_10->sizePolicy().hasHeightForWidth());
        groupBox_10->setSizePolicy(sizePolicy9);
        IF_orthogonalization_type = new QComboBox(groupBox_10);
        IF_orthogonalization_type->addItem(QStringLiteral("QR "));
        IF_orthogonalization_type->addItem(QString());
        IF_orthogonalization_type->setObjectName(QStringLiteral("IF_orthogonalization_type"));
        IF_orthogonalization_type->setGeometry(QRect(16, 23, 45, 20));

        gridLayout_5->addWidget(groupBox_10, 0, 0, 1, 1);

        groupBox = new QGroupBox(image_fusion);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setEnabled(true);
        QSizePolicy sizePolicy10(QSizePolicy::Preferred, QSizePolicy::Expanding);
        sizePolicy10.setHorizontalStretch(1);
        sizePolicy10.setVerticalStretch(15);
        sizePolicy10.setHeightForWidth(groupBox->sizePolicy().hasHeightForWidth());
        groupBox->setSizePolicy(sizePolicy10);
        groupBox->setAlignment(Qt::AlignCenter);
        gridLayout_4 = new QGridLayout(groupBox);
        gridLayout_4->setSpacing(6);
        gridLayout_4->setContentsMargins(11, 11, 11, 11);
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        IF_remove_from_source_list = new QPushButton(groupBox);
        IF_remove_from_source_list->setObjectName(QStringLiteral("IF_remove_from_source_list"));
        QSizePolicy sizePolicy11(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy11.setHorizontalStretch(1);
        sizePolicy11.setVerticalStretch(1);
        sizePolicy11.setHeightForWidth(IF_remove_from_source_list->sizePolicy().hasHeightForWidth());
        IF_remove_from_source_list->setSizePolicy(sizePolicy11);

        gridLayout_4->addWidget(IF_remove_from_source_list, 0, 1, 1, 1);

        IF_add_selected_to_list = new QPushButton(groupBox);
        IF_add_selected_to_list->setObjectName(QStringLiteral("IF_add_selected_to_list"));
        sizePolicy11.setHeightForWidth(IF_add_selected_to_list->sizePolicy().hasHeightForWidth());
        IF_add_selected_to_list->setSizePolicy(sizePolicy11);

        gridLayout_4->addWidget(IF_add_selected_to_list, 0, 0, 1, 1);

        IF_sourses_list = new BasicListView(groupBox);
        IF_sourses_list->setObjectName(QStringLiteral("IF_sourses_list"));
        QSizePolicy sizePolicy12(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy12.setHorizontalStretch(0);
        sizePolicy12.setVerticalStretch(5);
        sizePolicy12.setHeightForWidth(IF_sourses_list->sizePolicy().hasHeightForWidth());
        IF_sourses_list->setSizePolicy(sizePolicy12);
        IF_sourses_list->setMinimumSize(QSize(25, 25));
        IF_sourses_list->setBaseSize(QSize(25, 25));
        IF_sourses_list->setDragDropMode(QAbstractItemView::DropOnly);
        IF_sourses_list->setAlternatingRowColors(true);
        IF_sourses_list->setIconSize(QSize(40, 40));

        gridLayout_4->addWidget(IF_sourses_list, 1, 0, 1, 2);


        gridLayout_5->addWidget(groupBox, 1, 0, 1, 1);

        operations->addTab(image_fusion, QString());
        satelite_image_filter = new QWidget();
        satelite_image_filter->setObjectName(QStringLiteral("satelite_image_filter"));
        gridLayout_7 = new QGridLayout(satelite_image_filter);
        gridLayout_7->setSpacing(6);
        gridLayout_7->setContentsMargins(11, 11, 11, 11);
        gridLayout_7->setObjectName(QStringLiteral("gridLayout_7"));
        frame = new QFrame(satelite_image_filter);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        gridLayout_8 = new QGridLayout(frame);
        gridLayout_8->setSpacing(6);
        gridLayout_8->setContentsMargins(11, 11, 11, 11);
        gridLayout_8->setObjectName(QStringLiteral("gridLayout_8"));
        filter_set_current_image = new QPushButton(frame);
        filter_set_current_image->setObjectName(QStringLiteral("filter_set_current_image"));
        QSizePolicy sizePolicy13(QSizePolicy::Fixed, QSizePolicy::Expanding);
        sizePolicy13.setHorizontalStretch(0);
        sizePolicy13.setVerticalStretch(0);
        sizePolicy13.setHeightForWidth(filter_set_current_image->sizePolicy().hasHeightForWidth());
        filter_set_current_image->setSizePolicy(sizePolicy13);
        filter_set_current_image->setMaximumSize(QSize(16777215, 16777215));

        gridLayout_8->addWidget(filter_set_current_image, 0, 0, 1, 1);

        horizontalSpacer_7 = new QSpacerItem(290, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_8->addItem(horizontalSpacer_7, 0, 1, 1, 1);

        filter_start = new QPushButton(frame);
        filter_start->setObjectName(QStringLiteral("filter_start"));
        QSizePolicy sizePolicy14(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy14.setHorizontalStretch(2);
        sizePolicy14.setVerticalStretch(0);
        sizePolicy14.setHeightForWidth(filter_start->sizePolicy().hasHeightForWidth());
        filter_start->setSizePolicy(sizePolicy14);

        gridLayout_8->addWidget(filter_start, 0, 2, 1, 1);

        filter_source_view = new previewGraphicsView(frame);
        filter_source_view->setObjectName(QStringLiteral("filter_source_view"));
        QSizePolicy sizePolicy15(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy15.setHorizontalStretch(2);
        sizePolicy15.setVerticalStretch(2);
        sizePolicy15.setHeightForWidth(filter_source_view->sizePolicy().hasHeightForWidth());
        filter_source_view->setSizePolicy(sizePolicy15);
        filter_source_view->setBackgroundBrush(brush);

        gridLayout_8->addWidget(filter_source_view, 1, 0, 1, 1);

        filter_result_view = new previewGraphicsView(frame);
        filter_result_view->setObjectName(QStringLiteral("filter_result_view"));
        sizePolicy15.setHeightForWidth(filter_result_view->sizePolicy().hasHeightForWidth());
        filter_result_view->setSizePolicy(sizePolicy15);
        filter_result_view->setBackgroundBrush(brush);

        gridLayout_8->addWidget(filter_result_view, 1, 1, 1, 2);

        filter_controls = new QGroupBox(frame);
        filter_controls->setObjectName(QStringLiteral("filter_controls"));
        QSizePolicy sizePolicy16(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy16.setHorizontalStretch(4);
        sizePolicy16.setVerticalStretch(1);
        sizePolicy16.setHeightForWidth(filter_controls->sizePolicy().hasHeightForWidth());
        filter_controls->setSizePolicy(sizePolicy16);
        filter_controls->setMinimumSize(QSize(0, 200));
        frame_2 = new QFrame(filter_controls);
        frame_2->setObjectName(QStringLiteral("frame_2"));
        frame_2->setGeometry(QRect(0, 10, 341, 181));
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        formLayout = new QFormLayout(frame_2);
        formLayout->setSpacing(6);
        formLayout->setContentsMargins(11, 11, 11, 11);
        formLayout->setObjectName(QStringLiteral("formLayout"));
        formLayout->setFieldGrowthPolicy(QFormLayout::AllNonFixedFieldsGrow);
        label = new QLabel(frame_2);
        label->setObjectName(QStringLiteral("label"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label);

        filter_lens_radius = new QDoubleSpinBox(frame_2);
        filter_lens_radius->setObjectName(QStringLiteral("filter_lens_radius"));
        filter_lens_radius->setDecimals(2);
        filter_lens_radius->setMaximum(1e+09);
        filter_lens_radius->setValue(77.5);

        formLayout->setWidget(0, QFormLayout::FieldRole, filter_lens_radius);

        label_2 = new QLabel(frame_2);
        label_2->setObjectName(QStringLiteral("label_2"));

        formLayout->setWidget(1, QFormLayout::LabelRole, label_2);

        filter_os_width = new QDoubleSpinBox(frame_2);
        filter_os_width->setObjectName(QStringLiteral("filter_os_width"));
        filter_os_width->setDecimals(2);
        filter_os_width->setMaximum(1e+09);
        filter_os_width->setValue(860);

        formLayout->setWidget(1, QFormLayout::FieldRole, filter_os_width);

        label_3 = new QLabel(frame_2);
        label_3->setObjectName(QStringLiteral("label_3"));

        formLayout->setWidget(2, QFormLayout::LabelRole, label_3);

        filter_wavelength = new QDoubleSpinBox(frame_2);
        filter_wavelength->setObjectName(QStringLiteral("filter_wavelength"));
        filter_wavelength->setDecimals(2);
        filter_wavelength->setMaximum(1e+09);
        filter_wavelength->setValue(400);

        formLayout->setWidget(2, QFormLayout::FieldRole, filter_wavelength);

        dpi_label = new QLabel(frame_2);
        dpi_label->setObjectName(QStringLiteral("dpi_label"));

        formLayout->setWidget(3, QFormLayout::LabelRole, dpi_label);

        matrix_dpi = new QDoubleSpinBox(frame_2);
        matrix_dpi->setObjectName(QStringLiteral("matrix_dpi"));
        matrix_dpi->setDecimals(0);
        matrix_dpi->setMaximum(1e+09);
        matrix_dpi->setSingleStep(100);
        matrix_dpi->setValue(2000);

        formLayout->setWidget(3, QFormLayout::FieldRole, matrix_dpi);


        gridLayout_8->addWidget(filter_controls, 2, 0, 1, 3);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_8->addItem(horizontalSpacer_5, 3, 0, 1, 1);

        filter_save = new QPushButton(frame);
        filter_save->setObjectName(QStringLiteral("filter_save"));
        QSizePolicy sizePolicy17(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy17.setHorizontalStretch(0);
        sizePolicy17.setVerticalStretch(0);
        sizePolicy17.setHeightForWidth(filter_save->sizePolicy().hasHeightForWidth());
        filter_save->setSizePolicy(sizePolicy17);

        gridLayout_8->addWidget(filter_save, 3, 2, 1, 1);


        gridLayout_7->addWidget(frame, 0, 0, 1, 1);

        operations->addTab(satelite_image_filter, QString());
        multispecrum_images = new QWidget();
        multispecrum_images->setObjectName(QStringLiteral("multispecrum_images"));
        gridLayout_14 = new QGridLayout(multispecrum_images);
        gridLayout_14->setSpacing(6);
        gridLayout_14->setContentsMargins(11, 11, 11, 11);
        gridLayout_14->setObjectName(QStringLiteral("gridLayout_14"));
        groupBox_8 = new QGroupBox(multispecrum_images);
        groupBox_8->setObjectName(QStringLiteral("groupBox_8"));
        sizePolicy7.setHeightForWidth(groupBox_8->sizePolicy().hasHeightForWidth());
        groupBox_8->setSizePolicy(sizePolicy7);
        groupBox_8->setAlignment(Qt::AlignCenter);
        gridLayout_13 = new QGridLayout(groupBox_8);
        gridLayout_13->setSpacing(6);
        gridLayout_13->setContentsMargins(11, 11, 11, 11);
        gridLayout_13->setObjectName(QStringLiteral("gridLayout_13"));
        MI_addColorImage = new QPushButton(groupBox_8);
        MI_addColorImage->setObjectName(QStringLiteral("MI_addColorImage"));

        gridLayout_13->addWidget(MI_addColorImage, 0, 0, 1, 2);

        MI_TreeView = new BasicTreeView(groupBox_8);
        MI_TreeView->setObjectName(QStringLiteral("MI_TreeView"));
        MI_TreeView->setEditTriggers(QAbstractItemView::NoEditTriggers);
        MI_TreeView->setTabKeyNavigation(true);
        MI_TreeView->setDragEnabled(true);
        MI_TreeView->setDragDropOverwriteMode(false);
        MI_TreeView->setDragDropMode(QAbstractItemView::DragDrop);
        MI_TreeView->setDefaultDropAction(Qt::MoveAction);
        MI_TreeView->setAlternatingRowColors(true);
        MI_TreeView->setSelectionMode(QAbstractItemView::ExtendedSelection);
        MI_TreeView->setIconSize(QSize(40, 40));
        MI_TreeView->setUniformRowHeights(true);
        MI_TreeView->setAnimated(true);
        MI_TreeView->setWordWrap(true);
        MI_TreeView->setHeaderHidden(true);

        gridLayout_13->addWidget(MI_TreeView, 1, 0, 1, 2);

        MI_preview = new QPushButton(groupBox_8);
        MI_preview->setObjectName(QStringLiteral("MI_preview"));
        sizePolicy.setHeightForWidth(MI_preview->sizePolicy().hasHeightForWidth());
        MI_preview->setSizePolicy(sizePolicy);

        gridLayout_13->addWidget(MI_preview, 2, 0, 1, 1);

        MI_save = new QPushButton(groupBox_8);
        MI_save->setObjectName(QStringLiteral("MI_save"));
        sizePolicy.setHeightForWidth(MI_save->sizePolicy().hasHeightForWidth());
        MI_save->setSizePolicy(sizePolicy);

        gridLayout_13->addWidget(MI_save, 2, 1, 1, 1);


        gridLayout_14->addWidget(groupBox_8, 0, 0, 1, 1);

        operations->addTab(multispecrum_images, QString());
        comparative_characteristics = new QWidget();
        comparative_characteristics->setObjectName(QStringLiteral("comparative_characteristics"));
        horizontalLayout_6 = new QHBoxLayout(comparative_characteristics);
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        comp_char_widget_prev = new QPushButton(comparative_characteristics);
        comp_char_widget_prev->setObjectName(QStringLiteral("comp_char_widget_prev"));
        sizePolicy17.setHeightForWidth(comp_char_widget_prev->sizePolicy().hasHeightForWidth());
        comp_char_widget_prev->setSizePolicy(sizePolicy17);

        horizontalLayout_6->addWidget(comp_char_widget_prev);

        comp_char_widget = new SlidingStackedWidget(comparative_characteristics);
        comp_char_widget->setObjectName(QStringLiteral("comp_char_widget"));
        comp_char_widget->setFrameShape(QFrame::StyledPanel);
        comp_char_widget->setFrameShadow(QFrame::Raised);
        comp_char_widget->setLineWidth(0);
        comp_char_widget->setMidLineWidth(0);
        page = new QWidget();
        page->setObjectName(QStringLiteral("page"));
        gridLayout_16 = new QGridLayout(page);
        gridLayout_16->setSpacing(6);
        gridLayout_16->setContentsMargins(11, 11, 11, 11);
        gridLayout_16->setObjectName(QStringLiteral("gridLayout_16"));
        frame_5 = new QFrame(page);
        frame_5->setObjectName(QStringLiteral("frame_5"));
        frame_5->setFrameShape(QFrame::StyledPanel);
        frame_5->setFrameShadow(QFrame::Raised);
        verticalLayout_2 = new QVBoxLayout(frame_5);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        groupBox_11 = new QGroupBox(frame_5);
        groupBox_11->setObjectName(QStringLiteral("groupBox_11"));
        gridLayout = new QGridLayout(groupBox_11);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        comp_char_set_img1 = new QPushButton(groupBox_11);
        comp_char_set_img1->setObjectName(QStringLiteral("comp_char_set_img1"));

        gridLayout->addWidget(comp_char_set_img1, 0, 0, 1, 1);

        comp_char_img1_view = new previewGraphicsView(groupBox_11);
        comp_char_img1_view->setObjectName(QStringLiteral("comp_char_img1_view"));
        QSizePolicy sizePolicy18(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy18.setHorizontalStretch(0);
        sizePolicy18.setVerticalStretch(0);
        sizePolicy18.setHeightForWidth(comp_char_img1_view->sizePolicy().hasHeightForWidth());
        comp_char_img1_view->setSizePolicy(sizePolicy18);
        comp_char_img1_view->setViewportUpdateMode(QGraphicsView::FullViewportUpdate);

        gridLayout->addWidget(comp_char_img1_view, 1, 0, 1, 1);


        verticalLayout_2->addWidget(groupBox_11);

        groupBox_12 = new QGroupBox(frame_5);
        groupBox_12->setObjectName(QStringLiteral("groupBox_12"));
        gridLayout_9 = new QGridLayout(groupBox_12);
        gridLayout_9->setSpacing(6);
        gridLayout_9->setContentsMargins(11, 11, 11, 11);
        gridLayout_9->setObjectName(QStringLiteral("gridLayout_9"));
        comp_char_set_img2 = new QPushButton(groupBox_12);
        comp_char_set_img2->setObjectName(QStringLiteral("comp_char_set_img2"));

        gridLayout_9->addWidget(comp_char_set_img2, 0, 0, 1, 1);

        comp_char_img2_view = new previewGraphicsView(groupBox_12);
        comp_char_img2_view->setObjectName(QStringLiteral("comp_char_img2_view"));
        comp_char_img2_view->setDragMode(QGraphicsView::ScrollHandDrag);
        comp_char_img2_view->setResizeAnchor(QGraphicsView::AnchorUnderMouse);

        gridLayout_9->addWidget(comp_char_img2_view, 1, 0, 1, 1);


        verticalLayout_2->addWidget(groupBox_12);


        gridLayout_16->addWidget(frame_5, 0, 0, 1, 1);

        comp_char_widget->addWidget(page);
        page_2 = new QWidget();
        page_2->setObjectName(QStringLiteral("page_2"));
        horizontalLayout_5 = new QHBoxLayout(page_2);
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        groupBox_6 = new QGroupBox(page_2);
        groupBox_6->setObjectName(QStringLiteral("groupBox_6"));
        horizontalLayout_4 = new QHBoxLayout(groupBox_6);
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        comp_char_list = new BasicListView(groupBox_6);
        comp_char_list->setObjectName(QStringLiteral("comp_char_list"));
        QSizePolicy sizePolicy19(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy19.setHorizontalStretch(1);
        sizePolicy19.setVerticalStretch(0);
        sizePolicy19.setHeightForWidth(comp_char_list->sizePolicy().hasHeightForWidth());
        comp_char_list->setSizePolicy(sizePolicy19);
        comp_char_list->setEditTriggers(QAbstractItemView::NoEditTriggers);
        comp_char_list->setSelectionMode(QAbstractItemView::MultiSelection);

        horizontalLayout_4->addWidget(comp_char_list);

        groupBox_7 = new QGroupBox(groupBox_6);
        groupBox_7->setObjectName(QStringLiteral("groupBox_7"));
        QSizePolicy sizePolicy20(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy20.setHorizontalStretch(1);
        sizePolicy20.setVerticalStretch(0);
        sizePolicy20.setHeightForWidth(groupBox_7->sizePolicy().hasHeightForWidth());
        groupBox_7->setSizePolicy(sizePolicy20);
        spinBox = new QSpinBox(groupBox_7);
        spinBox->setObjectName(QStringLiteral("spinBox"));
        spinBox->setGeometry(QRect(10, 40, 221, 31));

        horizontalLayout_4->addWidget(groupBox_7);


        horizontalLayout_5->addWidget(groupBox_6);

        comp_char_widget->addWidget(page_2);
        page_3 = new QWidget();
        page_3->setObjectName(QStringLiteral("page_3"));
        verticalLayout = new QVBoxLayout(page_3);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        comp_char_ssim_map_container = new QGroupBox(page_3);
        comp_char_ssim_map_container->setObjectName(QStringLiteral("comp_char_ssim_map_container"));
        gridLayout_10 = new QGridLayout(comp_char_ssim_map_container);
        gridLayout_10->setSpacing(6);
        gridLayout_10->setContentsMargins(11, 11, 11, 11);
        gridLayout_10->setObjectName(QStringLiteral("gridLayout_10"));
        comp_char_ssim_map_save = new QPushButton(comp_char_ssim_map_container);
        comp_char_ssim_map_save->setObjectName(QStringLiteral("comp_char_ssim_map_save"));
        sizePolicy.setHeightForWidth(comp_char_ssim_map_save->sizePolicy().hasHeightForWidth());
        comp_char_ssim_map_save->setSizePolicy(sizePolicy);

        gridLayout_10->addWidget(comp_char_ssim_map_save, 1, 1, 1, 1);

        horizontalSpacer = new QSpacerItem(150, 20, QSizePolicy::Preferred, QSizePolicy::Minimum);

        gridLayout_10->addItem(horizontalSpacer, 1, 0, 1, 1);

        comp_char_ssim_map = new previewGraphicsView(comp_char_ssim_map_container);
        comp_char_ssim_map->setObjectName(QStringLiteral("comp_char_ssim_map"));

        gridLayout_10->addWidget(comp_char_ssim_map, 0, 0, 1, 2);


        verticalLayout->addWidget(comp_char_ssim_map_container);

        groupBox_9 = new QGroupBox(page_3);
        groupBox_9->setObjectName(QStringLiteral("groupBox_9"));
        gridLayout_11 = new QGridLayout(groupBox_9);
        gridLayout_11->setSpacing(6);
        gridLayout_11->setContentsMargins(11, 11, 11, 11);
        gridLayout_11->setObjectName(QStringLiteral("gridLayout_11"));
        comp_char_results_table_save = new QPushButton(groupBox_9);
        comp_char_results_table_save->setObjectName(QStringLiteral("comp_char_results_table_save"));
        sizePolicy.setHeightForWidth(comp_char_results_table_save->sizePolicy().hasHeightForWidth());
        comp_char_results_table_save->setSizePolicy(sizePolicy);

        gridLayout_11->addWidget(comp_char_results_table_save, 1, 1, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Preferred, QSizePolicy::Minimum);

        gridLayout_11->addItem(horizontalSpacer_2, 1, 0, 1, 1);

        comp_char_results_table = new QTableView(groupBox_9);
        comp_char_results_table->setObjectName(QStringLiteral("comp_char_results_table"));
        comp_char_results_table->horizontalHeader()->setStretchLastSection(true);

        gridLayout_11->addWidget(comp_char_results_table, 0, 0, 1, 2);


        verticalLayout->addWidget(groupBox_9);

        comp_char_widget->addWidget(page_3);

        horizontalLayout_6->addWidget(comp_char_widget);

        comp_char_widget_next = new QPushButton(comparative_characteristics);
        comp_char_widget_next->setObjectName(QStringLiteral("comp_char_widget_next"));
        sizePolicy17.setHeightForWidth(comp_char_widget_next->sizePolicy().hasHeightForWidth());
        comp_char_widget_next->setSizePolicy(sizePolicy17);

        horizontalLayout_6->addWidget(comp_char_widget_next);

        operations->addTab(comparative_characteristics, QString());
        contours = new QWidget();
        contours->setObjectName(QStringLiteral("contours"));
        gridLayout_15 = new QGridLayout(contours);
        gridLayout_15->setSpacing(6);
        gridLayout_15->setContentsMargins(11, 11, 11, 11);
        gridLayout_15->setObjectName(QStringLiteral("gridLayout_15"));
        frame_3 = new QFrame(contours);
        frame_3->setObjectName(QStringLiteral("frame_3"));
        sizePolicy20.setHeightForWidth(frame_3->sizePolicy().hasHeightForWidth());
        frame_3->setSizePolicy(sizePolicy20);
        frame_3->setFrameShape(QFrame::StyledPanel);
        frame_3->setFrameShadow(QFrame::Raised);
        horizontalLayout = new QHBoxLayout(frame_3);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label_4 = new QLabel(frame_3);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setMinimumSize(QSize(0, 0));

        horizontalLayout->addWidget(label_4);

        edge_detection_type = new QComboBox(frame_3);
        edge_detection_type->setObjectName(QStringLiteral("edge_detection_type"));
        QSizePolicy sizePolicy21(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy21.setHorizontalStretch(0);
        sizePolicy21.setVerticalStretch(0);
        sizePolicy21.setHeightForWidth(edge_detection_type->sizePolicy().hasHeightForWidth());
        edge_detection_type->setSizePolicy(sizePolicy21);
        edge_detection_type->setMinimumSize(QSize(0, 0));
        edge_detection_type->setEditable(false);

        horizontalLayout->addWidget(edge_detection_type);

        edge_get = new QPushButton(frame_3);
        edge_get->setObjectName(QStringLiteral("edge_get"));
        QSizePolicy sizePolicy22(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy22.setHorizontalStretch(0);
        sizePolicy22.setVerticalStretch(0);
        sizePolicy22.setHeightForWidth(edge_get->sizePolicy().hasHeightForWidth());
        edge_get->setSizePolicy(sizePolicy22);
        edge_get->setMinimumSize(QSize(1, 0));

        horizontalLayout->addWidget(edge_get);


        gridLayout_15->addWidget(frame_3, 0, 0, 1, 1);

        frame_4 = new QFrame(contours);
        frame_4->setObjectName(QStringLiteral("frame_4"));
        sizePolicy20.setHeightForWidth(frame_4->sizePolicy().hasHeightForWidth());
        frame_4->setSizePolicy(sizePolicy20);
        frame_4->setFrameShape(QFrame::StyledPanel);
        frame_4->setFrameShadow(QFrame::Raised);

        gridLayout_15->addWidget(frame_4, 0, 1, 1, 1);

        edges_source = new previewGraphicsView(contours);
        edges_source->setObjectName(QStringLiteral("edges_source"));

        gridLayout_15->addWidget(edges_source, 1, 0, 1, 2);

        operations->addTab(contours, QString());

        gridLayout_3->addWidget(operations, 0, 1, 1, 1);

        mainTreeView = new ImageTreeView(centralWidget);
        mainTreeView->setObjectName(QStringLiteral("mainTreeView"));
        QSizePolicy sizePolicy23(QSizePolicy::Preferred, QSizePolicy::Expanding);
        sizePolicy23.setHorizontalStretch(0);
        sizePolicy23.setVerticalStretch(0);
        sizePolicy23.setHeightForWidth(mainTreeView->sizePolicy().hasHeightForWidth());
        mainTreeView->setSizePolicy(sizePolicy23);
        mainTreeView->setEditTriggers(QAbstractItemView::NoEditTriggers);
        mainTreeView->setTabKeyNavigation(true);
        mainTreeView->setDragEnabled(true);
        mainTreeView->setDragDropMode(QAbstractItemView::DragDrop);
        mainTreeView->setAlternatingRowColors(true);
        mainTreeView->setIconSize(QSize(40, 40));
        mainTreeView->setUniformRowHeights(true);
        mainTreeView->setSortingEnabled(true);
        mainTreeView->setAnimated(true);
        mainTreeView->setWordWrap(true);
        mainTreeView->setHeaderHidden(true);
        mainTreeView->header()->setVisible(false);
        mainTreeView->header()->setProperty("showSortIndicator", QVariant(false));
        mainTreeView->header()->setStretchLastSection(false);

        gridLayout_3->addWidget(mainTreeView, 0, 0, 1, 1);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1052, 21));
        menuBar->setDefaultUp(false);
        menu_file = new QMenu(menuBar);
        menu_file->setObjectName(QStringLiteral("menu_file"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        mainToolBar->setEnabled(true);
        sizePolicy17.setHeightForWidth(mainToolBar->sizePolicy().hasHeightForWidth());
        mainToolBar->setSizePolicy(sizePolicy17);
        mainToolBar->setMouseTracking(true);
        mainToolBar->setStyleSheet(QStringLiteral("margin:1px;padding:2px;border:none"));
        mainToolBar->setIconSize(QSize(30, 30));
        mainToolBar->setToolButtonStyle(Qt::ToolButtonIconOnly);
        MainWindow->addToolBar(Qt::LeftToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menu_file->menuAction());
        menu_file->addSeparator();
        mainToolBar->addAction(actionAdd);
        mainToolBar->addAction(actionRemove);

        retranslateUi(MainWindow);

        operations->setCurrentIndex(5);
        comp_char_widget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Image processing", 0));
        actionRemove->setText(QApplication::translate("MainWindow", "Remove", 0));
        actionRemove->setIconText(QApplication::translate("MainWindow", "Remove", 0));
        actionAdd->setText(QApplication::translate("MainWindow", "Add", 0));
        actionAdd->setIconText(QApplication::translate("MainWindow", "Add", 0));
        actionPreview->setText(QApplication::translate("MainWindow", "Preview", 0));
#ifndef QT_NO_TOOLTIP
        preview_tab->setToolTip(QString());
#endif // QT_NO_TOOLTIP
        operations->setTabText(operations->indexOf(preview_tab), QApplication::translate("MainWindow", "Preview", 0));
        operations->setTabToolTip(operations->indexOf(preview_tab), QApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt; font-weight:600; color:#356a9f;\">Quick preview of current image</span></p></body></html>", 0));
#ifndef QT_NO_TOOLTIP
        characteristics_tab->setToolTip(QString());
#endif // QT_NO_TOOLTIP
        groupBox_4->setTitle(QApplication::translate("MainWindow", "Characteristics", 0));
        groupBox_5->setTitle(QApplication::translate("MainWindow", "Results", 0));
        evaluateParams->setText(QApplication::translate("MainWindow", "Evaluate", 0));
        saveParams->setText(QApplication::translate("MainWindow", "Save", 0));
        operations->setTabText(operations->indexOf(characteristics_tab), QApplication::translate("MainWindow", "Characteristics", 0));
        operations->setTabToolTip(operations->indexOf(characteristics_tab), QApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt; font-weight:600; color:#356a9f;\">Evaluate basic chatacteristics of current image</span></p></body></html>", 0));
        groupBox_2->setTitle(QApplication::translate("MainWindow", "Mask", 0));
        IF_set_pan->setText(QApplication::translate("MainWindow", "Set Selected", 0));
        IF_use_normalization->setText(QApplication::translate("MainWindow", "Normalize color", 0));
        IF_start->setText(QApplication::translate("MainWindow", "Start", 0));
        groupBox_3->setTitle(QApplication::translate("MainWindow", "Results", 0));
        IF_save->setText(QApplication::translate("MainWindow", "Save", 0));
        IF_preview->setText(QApplication::translate("MainWindow", "Preview", 0));
        IF_add_color_image->setText(QApplication::translate("MainWindow", "Add Colored Image", 0));
        groupBox_10->setTitle(QApplication::translate("MainWindow", "Orthogonalization Type", 0));
        IF_orthogonalization_type->setItemText(1, QApplication::translate("MainWindow", "SVD", 0));

        IF_orthogonalization_type->setCurrentText(QApplication::translate("MainWindow", "QR ", 0));
        groupBox->setTitle(QApplication::translate("MainWindow", "Sources", 0));
        IF_remove_from_source_list->setText(QApplication::translate("MainWindow", "Remove selected", 0));
        IF_add_selected_to_list->setText(QApplication::translate("MainWindow", "Add Selected", 0));
        operations->setTabText(operations->indexOf(image_fusion), QApplication::translate("MainWindow", "Image fusion", 0));
        filter_set_current_image->setText(QApplication::translate("MainWindow", "Set Current", 0));
        filter_start->setText(QApplication::translate("MainWindow", "Filter", 0));
        filter_controls->setTitle(QApplication::translate("MainWindow", "Controls", 0));
        label->setText(QApplication::translate("MainWindow", "Lens Radius", 0));
#ifndef QT_NO_TOOLTIP
        filter_lens_radius->setToolTip(QApplication::translate("MainWindow", "Lens radius of satelite optical system", 0));
#endif // QT_NO_TOOLTIP
        filter_lens_radius->setSuffix(QApplication::translate("MainWindow", " mm", "millimeters"));
        label_2->setText(QApplication::translate("MainWindow", "Optical system width", 0));
#ifndef QT_NO_TOOLTIP
        filter_os_width->setToolTip(QApplication::translate("MainWindow", "Lenght of satelite optical system", 0));
#endif // QT_NO_TOOLTIP
        filter_os_width->setSuffix(QApplication::translate("MainWindow", " mm", "millimeters"));
        label_3->setText(QApplication::translate("MainWindow", "Wavelength, \316\273", 0));
#ifndef QT_NO_TOOLTIP
        filter_wavelength->setToolTip(QApplication::translate("MainWindow", "Average wavelength of measured radiation", 0));
#endif // QT_NO_TOOLTIP
        filter_wavelength->setPrefix(QString());
        filter_wavelength->setSuffix(QApplication::translate("MainWindow", " nm", "nanometers"));
        dpi_label->setText(QApplication::translate("MainWindow", "Matrix DPI", 0));
#ifndef QT_NO_TOOLTIP
        matrix_dpi->setToolTip(QApplication::translate("MainWindow", "DPI of detertor matrix", 0));
#endif // QT_NO_TOOLTIP
        matrix_dpi->setSuffix(QApplication::translate("MainWindow", " dpi", "millimeters"));
        filter_save->setText(QApplication::translate("MainWindow", "Save", 0));
        operations->setTabText(operations->indexOf(satelite_image_filter), QApplication::translate("MainWindow", "Satelite image filter", 0));
        groupBox_8->setTitle(QApplication::translate("MainWindow", "Results", 0));
        MI_addColorImage->setText(QApplication::translate("MainWindow", "Add Colored Image", 0));
        MI_preview->setText(QApplication::translate("MainWindow", "Preview", 0));
        MI_save->setText(QApplication::translate("MainWindow", "Save", 0));
        operations->setTabText(operations->indexOf(multispecrum_images), QApplication::translate("MainWindow", "Multispecrum images", 0));
        comp_char_widget_prev->setText(QApplication::translate("MainWindow", "\357\204\204", 0));
        groupBox_11->setTitle(QApplication::translate("MainWindow", "First Image", 0));
        comp_char_set_img1->setText(QApplication::translate("MainWindow", "Pick selected", 0));
        groupBox_12->setTitle(QApplication::translate("MainWindow", "GroupBox", 0));
        comp_char_set_img2->setText(QApplication::translate("MainWindow", "PIck selected", 0));
        groupBox_6->setTitle(QApplication::translate("MainWindow", "Options", 0));
        groupBox_7->setTitle(QApplication::translate("MainWindow", "Config", 0));
        comp_char_ssim_map_container->setTitle(QApplication::translate("MainWindow", "SSIM Map", 0));
        comp_char_ssim_map_save->setText(QApplication::translate("MainWindow", "Save", 0));
        groupBox_9->setTitle(QApplication::translate("MainWindow", "Results", 0));
        comp_char_results_table_save->setText(QApplication::translate("MainWindow", "Save", 0));
        comp_char_widget_next->setText(QApplication::translate("MainWindow", "\357\204\205", 0));
        operations->setTabText(operations->indexOf(comparative_characteristics), QApplication::translate("MainWindow", "Comparative Characteristics", 0));
#ifndef QT_NO_TOOLTIP
        contours->setToolTip(QApplication::translate("MainWindow", "<html><head/><body><p>Detecting Contours on given image</p></body></html>", 0));
#endif // QT_NO_TOOLTIP
        label_4->setText(QApplication::translate("MainWindow", "Detection type", 0));
        edge_get->setText(QApplication::translate("MainWindow", "Detect Edges", 0));
        operations->setTabText(operations->indexOf(contours), QApplication::translate("MainWindow", "Edge Detection", 0));
        menu_file->setTitle(QApplication::translate("MainWindow", "File", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
