project(eventgrid)

add_subdirectory(deps/pybind11-2.5.0)
pybind11_add_module(eventgrid src/Main.cpp)
