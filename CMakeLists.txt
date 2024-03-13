cmake_minimum_required(VERSION 3.10)

project(TextRPG)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(TextRPG main.cpp)

add_subdirectory(src)

target_link_libraries(TextRPG SourceLibrary)