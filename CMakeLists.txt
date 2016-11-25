cmake_minimum_required(VERSION 3.6)
project(ex1__version_1_1)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
        BfsAlgorithm.h
    Grid.cpp
    Grid.h
    main.cpp
        Node.h Graph.h Point.cpp Point.h InputParsing.cpp InputParsing.h)

add_executable(ex1__version_1_1 ${SOURCE_FILES})