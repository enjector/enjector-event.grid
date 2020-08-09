project(event.grid-client.python)
cmake_minimum_required (VERSION 3.15.1)

add_subdirectory(deps/pybind11-2.5.0)
pybind11_add_module(eventgrid src/Main.cpp)
