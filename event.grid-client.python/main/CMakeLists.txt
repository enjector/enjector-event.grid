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

include_directories(
    ${PYTHON_INCLUDE_DIRS}
    ${PYBIND11_INCLUDE_DIRS}
)

if(CMAKE_BUILD_TYPE MATCHES "Debug")
    set(CMAKE_LIBRARY_OUTPUT_DIRECTORY_DEBUG "${CMAKE_CURRENT_BINARY_DIR}/package/${PROJECT_PYTHON_SHARED_LIB_NAME}")
    set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG "${CMAKE_CURRENT_BINARY_DIR}/package/${PROJECT_PYTHON_SHARED_LIB_NAME}")
else()
    set(CMAKE_LIBRARY_OUTPUT_DIRECTORY_RELEASE "${CMAKE_CURRENT_BINARY_DIR}/package/${PROJECT_PYTHON_SHARED_LIB_NAME}")
    set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELEASE "${CMAKE_CURRENT_BINARY_DIR}/package/${PROJECT_PYTHON_SHARED_LIB_NAME}")
endif()

set(INCLUDE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/src)
set(SOURCE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/src)

set(SOURCE_FILES
    ${SOURCE_PATH}/Main.cpp
)

add_library(${PROJECT_NAME} SHARED ${SOURCE_FILES})
set_target_properties(${PROJECT_NAME} PROPERTIES PREFIX "")
set_target_properties(${PROJECT_NAME} PROPERTIES OUTPUT_NAME ${PROJECT_PYTHON_SHARED_LIB_NAME})

# Only for Windows
if(WIN32)
    set_target_properties(${PROJECT_NAME} PROPERTIES SUFFIX ".pyd")
endif()

set_target_properties(${PROJECT_NAME} PROPERTIES COMPILE_FLAGS "${CMAKE_CXX_FLAGS} -I./include")
target_link_libraries(${PROJECT_NAME} LINK_PUBLIC pybind11 event.grid-client.cpp ${PYTHON_LIBRARY} ${CMAKE_THREAD_LIBS_INIT} ${CMAKE_LIBS_PLATFORM_SPECIFIC})

# Place the initialization and set file in the output directory for the Python bindings
configure_file(__init__.py
    ${CMAKE_CURRENT_BINARY_DIR}/package/eventgrid/__init__.py
)
