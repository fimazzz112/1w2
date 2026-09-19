cmake_minimum_required(VERSION 3.20)
project(FabricLauncher LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(FabricLauncher WIN32 src/main.cpp)
