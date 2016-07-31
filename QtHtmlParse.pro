TEMPLATE = app

QT += qml quick widgets
QT += network
QT += xml

CONFIG += c++11

SOURCES += main.cpp \
        mytools.cpp

RESOURCES += qml.qrc

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Default rules for deployment.
include(deployment.pri)

HEADERS += \
        mytools.h

DISTFILES += \
    test.html \
    node.html
