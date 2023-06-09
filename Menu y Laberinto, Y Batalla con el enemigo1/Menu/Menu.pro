QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    enemigos.cpp \
    items_juego.cpp \
    jugador.cpp \
    main.cpp \
    mainwindow.cpp \
    mainwindow1.cpp \
    mainwindow2.cpp \
    mainwindow3.cpp \
    mi_esfera.cpp

HEADERS += \
    enemigos.h \
    items_juego.h \
    jugador.h \
    mainwindow.h \
    mainwindow1.h \
    mainwindow2.h \
    mainwindow3.h \
    mi_esfera.h

FORMS += \
    mainwindow.ui \
    mainwindow1.ui \
    mainwindow2.ui \
    mainwindow3.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    IMAGENES.qrc
