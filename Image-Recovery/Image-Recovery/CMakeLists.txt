cmake_minimum_required(VERSION 3.20)

project(Image-Recovery VERSION 0.1)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_PREFIX_PATH $ENV{HOME}/Qt/6.2.0/gcc_64/lib/cmake)

find_package(QT NAMES Qt6 Qt5 COMPONENTS Widgets REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Widgets REQUIRED)

set(PROJECT_SOURCES
        resources.qrc
        src/main.cpp
        src/ui/mainscreen.cpp
        src/ui/mainscreen.h
        src/ui/mainscreen.ui
        src/algorithm/datamanager.cpp
        src/algorithm/datamanager.h
        src/algorithm/genetic.cpp
        src/algorithm/genetic.h
        src/data-structures/simplelist.h
        src/data-structures/simplenode.h)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(Image-Recovery
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
    )
else()
    if(ANDROID)
        add_library(Image-Recovery SHARED
            ${PROJECT_SOURCES}
        )
    else()
        add_executable(Image-Recovery
            ${PROJECT_SOURCES}
        )
    endif()
endif()

target_link_libraries(Image-Recovery PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)

set_target_properties(Image-Recovery PROPERTIES
    MACOSX_BUNDLE_GUI_IDENTIFIER my.example.com
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(Image-Recovery)
endif()