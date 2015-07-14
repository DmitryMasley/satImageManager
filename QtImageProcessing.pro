#-------------------------------------------------
#
# Project created by QtCreator 2012-10-12T11:26:44
#
#-------------------------------------------------
QT       += core gui widgets network  webkit qml quick quickwidgets
TARGET = QtImageProcessing
TEMPLATE = app
PRECOMPILED_HEADER = stdafx.h
SOURCES +=stdafx.cpp \
        main.cpp\
        mainwindow.cpp \
    ImagePropertiesEvaluating.cpp \
    ProcessingCore.cpp \
    imagetree.cpp \
    previewgraphicsview.cpp \
    imagetreenode.cpp \
    imagetreemodel.cpp \
    treeitem.cpp \
    imagetreeview.cpp \
    characteristicsitem.cpp \
    characteristicstable.cpp \
    characteristicsmodel.cpp \
    characteristicslist.cpp \
    characteristicsproggresbar.cpp \
    progressdialog.cpp \
#    controllers.cpp \
    basiclistview.cpp \
    controllercharacteristics.cpp \
    controllermain.cpp \
    controllerfilter.cpp \
    imageitem.cpp \
    imagemodel.cpp \
    basicmodel.cpp \
    basicmodelitem.cpp \
    matmodel.cpp \
    matmodelitem.cpp \
    ddmimedata.cpp \
    basictreeview.cpp \
    imagecharacteristics.cpp \
    basicitemmimedata.cpp \
#    ssim.cpp \
    slidingstackedwidget.cpp \
    grayscaleimagemodel.cpp \
    controllercomparativecharacteristics.cpp \
    controllermultichannel.cpp \
    mainmodel.cpp \
    helperdialog.cpp \
    imageFusion/imagefusionprocessor.cpp \
    imageFusion/controllerimagefusion.cpp \
    listitemdelegate.cpp \
    lib/abstractitem.cpp \
    lib/standardmodel.cpp \
    lib/standardmimedata.cpp \
    lib/image/standardimagemodel.cpp \
    lib/image/standardimageitem.cpp \
    multichannel/controllermultichannelimages.cpp \
    controllers/edgedetectioncontroller.cpp \
    object.cpp \
    UICore.cpp

HEADERS  +=stdafx.h \
    mainwindow.h \
    ImagePropertiesEvaluating.h \
    ProcessingCore.h \
    imagetree.h \
    previewgraphicsview.h \
    imagetreenode.h \
    imagetreemodel.h \
    treeitem.h \
    imagetreeview.h \
    characteristicstable.h \
    characteristicsitem.h \
    characteristicsmodel.h \
    characteristicslist.h \
    characteristicsproggresbar.h \
    progressdialog.h \
#    controllers.h \
    basiclistview.h \
    controllercharacteristics.h \
    controllermain.h \
    controllerfilter.h \
    imageitem.h \
    imagemodel.h \
    basicmodel.h \
    basicmodelitem.h \
    matmodel.h \
    matmodelitem.h \
    ddmimedata.h \
    basictreeview.h \
    imagecharacteristics.h \
    basicitemmimedata.h \
#    ssim.h \
    slidingstackedwidget.h \
    grayscaleimagemodel.h \
    controllercomparativecharacteristics.h \
    controllermultichannel.h \
    mainmodel.h \
    helperdialog.h \
    imageFusion/imagefusionprocessor.h \
    imageFusion/controllerimagefusion.h \
    listitemdelegate.h \
    lib/abstractitem.h \
    lib/standardmodel.h \
    lib/standardmimedata.h \
    lib/image/standardimagemodel.h \
    lib/image/standardimageitem.h \
    multichannel/controllermultichannelimages.h \
    metatypes.h \
    controllers/edgedetectioncontroller.h \
    controllerimagefusion.h \
    object.h \
    ui_helperdialog.h \
    ui_mainwindow.h \
    UICore.h

FORMS+= mainwindow.ui

#OPENCV = C:/opencv
#OPENCV_LIB = $$OPENCV/build/x86/vc10/lib
#INCLUDEPATH += $$OPENCV/build/include
#QMAKE_LIBDIR += $$OPENCV_LIB
#CONFIG(debug, debug|release) {
#  LIBS += $$files($$OPENCV_LIB/*242.lib)
#} else {
#  LIBS += $$files($$OPENCV_LIB/*242d.lib)
#}
INCLUDEPATH += "C:/opencv/build/include"#C:/opencvQt/include


# custom build mingw
#LIBS += "C:/openCVBuild/lib/libopencv_core246.dll.a"
#LIBS += "C:/openCVBuild/lib/libopencv_calib3d246.dll.a"
#LIBS += "C:/openCVBuild/lib/libopencv_contrib246.dll.a"

#LIBS += "C:/openCVBuild/lib/libopencv_features2d246.dll.a"
#LIBS += "C:/openCVBuild/lib/libopencv_flann246.dll.a"

#LIBS += "C:/openCVBuild/lib/libopencv_gpu246.dll.a"
#LIBS += "C:/openCVBuild/lib/libopencv_highgui246.dll.a"
#LIBS += "C:/openCVBuild/lib/libopencv_imgproc246.dll.a"
#LIBS += "C:/openCVBuild/lib/libopencv_legacy246.dll.a"

