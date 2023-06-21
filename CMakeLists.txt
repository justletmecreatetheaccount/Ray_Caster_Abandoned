cmake_minimum_required(VERSION 3.25.1)
project(Ray_Caster VERSION 0.0.1 LANGUAGES CXX)

set(SFML_LIBS sfml-graphics sfml-system sfml-window)


add_executable(${PROJECT_NAME} ${WIN32_GUI} ${PROJECT_SOURCE_DIR}/src/Ray_Caster.cpp)
target_include_directories(${PROJECT_NAME} PRIVATE ${PROJECT_SOURCE_DIR}/Dependencies/SFML-2.5.1/include)
#target_link_directories(${PROJECT_NAME} PRIVATE ${PROJECT_SOURCE_DIR}/Dependencies/SFML-2.5.1/lib)
target_link_libraries(${PROJECT_NAME} ${SFML_LIBS})
set_property(TARGET ${PROJECT_NAME} PROPERTY CXX_STANDARD 17)