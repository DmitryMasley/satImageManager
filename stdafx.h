#pragma once
#include <iostream> // for standard I/O
#include <string> // for strings
#include <QObject>
#include <QMimeData>
#include <QtWidgets/QWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QFileDialog>
#include <QtWidgets/QGraphicsItem>
#include <QtWidgets/QGraphicsView>
#include <QBitmap>
#include <QtWidgets/QTreeView>
#include <QtWidgets/QTableView>
#include <QStringListModel>
#include <QtWidgets/QListView>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QProgressDialog>
#include <QtWidgets/QPushButton>
#include <QTextStream>
#include <QTextDocument>
#include <QTextDocumentWriter>
#include <QTextTable>
#include <QTextCursor>
#include <QTextCodec>
#include <QtWidgets/QProgressDialog>
#include <QtWidgets/QMessageBox>
#include <QEasingCurve>
#include <QDebug>
#include <QPropertyAnimation>
#include <QParallelAnimationGroup>
#include <QtGlobal>
#include <cmath>
#include <iomanip> // for controlling float print precision
#include <sstream> // string to number conversion
//#include <vcclr.h>
#include <opencv2/imgproc/imgproc.hpp> // Gaussian Blur
#include <opencv2/core/core.hpp> // Basic OpenCV structures (cv::Mat, Scalar)
#include <opencv2/highgui/highgui.hpp> // OpenCV window I/O
#include <opencv2/imgproc/imgproc_c.h>
#include <opencv2/gpu/gpu.hpp>
#include "ProcessingCore.h"
//#include "ssim.h"
#include "slidingstackedwidget.h"
//#include "UICore.h"
#include "ImagePropertiesEvaluating.h"
#include "basicitemmimedata.h"
#include "ddmimedata.h"
#include "basiclistview.h"
#include "basictreeview.h"
#include "basicmodelitem.h"
#include "basicmodel.h"
#include "imagetreeview.h"
#include "imagetreemodel.h"
//#include "imagetree.h"
//#include "imageitem.h"
//#include "imagemodel.h"
//#include "imagetreenode.h"
//#include "previewgraphicsview.h"
//#include "treeitem.h"
//#include "QAbstractItemModel"
//#include "characteristicsitem.h"
//#include "characteristicsmodel.h"
//#include "matmodelitem.h"
//#include "matmodel.h"
#include "grayscaleimagemodel.h"
#include "helperdialog.h"

Q_DECLARE_METATYPE(cv::Mat)
Q_DECLARE_METATYPE(QImage*)
Q_DECLARE_METATYPE(QList<QList<QVariant> >)
