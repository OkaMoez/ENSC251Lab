TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        main.cpp \
        student.cpp

HEADERS += \
    student.hpp

DISTFILES += \
    README \
    domestic-stu.txt \
    international-stu.txt
