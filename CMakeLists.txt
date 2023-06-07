cmake_minimum_required(VERSION 3.24.1)
project("StasG4Project" VERSION 0.1.0)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_PREFIX_PATH "D:\\Qt\\Qt5.12.12\\5.12.12\\mingw73_64\\lib\\cmake")

#find_package(Qt5Widgets REQUIRED)
find_package(Qt5Widgets COMPONENTS
        Core
        Gui
        Widgets
        REQUIRED)

add_executable(StasG4Project myprogram.cpp)

#target_link_libraries(StasG4Project Qt5::Widgets)
target_link_libraries(StasG4Project
        Qt5::Core
        Qt5::Gui
        Qt5::Widgets)