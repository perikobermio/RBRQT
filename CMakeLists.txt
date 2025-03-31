cmake_minimum_required(VERSION 3.5)

project(HolaMundoQt5)

set(CMAKE_CXX_STANDARD 11)

# Encuentra Qt5
find_package(Qt5 REQUIRED Widgets)

# Agregar el archivo fuente
add_executable(HolaMundoQt5 main.cpp)

# Vincula la aplicación con Qt5
target_link_libraries(HolaMundoQt5 Qt5::Widgets)

qt_add_resources(HolaMundoQt5 "resources.qrc")