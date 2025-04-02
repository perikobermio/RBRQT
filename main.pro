

TEMPLATE = lib
CONFIG += dll
TARGET = RBRPlugin
DEFINES += RBRPLUGIN_LIBRARY

SOURCES += \
    main.cpp \ 
    src/*.cpp

HEADERS += \
    include/*.h

RESOURCES += resources.qrc