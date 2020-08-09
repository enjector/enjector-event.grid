project(event.grid-client.python)

set(PROJECT_PYTHON_SHARED_LIB_NAME eventgrid)

find_package(Python COMPONENTS Interpreter Development)
if(Python_FOUND)
  set(PYTHON_EXECUTABLE          ${Python_EXECUTABLE})
  set(PYTHON_LIBRARY             ${Python_LIBRARIES})
  set(PYTHON_LIBRARY             ${Python_LIBRARIES})
  set(PYTHON_INCLUDE_DIR         ${Python_INCLUDE_DIRS})
  set(PYTHON_VERSION_STRING      ${Python_VERSION})
  set(PYTHONLIBS_VERSION_STRING  ${Python_VERSION})
else()
    message(FATAL_ERROR "Python deps not found")
endif()

message(">>>>${PYTHON_LIBRARY}")

include_directories(
    ${PYTHON_INCLUDE_DIRS}
    ${PYBIND11_INCLUDE_DIRS}
)

if(CMAKE_BUILD_TYPE MATCHES "Debug")
    set(CMAKE_LIBRARY_OUTPUT_DIRECTORY_DEBUG "${CMAKE_CURRENT_BINARY_DIR}/package/eventgrid")
    set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG "${CMAKE_CURRENT_BINARY_DIR}/package/eventgrid")
else()
    set(CMAKE_LIBRARY_OUTPUT_DIRECTORY_RELEASE "${CMAKE_CURRENT_BINARY_DIR}/package/eventgrid")
    set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELEASE "${CMAKE_CURRENT_BINARY_DIR}/package/eventgrid")
endif()

set(INCLUDE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/src)
set(SOURCE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/src)

set(SOURCE_FILES
    ${SOURCE_PATH}/Main.cpp
)

add_library(${PROJECT_NAME} SHARED ${SOURCE_FILES})
set_target_properties(${PROJECT_NAME} PROPERTIES PREFIX "")
set_target_properties(${PROJECT_NAME} PROPERTIES OUTPUT_NAME ${PROJECT_PYTHON_SHARED_LIB_NAME})
set_target_properties(${PROJECT_NAME} PROPERTIES SUFFIX ".pyd")

set_target_properties(${PROJECT_NAME} PROPERTIES COMPILE_FLAGS "${CMAKE_CXX_FLAGS} -I./include")
target_link_libraries(${PROJECT_NAME} LINK_PUBLIC pybind11 ${PYTHON_LIBRARY} ${CMAKE_THREAD_LIBS_INIT} ${CMAKE_LIBS_PLATFORM_SPECIFIC})

# Place the initialization and set file in the output directory for the Python bindings
configure_file(__init__.py
    ${CMAKE_CURRENT_BINARY_DIR}/package/eventgrid/__init__.py
)

configure_file(setup.py
    ${CMAKE_CURRENT_BINARY_DIR}/package/setup.py
)

# Use just one of these:
# GCC/clang:
#set(PYBIND11_CPP_STANDARD -std=c++11)
#set(PYBIND11_CPP_STANDARD -std=c++14)
#set(PYBIND11_CPP_STANDARD -std=c++1z) # Experimental C++17 support
# MSVC:
#set(PYBIND11_CPP_STANDARD /std:c++14)
#set(PYBIND11_CPP_STANDARD /std:c++latest) # Enables some MSVC C++17 features
#
#pybind11_add_module(${PROJECT_NAME} src/Main.cpp)
#
#message(">>>> ${CMAKE_CURRENT_SOURCE_DIR}")
#find_library(EVENT_GRID_CLIENT_CPP
#    NAMES event.grid-client.cpp
#    HINTS "./lib"
#    PATH_SUFFIXES lib
#    NO_DEFAULT_PATH)
#
#if (NOT EVENT_GRID_CLIENT_CPP)
#    message(FATAL_ERROR "Event.Grid Client C++ library not found ${EVENT_GRID_CLIENT_CPP}")
#endif()
#
##set_target_properties(${PROJECT_NAME} PROPERTIES COMPILE_FLAGS "${CMAKE_CXX_FLAGS} -I../event.grid-client.cpp/main/include -I./include")
##target_link_libraries(${PROJECT_NAME} LINK_PUBLIC ${CMAKE_THREAD_LIBS_INIT} -L../lib -levent.grid-client.cpp ${CMAKE_LIBS_PLATFORM_SPECIFIC})
#
#set_target_properties(${PROJECT_NAME} PROPERTIES COMPILE_FLAGS "${CMAKE_CXX_FLAGS} -I./include")
#target_link_libraries(${PROJECT_NAME} LINK_PUBLIC event.grid-client.cpp ${CMAKE_THREAD_LIBS_INIT} ${CMAKE_LIBS_PLATFORM_SPECIFIC})
