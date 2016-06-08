TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt


INCLUDEPATH += -I/usr/local/include /opt/pylon5/include
LIBS += -L/usr/local/lib -lopencv_imgproc -lopencv_core -lopencv_highgui -L/opt/pylon5/lib64 -lpylonbase -lpylonutility -lGenApi_gcc_v3_0_Basler_pylon_v5_0 -lGCBase_gcc_v3_0_Basler_pylon_v5_0 -lLog_gcc_v3_0_Basler_pylon_v5_0 -lMathParser_gcc_v3_0_Basler_pylon_v5_0 -lNodeMapData_gcc_v3_0_Basler_pylon_v5_0 -lXmlParser_gcc_v3_0_Basler_pylon_v5_0

SOURCES += main.cpp \
    baslercamera.cpp

#CFLAGS += -m32
#QMAKE_CXXFLAGS += -m32
#CONFIG += i386

HEADERS += \
    baslercamera.h
