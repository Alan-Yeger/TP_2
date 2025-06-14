cmake_minimum_required(VERSION 3.10)
project(TP_Pokedex)

set(CMAKE_CXX_STANDARD 20)

file(GLOB SOURCES_EJ1 "Ej1/src/*.cpp")

set(SOURCES_EJ1 ${SOURCES_EJ1} "Ej1/examples/main.cpp")

add_executable(ej1 ${SOURCES_EJ1})

add_executable(ej2
    Ej2/src/dron.cpp
    Ej2/examples/main.cpp
)

add_executable(ej3
    Ej3/examples/main.cpp
)
