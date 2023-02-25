cmake_minimum_required(VERSION 3.21)
project(FlightMap)

set(CMAKE_CXX_STANDARD 14)

add_executable(FlightMap main.cpp FlightMap.cpp FlightMap.h Flight.cpp Flight.h City.cpp City.h)
