cmake_minimum_required(VERSION 3.21)

project(TestTask VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 REQUIRED COMPONENTS Widgets)
# qt_standard_project_setup()
set(CMAKE_AUTOMOC ON)


qt_add_executable(TestTask
main.cpp
window.cpp
)
set_target_properties(TestTask PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

target_link_libraries(TestTask PRIVATE Qt6::Widgets)
