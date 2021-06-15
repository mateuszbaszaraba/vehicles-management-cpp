cmake_minimum_required(VERSION 3.17)
project(electric_cars_project)

set(CMAKE_CXX_STANDARD 11)

add_executable(electric_cars_project main.cpp vehicle.cpp vehicle.h car.cpp car.h bike.cpp bike.h)