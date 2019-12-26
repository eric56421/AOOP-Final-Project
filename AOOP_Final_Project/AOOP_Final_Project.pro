QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

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
    add1.cpp \
    building.cpp \
    data.cpp \
    distancebetweenprime.cpp \
    fibonaccioffibonacci.cpp \
    findfactorial.cpp \
    findstructuresoftrees.cpp \
    findtheperiodofstring.cpp \
    floor.cpp \
    getsignature.cpp \
    getsolution.cpp \
    judge.cpp \
    judgewindow.cpp \
    largefactorial.cpp \
    largesroot.cpp \
    longestandshortestdistance.cpp \
    longestcommonsubstring.cpp \
    longestpeekpalindrome.cpp \
    main.cpp \
    mainwindow.cpp \
    manhattandistance.cpp \
    marioojisan.cpp \
    maze.cpp \
    minesweeper.cpp \
    mydatabase.cpp \
    mymath.cpp \
    myother.cpp \
    mystring.cpp \
    mytree.cpp \
    people.cpp \
    problemset.cpp \
    runinformation.cpp \
    scheduler.cpp \
    setfactorial.cpp \
    shortestandlongestpair.cpp \
    shortestsummationdistance.cpp \
    shygame.cpp \
    subtract1.cpp \
    symmetricpairs.cpp \
    theeasycity1.cpp \
    sumoflargehexadecimalintegers.cpp \
    theeasycity2.cpp

HEADERS += \
    add1.h \
    building.h \
    data.h \
    distancebetweenprime.h \
    fibonaccioffibonacci.h \
    findfactorial.h \
    findstructuresoftrees.h \
    findtheperiodofstring.h \
    floor.h \
    getsignature.h \
    getsolution.h \
    judge.h \
    judgewindow.h \
    largefactorial.h \
    largesroot.h \
    longestandshortestdistance.h \
    longestcommonsubstring.h \
    longestpeekpalindrome.h \
    mainwindow.h \
    manhattandistance.h \
    marioojisan.h \
    maze.h \
    minesweeper.h \
    mydatabase.h \
    mymath.h \
    myother.h \
    mystring.h \
    mytree.h \
    people.h \
    problems.h \
    problemset.h \
    runinformation.h \
    scheduler.h \
    shortestandlongestpair.h \
    shortestsummationdistance.h \
    shygame.h \
    subtract1.h \
    symmetricpairs.h \
    theeasycity1.h \
    sumoflargehexadecimalintegers.h \
    theeasycity2.h

FORMS += \
    judgewindow.ui \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
