TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

PRECOMPILED_HEADER = pch.h

SOURCES += main.cpp

HEADERS += \
    visitor.h \
    pch.h \
    cor.h \
    flyweight.h
