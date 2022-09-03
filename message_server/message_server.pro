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

SOURCES += \
        ../baselib/hiredis-1.0.2/alloc.c \
        ../baselib/hiredis-1.0.2/async.c \
        ../baselib/hiredis-1.0.2/dict.c \
        ../baselib/hiredis-1.0.2/examples/example-ae.c \
        ../baselib/hiredis-1.0.2/examples/example-glib.c \
        ../baselib/hiredis-1.0.2/examples/example-ivykis.c \
        ../baselib/hiredis-1.0.2/examples/example-libev.c \
        ../baselib/hiredis-1.0.2/examples/example-libevent-ssl.c \
        ../baselib/hiredis-1.0.2/examples/example-libevent.c \
        ../baselib/hiredis-1.0.2/examples/example-libuv.c \
        ../baselib/hiredis-1.0.2/examples/example-macosx.c \
        ../baselib/hiredis-1.0.2/examples/example-push.c \
        ../baselib/hiredis-1.0.2/examples/example-qt.cpp \
        ../baselib/hiredis-1.0.2/examples/example-ssl.c \
        ../baselib/hiredis-1.0.2/examples/example.c \
        ../baselib/hiredis-1.0.2/hiredis.c \
        ../baselib/hiredis-1.0.2/net.c \
        ../baselib/hiredis-1.0.2/read.c \
        ../baselib/hiredis-1.0.2/sds.c \
        ../baselib/hiredis-1.0.2/sockcompat.c \
        ../baselib/hiredis-1.0.2/ssl.c \
        ../baselib/hiredis-1.0.2/test.c \
        ../baselib/net/buffer.cpp \
        ../baselib/net/channel.cpp \
        ../baselib/net/channel_client.cpp \
        ../baselib/net/channel_factory.cpp \
        ../baselib/net/chlq.cpp \
        ../baselib/net/main.cpp \
        ../pro/protocol.cpp \
        channel_client.cpp \
        conn_mgr.cpp \
        loop.cpp \
        main.cpp

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

SUBDIRS += \
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
    ../baselib/hiredis-1.0.2/adapters/ae.h \
    ../baselib/hiredis-1.0.2/adapters/glib.h \
    ../baselib/hiredis-1.0.2/adapters/ivykis.h \
    ../baselib/hiredis-1.0.2/adapters/libev.h \
    ../baselib/hiredis-1.0.2/adapters/libevent.h \
    ../baselib/hiredis-1.0.2/adapters/libuv.h \
    ../baselib/hiredis-1.0.2/adapters/macosx.h \
    ../baselib/hiredis-1.0.2/adapters/qt.h \
    ../baselib/hiredis-1.0.2/alloc.h \
    ../baselib/hiredis-1.0.2/async.h \
    ../baselib/hiredis-1.0.2/async_private.h \
    ../baselib/hiredis-1.0.2/dict.h \
    ../baselib/hiredis-1.0.2/examples/example-qt.h \
    ../baselib/hiredis-1.0.2/fmacros.h \
    ../baselib/hiredis-1.0.2/hiredis.h \
    ../baselib/hiredis-1.0.2/hiredis_ssl.h \
    ../baselib/hiredis-1.0.2/net.h \
    ../baselib/hiredis-1.0.2/read.h \
    ../baselib/hiredis-1.0.2/sds.h \
    ../baselib/hiredis-1.0.2/sdsalloc.h \
    ../baselib/hiredis-1.0.2/sockcompat.h \
    ../baselib/hiredis-1.0.2/win32.h \
    ../baselib/net/buffer.h \
    ../baselib/net/channel.h \
    ../baselib/net/channel_client.h \
    ../baselib/net/channel_factory.h \
    ../baselib/net/chlq.h \
    ../pro/protocol.h \
    channel_client.h \
    conn_mgr.h \
    loop.h
