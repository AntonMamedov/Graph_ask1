cmake_minimum_required(VERSION 3.17)
project(Graph3modul_1)

set(CMAKE_CXX_STANDARD 17)
include_directories(include)
file(GLOB SrcFiles "src/*.cpp")
add_executable(Graph3modul_1 ${SrcFiles})