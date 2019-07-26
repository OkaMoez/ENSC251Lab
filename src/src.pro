TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
    functions.cpp \
    main.cpp \
    student.cpp \
    studentlists.cpp

HEADERS += \
    constants.hpp \
    functions.hpp \
    student.hpp \
    studentlists.hpp \
    unittest.hpp

DISTFILES += \
    README \
    domestic-stu.txt \
    international-stu.txt \
    test-stu.txt
