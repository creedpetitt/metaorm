cmake_minimum_required(VERSION 3.20)

project(metaorm LANGUAGES CXX)

add_executable(metaorm
    src/main.cpp
)

target_compile_options(metaorm PRIVATE -std=c++26)

target_include_directories(metaorm PUBLIC
    ${PROJECT_SOURCE_DIR}/include
)

target_compile_options(metaorm PRIVATE -freflection)