TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt


INCLUDEPATH += -I/usr/local/include /opt/pylon5/include
LIBS += -L/usr/local/lib -lopencv_shape -lopencv_stitching -lopencv_objdetect -lopencv_superres -lopencv_videostab -lopencv_calib3d -lopencv_features2d -lopencv_highgui -lopencv_videoio -lopencv_imgcodecs -lopencv_video -lopencv_photo -lopencv_ml -lopencv_imgproc -lopencv_flann -lopencv_core -lopencv_hal -L/opt/pylon5/lib64 -lpylonbase -lpylonutility -lGenApi_gcc_v3_0_Basler_pylon_v5_0 -lGCBase_gcc_v3_0_Basler_pylon_v5_0 -lLog_gcc_v3_0_Basler_pylon_v5_0 -lMathParser_gcc_v3_0_Basler_pylon_v5_0 -lNodeMapData_gcc_v3_0_Basler_pylon_v5_0 -lXmlParser_gcc_v3_0_Basler_pylon_v5_0

SOURCES += main.cpp \
    baslercamera.cpp

#CFLAGS += -m32
#QMAKE_CXXFLAGS += -m32
#CONFIG += i386

HEADERS += \
    baslercamera.h
