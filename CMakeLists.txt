cmake_minimum_required(VERSION 3.26)
project(raytracer_in_cpp)

set(CMAKE_CXX_STANDARD 20)

add_library(raytracer_in_cpp
        Vector3.cpp
        Vector3.h
        Vector2.cpp
        Vector2.h
        Math.cpp
        Math.h
        Point2.cpp
        Point2.h
        Point3.cpp
        Point3.h)
