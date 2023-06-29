cmake_minimum_required(VERSION 3.25.1)
set(CMAKE_BUILD_TYPE Debug)
project(Ray_Caster VERSION 0.0.1 LANGUAGES CXX)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(EXPORT_COMPILE_COMMANDS)

set(SFML_STATIC_LIBRARIES TRUE)
set(SFML_DIR "${CMAKE_SOURCE_DIR}/Dependencies/SFML-2.6.0/lib/cmake/SFML")
find_package(SFML 2.6.0 COMPONENTS system window graphics REQUIRED)
include_directories(${SFML_INCLUDE_DIRS})

set(SOURCES
    src/Ray_Caster.cpp
    src/Entities.cpp
    src/Attributes.cpp
)

add_executable(${PROJECT_NAME} ${SOURCES})
target_link_libraries(${PROJECT_NAME} sfml-system sfml-window sfml-graphics)