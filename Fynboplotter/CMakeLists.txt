cmake_minimum_required(VERSION 3.21)
project(Fynboplotter)

set(CMAKE_CXX_STANDARD 14)

find_package(ROOT 6.18 CONFIG REQUIRED)

add_executable(Fynboplotter main.cpp)
target_link_libraries(Fynboplotter PUBLIC ROOT::Physics ROOT::Hist)
