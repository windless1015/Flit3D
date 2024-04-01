cmake_minimum_required(VERSION 3.10)

project(TrackBall VERSION 1.0)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Add a definition for _USE_MATH_DEFINES
add_definitions(-D_USE_MATH_DEFINES)

find_package(Qt5 COMPONENTS Widgets Core Gui REQUIRED)
find_package(OpenGL REQUIRED)
find_package(OpenMesh REQUIRED)

include_directories(${OpenMesh_INCLUDE_DIRS})
include_directories(${OPENGL_INCLUDE_DIRS})

add_executable(TrackBall 
    main.cpp
    TrackballWidget.h
    TrackballWidget.cpp
    Mesh.h
    Mesh.cpp
    #OpenMeshWrapper.h
    )

if(CMAKE_VERSION VERSION_LESS "3.7.0")
    set(CMAKE_INCLUDE_CURRENT_DIR ON)
endif()

target_link_libraries(TrackBall 
    Qt5::Widgets 
    Qt5::Core 
    Qt5::Gui
    OpenMeshCore 
    OpenMeshTools 
    ${OPENGL_LIBRARIES})