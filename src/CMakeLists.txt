cmake_minimum_required(VERSION 3.0.0)
project(1-task VERSION 0.1.0)

set(SOURCES main.cpp circle.cpp)
set(HEADERS ${MY_INCLUDE_DIR}/circle.h)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(EXECUTABLE_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/img)
set(CMAKE_PREFIX_PATH "/home/pavel/Qt/6.3.1/gcc_64/lib/cmake/")

find_package(Qt6 COMPONENTS Core Gui Widgets REQUIRED)
qt6_wrap_cpp (MOC_SOURCES ${HEADERS})

add_executable(1-task ${SOURCES} ${MOC_SOURCES})

target_link_libraries(1-task Qt6::Core Qt6::Gui Qt6::Widgets)
target_include_directories(1-task PUBLIC ${MY_INCLUDE_DIR})
