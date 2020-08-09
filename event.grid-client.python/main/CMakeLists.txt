project(event.grid-client.python)

# Use just one of these:
# GCC/clang:
#set(PYBIND11_CPP_STANDARD -std=c++11)
#set(PYBIND11_CPP_STANDARD -std=c++14)
#set(PYBIND11_CPP_STANDARD -std=c++1z) # Experimental C++17 support
# MSVC:
#set(PYBIND11_CPP_STANDARD /std:c++14)
#set(PYBIND11_CPP_STANDARD /std:c++latest) # Enables some MSVC C++17 features

pybind11_add_module(${PROJECT_NAME} src/Main.cpp)

message(">>>> ${CMAKE_CURRENT_SOURCE_DIR}")
find_library(EVENT_GRID_CLIENT_CPP
    NAMES event.grid-client.cpp
    HINTS "./lib"
    PATH_SUFFIXES lib
    NO_DEFAULT_PATH)

if (NOT EVENT_GRID_CLIENT_CPP)
    message(FATAL_ERROR "Event.Grid Client C++ library not found ${EVENT_GRID_CLIENT_CPP}")
endif()

#set_target_properties(${PROJECT_NAME} PROPERTIES COMPILE_FLAGS "${CMAKE_CXX_FLAGS} -I../event.grid-client.cpp/main/include -I./include")
#target_link_libraries(${PROJECT_NAME} LINK_PUBLIC ${CMAKE_THREAD_LIBS_INIT} -L../lib -levent.grid-client.cpp ${CMAKE_LIBS_PLATFORM_SPECIFIC})

set_target_properties(${PROJECT_NAME} PROPERTIES COMPILE_FLAGS "${CMAKE_CXX_FLAGS} -I./include")
target_link_libraries(${PROJECT_NAME} LINK_PUBLIC event.grid-client.cpp ${CMAKE_THREAD_LIBS_INIT} ${CMAKE_LIBS_PLATFORM_SPECIFIC})
