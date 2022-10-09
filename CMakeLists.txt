cmake_minimum_required(VERSION 3.12 FATAL_ERROR)

project(Simulation)

find_package(AUSALIB REQUIRED)

list(APPEND CMAKE_PREFIX_PATH "/home/jeppe/devel/resources/geant4/geant4-v11.0.2-install/lib/")

find_package(Geant4 REQUIRED ui_all vis_all)

include(${Geant4_USE_FILE})

file(GLOB sources ${PROJECT_SOURCE_DIR}/*.cpp)
file(GLOB headers ${PROJECT_SOURCE_DIR}/*.hh)

add_executable(sim main.cpp ${sources} ${headers})
target_link_libraries(sim ${Geant4_LIBRARIES} AUSA::AUSA)

add_custom_target(Simulation DEPENDS sim)