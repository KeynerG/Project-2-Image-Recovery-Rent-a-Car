cmake_minimum_required(VERSION 3.20)

project(Rent_A_Car VERSION 0.1)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_PREFIX_PATH $ENV{HOME}/Qt/6.2.0/gcc_64/lib/cmake/)

find_package(QT NAMES Qt6 Qt5 COMPONENTS Widgets REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Widgets REQUIRED)

include_directories(cmake-build-debug/)

set(PROJECT_SOURCES
        main.cpp
        mainwindow.cpp
        mainwindow.h
        mainwindow.ui
        DataStructures/SimpleList/SimpleList.h 
        DataStructures/SimpleList/SimpleNode.h 
        DataStructures/Graph/Graph.cpp 
        DataStructures/Graph/Graph.h 
        DataStructures/Graph/Vertex.cpp 
        DataStructures/Graph/Vertex.h 
        DataStructures/Graph/Edge.cpp 
        DataStructures/Graph/Edge.h 
        LogicManagment/TravelAssistant.cpp 
        LogicManagment/TravelAssistant.h)

if (${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(Rent_A_Car
            MANUAL_FINALIZATION
            ${PROJECT_SOURCES}
            )
    # Define target properties for Android with Qt 6 as:
    #    set_property(TARGET Rent_A_Car APPEND PROPERTY QT_ANDROID_PACKAGE_SOURCE_DIR
    #                 ${CMAKE_CURRENT_SOURCE_DIR}/android)
    # For more information, see https://doc.qt.io/qt-6/qt-add-executable.html#target-creation
else ()
    if (ANDROID)
        add_library(Rent_A_Car SHARED
                ${PROJECT_SOURCES}
                )
        # Define properties for Android with Qt 5 after find_package() calls as:
        #    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
    else ()
        add_executable(Rent_A_Car
                ${PROJECT_SOURCES}
                )
    endif ()
endif ()

target_link_libraries(Rent_A_Car PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)

set_target_properties(Rent_A_Car PROPERTIES
        MACOSX_BUNDLE_GUI_IDENTIFIER my.example.com
        MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
        MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
        )

if (QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(Rent_A_Car)
endif ()
