# -------------------------------------------------
# Project created by QtCreator 2015-08-08T19:59:02
# -------------------------------------------------
QT += core \
    gui \
    sql
greaterThan(QT_MAJOR_VERSION, 4):QT += widgets
TARGET = laichunfu
TEMPLATE = app
SOURCES += main.cpp \
    mainwidget.cpp \
    exp/expdialog.cpp \
    select/selectdialog.cpp \
    manage/managedialog.cpp \
    set/setdialog.cpp \
    input/myinputpanel.cpp \
    input/myinputpanelcontext.cpp \
    command.cpp \
    confirmstd/confirmstd.cpp
HEADERS += mainwidget.h \
    exp/expdialog.h \
    select/selectdialog.h \
    manage/managedialog.h \
    set/setdialog.h \
    input/myinputpanel.h \
    input/myinputpanelcontext.h \
    connect_sql.h \
    ecam/ezsys.h \
    ecam/inifile.h \
    ../../../../../usr/ezcam.h \
    lincom/posix_qextserialport.h \
    lincom/qextserialbase.h \
    command.h \
    confirmstd/confirmstd.h
FORMS += mainwidget.ui \
    exp/expdialog.ui \
    select/selectdialog.ui \
    manage/managedialog.ui \
    set/setdialog.ui \
    input/myinputpanelform.ui \
    confirmstd/confirmstd.ui
RESOURCES += rc.qrc
