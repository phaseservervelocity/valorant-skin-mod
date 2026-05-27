cmake_minimum_required(VERSION 3.10)
project(valorant-skin-mod VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(valorant-skin-mod
    src/main.cpp
    src/skin_changer.cpp
    src/memory_utils.cpp
    include/skin_changer.h
    include/memory_utils.h
)

target_include_directories(valorant-skin-mod PRIVATE include)