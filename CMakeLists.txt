cmake_minimum_required(VERSION 3.5)

project(spectracs VERSION 0.1 LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 COMPONENTS Widgets LinguistTools Sql REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Widgets LinguistTools Sql REQUIRED)

set(TS_FILES spectracs_en_AT.ts)

set(PROJECT_SOURCES

        qdbmanager/criteriabuilder.cpp
        qdbmanager/criteriabuilder.h
        qdbmanager/entities/abstractEntity.cpp
        qdbmanager/entities/abstractEntity.h
        qdbmanager/entities/baseEntity.cpp
        qdbmanager/entities/baseEntity.h
        qdbmanager/entityfactory.cpp
        qdbmanager/entityfactory.h
        qdbmanager/interfaces/qsqlite.cpp
        qdbmanager/interfaces/qsqlite.h
        qdbmanager/qdbmanager.cpp
        qdbmanager/qdbmanager.h
        qdbmanager/tpmanager.cpp
        qdbmanager/tpmanager.h


        main.cpp
        mainwindow.cpp
        mainwindow.h
        applicationContext.cpp
        applicationContext.h
        spectralJob.cpp
        spectralJob.h
        spectralMeasurement.h
        spectralMeasurement.cpp
        spectrasServerResponseHandler.h
        spectrasServerResponseHandler.cpp
        spectralMeasurementBarChart.h
        spectralMeasurementBarChart.cpp
        spectralMeasurementDbEntity.h
        spectralMeasurementDbEntity.cpp
        mainwindow.ui

        testEntity.h
        testEntity.cpp


        ${TS_FILES}
)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(spectracs
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
    )
# Define target properties for Android with Qt 6 as:
#    set_property(TARGET spectracs APPEND PROPERTY QT_ANDROID_PACKAGE_SOURCE_DIR
#                 ${CMAKE_CURRENT_SOURCE_DIR}/android)
# For more information, see https://doc.qt.io/qt-6/qt-add-executable.html#target-creation

    qt_create_translation(QM_FILES ${CMAKE_SOURCE_DIR} ${TS_FILES})
else()
    if(ANDROID)
        add_library(spectracs SHARED
            ${PROJECT_SOURCES}
        )
# Define properties for Android with Qt 5 after find_package() calls as:
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
    else()
        add_executable(spectracs
            ${PROJECT_SOURCES}
        )
    endif()

    qt5_create_translation(QM_FILES ${CMAKE_SOURCE_DIR} ${TS_FILES})
endif()

target_link_libraries(spectracs PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)

set_target_properties(spectracs PROPERTIES
    MACOSX_BUNDLE_GUI_IDENTIFIER my.example.com
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
)

find_package(Qt6 COMPONENTS Network REQUIRED)
target_link_libraries(spectracs PRIVATE Qt6::Network)

find_package(Qt6 COMPONENTS Charts REQUIRED)
target_link_libraries(spectracs PRIVATE Qt6::Charts)

find_package(Qt6 COMPONENTS Sql REQUIRED)
target_link_libraries(spectracs PRIVATE Qt6::Sql)

add_subdirectory(../../qt-sqlite-orm qt-sqlite-orm.build)

target_link_libraries(spectracs PUBLIC qtorm)



if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(spectracs)
endif()
