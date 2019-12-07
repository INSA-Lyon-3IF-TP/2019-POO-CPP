TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        Catalogue.cpp \
        Trajet.cpp \
        TrajetComplexe.cpp \
        TrajetSimple.cpp \
        main.cpp

HEADERS += \
    Catalogue.h \
    Trajet.h \
    TrajetComplexe.h \
    TrajetSimple.h

DISTFILES += \
    Makefile
