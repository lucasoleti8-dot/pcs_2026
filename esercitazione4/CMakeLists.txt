cmake_minimum_required(VERSION 3.20)
project(esercitazione_4) 

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wshadow -Werror=vla")

set(SOURCE_measure_sorts measure_sorts.cpp timecounter.cpp)
add_executable(Measure_sorts ${SOURCE_measure_sorts})

set(SOURCE_bubblesort test_bubblesort.cpp)
add_executable(Test_bubblesort ${SOURCE_bubblesort})
add_test(NAME bubblesort COMMAND Test_bubblesort)

set(SOURCE_insertionsort test_insertionsort.cpp)
add_executable(Test_insertionsort ${SOURCE_insertionsort})
add_test(NAME insertionsort COMMAND Test_insertionsort)

set(SOURCE_selectionsort test_selectionsort.cpp)
add_executable(Test_selectionsort ${SOURCE_selectionsort})
add_test(NAME selectionsort COMMAND Test_selectionsort)

enable_testing()



