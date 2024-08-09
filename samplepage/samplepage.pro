TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    cmdtestfunction.cpp \
    cmdtestutils.cpp \
    cmdtestunit.cpp

HEADERS += \
    cmdtestfunction.h \
    cmdtestutils.h \
    cmdtestunit.h

########## AutoReplyPrint Begin ##########

AUTOREPLYPRINT_DIR = ../autoreplyprint

# other arch need define additional arguments
# like this:
#   AUTOREPLYPRINT_ARCH=arm-xxx-linux-gnueabi
isEmpty(AUTOREPLYPRINT_ARCH) {
    unix:mac {
        AUTOREPLYPRINT_ARCH = mac
    }
    unix:!mac {
        equals(QT_ARCH, i386) {
            AUTOREPLYPRINT_ARCH = linux-x86
        }
        equals(QT_ARCH, x86_64) {
            AUTOREPLYPRINT_ARCH = linux-x64
        }
    }
    win32 {
        equals(QT_ARCH,windows) {
            AUTOREPLYPRINT_ARCH = win32
        }
        equals(QT_ARCH,i386) {
            AUTOREPLYPRINT_ARCH = win32
        }
        equals(QT_ARCH,x86_64) {
            AUTOREPLYPRINT_ARCH = win64
        }
    }
}
isEmpty(AUTOREPLYPRINT_LINKTYPE) {
    AUTOREPLYPRINT_LINKTYPE = staticlib
    #AUTOREPLYPRINT_LINKTYPE = dll
}
AUTOREPLYPRINT_LINKDIR = $${AUTOREPLYPRINT_DIR}/$${AUTOREPLYPRINT_LINKTYPE}/$${AUTOREPLYPRINT_ARCH}
LIBS += -L$${AUTOREPLYPRINT_LINKDIR}
LIBS += -lautoreplyprint -lpthread
INCLUDEPATH += $${AUTOREPLYPRINT_LINKDIR}

########## AutoReplyPrint End   ##########
