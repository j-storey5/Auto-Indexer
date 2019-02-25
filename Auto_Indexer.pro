TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        main.cpp \
    catch_test.cpp \
    dsstring.cpp \
    index.cpp

HEADERS += \
    catch.hpp \
    dsstring.h \
    dsvector.hpp \
    index.h
