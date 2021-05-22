QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    about.cpp \
    add.cpp \
    datagroup.cpp \
    edit.cpp \
    find.cpp \
    ifsave.cpp \
    lib/api.cpp \
    lib/meta.cpp \
    lib/util.cpp \
    main.cpp \
    mainwindow.cpp \
    test/hsms_test.c

HEADERS += \
    about.h \
    add.h \
    datagroup.h \
    edit.h \
    find.h \
    ifsave.h \
    lib/api.h \
    lib/meta.h \
    lib/util.h \
    mainwindow.h

FORMS += \
    about.ui \
    add.ui \
    find.ui \
    ifsave.ui \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    data/students.dat
ICON = icon.icns

RESOURCES += \
    logo.qrc

