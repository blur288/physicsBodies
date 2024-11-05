cmake_minimum_required(VERSION 3.15)
project(RaylibTest)

find_package(raylib 3.0 REQUIRED) # Requires at least version 3.0
#add_library(rlimgui "${CMAKE_SOURCE_DIR}/External/rlImGui/bin/Debug/librlImGui.a")

add_compile_options(--std=c++11)

set (CMAKE_CXX_STANDARD 11) # Requires C11 standard


include_directories(External)

add_executable(${PROJECT_NAME} main.cpp
        src/Object.cpp
        src/Object.h
        src/physics/physics.cpp
        src/physics/physics.h
        windowClass/windowClass.cpp
        windowClass/windowClass.h
        src/scene.cpp
        src/scene.h
        External/imgui/imgui.cpp
        External/imgui/imgui_demo.cpp
        External/imgui/imgui_draw.cpp
        External/imgui/imgui_tables.cpp
        External/imgui/imgui_widgets.cpp)

target_include_directories(${PROJECT_NAME} PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/External/rlImGui/")
target_link_libraries(${PROJECT_NAME} raylib "${CMAKE_CURRENT_SOURCE_DIR}/External/rlImGui/bin/rlImGui.o")

#${CMAKE_SOURCE_DIR}/External/rlImGui/bin/Debug/librlImGui.a


# Checks if OSX and links appropriate frameworks (only required on MacOS)
if (APPLE)
    target_link_libraries(${PROJECT_NAME} "-framework IOKit")
    target_link_libraries(${PROJECT_NAME} "-framework Cocoa")
    target_link_libraries(${PROJECT_NAME} "-framework OpenGL")
endif()