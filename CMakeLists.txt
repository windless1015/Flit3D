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

#header include directory
include_directories(${OPENGL_INCLUDE_DIRS})

#src code files
add_executable(TrackBall 
    main.cpp
    TrackballWidget.h
    TrackballWidget.cpp
    Mesh.h
    Mesh.cpp
    )

set(OPENMESH_LIB_DEBUG 
    OpenMeshCored
    OpenMeshToolsd
)

set(OPENMESH_LIB_RELEASE 
    OpenMeshCore
    OpenMeshTools
)

#link lib directory
TARGET_LINK_DIRECTORIES(${CMAKE_PROJECT_NAME} PUBLIC
    "C:/Program Files/OpenMesh 10.0/lib"
)

#link libs 
TARGET_LINK_LIBRARIES(TrackBall 
    Qt5::Widgets 
    Qt5::Core 
    Qt5::Gui
    debug ${OPENMESH_LIB_DEBUG}
    optimized ${OPENMESH_LIB_RELEASE}
    ${OPENGL_LIBRARIES}
)