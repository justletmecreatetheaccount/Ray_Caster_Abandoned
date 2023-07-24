cmake_minimum_required(VERSION 3.25.1)
project(Ray_Caster VERSION 0.0.1 LANGUAGES CXX)
set(CMAKE_C_COMPILER "clang")
set(CMAKE_CXX_COMPILER "clang++")
set(CMAKE_TOOLCHAIN_FILE "C:/C++/vcpkg/scripts/buildsystems/vcpkg.cmake")

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(SFML_STATIC_LIBRARIES TRUE)
set(SFML_DIR "${CMAKE_SOURCE_DIR}/Dependencies/SFML-2.6.0/lib/cmake/SFML")
set(OpenCV_DIR "${CMAKE_SOURCE_DIR}/Dependencies/opencv/build/x64/vc16/lib")
find_package(SFML 2.5.1 COMPONENTS system window graphics REQUIRED)
find_package( OpenCV REQUIRED )
include_directories(
    ${SFML_INCLUDE_DIRS}
    ${OpenCV_INCLUDE_DIRS}
)

set(SOURCES
    src/Ray_Caster.cpp
    src/Entities.cpp
    src/Attributes.cpp
    src/Custom_Attributes.cpp
)

add_executable(${PROJECT_NAME} ${SOURCES})
target_link_libraries(${PROJECT_NAME} sfml-system sfml-window sfml-graphics ${OpenCV_LIBS})