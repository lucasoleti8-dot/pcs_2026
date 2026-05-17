cmake_minimum_required(VERSION 3.20)
project(esercitazione_9) 

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wshadow -Werror=vla")

set(SOURCE_visite_grafi visite_grafi.cpp)
add_executable(Visite_grafi ${SOURCE_visite_grafi})

