cmake_minimum_required(VERSION 3.29)

project(BeeScript)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(SOURCE_FILES main.cpp Lexer.hpp Lexer.cpp)

add_executable(BeeScript ${SOURCE_FILES})