#LIBS += "C:/openCVBuild/lib/libopencv_ml246.dll.a"
#LIBS += "C:/openCVBuild/lib/libopencv_nonfree246.dll.a"
#LIBS += "C:/openCVBuild/lib/libopencv_objdetect246.dll.a"
# custom build mingw end



LIBS += "C:/opencv/build-current/lib/libopencv_calib3d300.dll.a"
LIBS += "C:/opencv/build-current/lib/libopencv_core300.dll.a"
LIBS += "C:/opencv/build-current/lib/libopencv_features2d300.dll.a"
LIBS += "C:/opencv/build-current/lib/libopencv_flann300.dll.a"
LIBS += "C:/opencv/build-current/lib/libopencv_highgui300.dll.a"
LIBS += "C:/opencv/build-current/lib/libopencv_imgcodecs300.dll.a"
LIBS += "C:/opencv/build-current/lib/libopencv_imgproc300.dll.a"
LIBS += "C:/opencv/build-current/lib/libopencv_java300.dll.a"

LIBS += "C:/opencv/build-current/lib/libopencv_ml300.dll.a"
LIBS += "C:/opencv/build-current/lib/libopencv_objdetect300.dll.a"
LIBS += "C:/opencv/build-current/lib/libopencv_photo300.dll.a"
LIBS += "C:/opencv/build-current/lib/libopencv_shape300.dll.a"
LIBS += "C:/opencv/build-current/lib/libopencv_stitching300.dll.a"
LIBS += "C:/opencv/build-current/lib/libopencv_superres300.dll.a"
LIBS += "C:/opencv/build-current/lib/libopencv_video300.dll.a"
LIBS += "C:/opencv/build-current/lib/libopencv_videoio300.dll.a"
LIBS += "C:/opencv/build-current/lib/libopencv_videostab300.dll.a"

#LIBS += "C:/opencv/build-current/bin/libopencv_calib3d300.dll"
#LIBS += "C:/opencv/build-current/bin/libopencv_core300.dll"
#LIBS += "C:/opencv/build-current/bin/libopencv_features2d300.dll"
#LIBS += "C:/opencv/build-current/bin/libopencv_flann300.dll"
#LIBS += "C:/opencv/build-current/bin/libopencv_highgui300.dll"
#LIBS += "C:/opencv/build-current/bin/libopencv_imgcodecs300.dll"
#LIBS += "C:/opencv/build-current/bin/libopencv_imgproc300.dll"
#LIBS += "C:/opencv/build-current/bin/libopencv_java300.dll"

#LIBS += "C:/opencv/build-current/bin/libopencv_ml300.dll"
#LIBS += "C:/opencv/build-current/bin/libopencv_objdetect300.dll"
#LIBS += "C:/opencv/build-current/bin/libopencv_photo300.dll"
#LIBS += "C:/opencv/build-current/bin/libopencv_shape300.dll"
#LIBS += "C:/opencv/build-current/bin/libopencv_stitching300.dll"

#LIBS += "C:/opencv/build-current/bin/libopencv_superres300.dll"
#LIBS += "C:/opencv/build-current/bin/libopencv_video300.dll"
#LIBS += "C:/opencv/build-current/bin/libopencv_videoio300.dll"
#LIBS += "C:/opencv/build-current/bin/libopencv_videostab300.dll"
#"C:/opencv/build/x86/vc1/lib/opencv_contrib242.lib" \
#"C:/opencv/build/x86/vc10/lib/opencv_core242.lib" \
#"C:/opencv/build/x86/vc10/lib/opencv_imgproc242.lib" \
#"C:/opencv/build/x86/vc10/lib/opencv_highgui242.lib"
#LIBS += "C:/opencv/build/x86/vc10/lib/opencv_ml242.lib"
#LIBS += "C:/opencv/build/x86/vc10/lib/opencv_video242.lib"
#LIBS += "C:/opencv/build/x86/vc10/lib/opencv_features2d242.lib"

#LIBS += "C:/opencv/build/x86/vc10/lib/opencv_objdetect242.lib"
#LIBS += "C:/opencv/build/x86/vc10/lib/opencv_legacy242.lib"
#LIBS += "C:/opencv/build/x86/vc10/lib/opencv_flann242.lib"

#LIBS += C:/opencv/build/x86/vc10/lib/opencv_gpu242.lib
#LIBS += C:/opencv/build/x86/vc10/lib/opencv_nonfree242.lib
#LIBS += C:/opencv/build/x86/vc10/lib/opencv_photo242.lib
#LIBS += C:/opencv/build/x86/vc10/lib/opencv_stitching242.lib
#LIBS += C:/opencv/build/x86/vc10/lib/opencv_ts242.lib
#LIBS += C:/opencv/build/x86/vc10/lib/opencv_videostab242.lib


#DEPENDPATH +="C:/opencv/build/x86/mingw/bin"
#DEPENDPATH +="C:/opencv/build/common/tbb/ia32/mingw"
#DEPENDPATH +="F:/QtSDK/mingw/bin"
#DEPENDPATH +="F:/QtSDK/Desktop/Qt/4.8.1/mingw/bin"

RESOURCES += \
    resource.qrc
include(./QtAwesome/QtAwesome.pri)
