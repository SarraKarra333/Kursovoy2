QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    comboboxdelegate.cpp \
    d_d.cpp \
    diagramwindow.cpp \
    main.cpp \
    mainwindow.cpp \
    midi.cpp \
    spinboxdelegate.cpp

HEADERS += \
    comboboxdelegate.h \
    d_d.h \
    diagramwindow.h \
    list.h \
    mainwindow.h \
    midi.h \
    spinboxdelegate.h

FORMS += \
    diagramwindow.ui \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
