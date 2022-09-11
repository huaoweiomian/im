QT -= gui

CONFIG += c++11 console
CONFIG -= app_bundle

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0



# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

SUBDIRS += \
    ../baselib/net/pro_server.pro \
    ../baselib/net/pro_server.pro

DISTFILES += \
    ../baselib/hiredis-1.0.2/CHANGELOG.md \
    ../baselib/hiredis-1.0.2/CMakeLists.txt \
    ../baselib/hiredis-1.0.2/COPYING \
    ../baselib/hiredis-1.0.2/README.md \
    ../baselib/hiredis-1.0.2/appveyor.yml \
    ../baselib/hiredis-1.0.2/examples/CMakeLists.txt \
    ../baselib/hiredis-1.0.2/hiredis-config.cmake.in \
    ../baselib/hiredis-1.0.2/hiredis.pc.in \
    ../baselib/hiredis-1.0.2/hiredis_ssl-config.cmake.in \
    ../baselib/hiredis-1.0.2/hiredis_ssl.pc.in \
    ../baselib/hiredis-1.0.2/test.sh \
    ../baselib/net/README.md

HEADERS += \
    ../baselib/net/buffer.h \
    ../baselib/net/channel.h \
    ../baselib/net/channel_client.h \
    ../baselib/net/channel_factory.h \
    ../baselib/net/chlq.h \
    ../pro/protocol.h \
    config.h \
    conn_mgr.h \
    loop.h

SOURCES += \
    ../baselib/net/buffer.cpp \
    ../baselib/net/channel.cpp \
    ../baselib/net/channel_client.cpp \
    ../baselib/net/channel_factory.cpp \
    ../baselib/net/chlq.cpp \
    ../pro/protocol.cpp \
    config.cpp \
    conn_mgr.cpp \
    loop.cpp \
    main.cpp

