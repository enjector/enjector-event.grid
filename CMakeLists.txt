project(event.grid)

cmake_minimum_required (VERSION 3.7.2)
#cmake_minimum_required (VERSION 3.15.1)

set(TMPDIR "${CMAKE_BINARY_DIR}/tmp")

if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE "Release")
#  set(CMAKE_BUILD_TYPE $ENV{BUILD_TYPE})
endif()

message(STATUS "Build type: ${CMAKE_BUILD_TYPE}")
message(STATUS "Architecture: ${ARCHITECTURE}")

# Defaults
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY_DEBUG ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY_DEBUG ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY_RELEASE ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY_RELEASE ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELEASE ${CMAKE_BINARY_DIR}/bin)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

set(CMAKE_SHARED_LIBRARY_PREFIX_C "")
set(CMAKE_SHARED_LIBRARY_PREFIX_CXX "")
#set(CMAKE_REQUIRED_DEFINITIONS "-std=c++14")

if(WIN32)
  # Windows
  message("Configuring for Windows")
  if(CMAKE_BUILD_TYPE MATCHES "Debug")
    set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} /MTd /bigobj /Zi /EHsc")
    set(CMAKE_CXX_FLAGS_PLATFORM_SPECIFIC "-D_WIN32 -D_DEBUG")
    SET(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} /DEBUG /MACHINE:X64")
#    SET(CMAKE_SHARED_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} /DEBUG")
  else()
    set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} /MD /bigobj /EHsc")
    set(CMAKE_CXX_FLAGS_PLATFORM_SPECIFIC "-D_WIN32 -D_M_IX86")
    SET(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} /MACHINE:X64")
  endif()
else()
  # Other - Linux
  message("Configuring for Linux")
  set_property(GLOBAL PROPERTY TARGET_SUPPORTS_SHARED_LIBS TRUE)
  SET(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -Wl,-rpath -Wl,../lib")

  find_package (Threads REQUIRED)
  if(CMAKE_BUILD_TYPE MATCHES "Debug")
    set(CMAKE_CXX_FLAGS_PLATFORM_SPECIFIC "-D_LINUX -D_DEBUG -g -fprofile-arcs -fPIC -O0")
    set(CMAKE_LIBS_PLATFORM_SPECIFIC "-ldl -lm -lrt -static-libgcc -static-libstdc++")
  else()
    set(CMAKE_CXX_FLAGS_PLATFORM_SPECIFIC "-D_LINUX -Wall -fPIC -O3")
    set(CMAKE_LIBS_PLATFORM_SPECIFIC "-ldl -lm -lrt -static-libgcc -static-libstdc++")
  endif()
endif()

if(CMAKE_BUILD_TYPE MATCHES "Debug")
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS_DEBUG} ${CMAKE_CXX_FLAGS_PLATFORM_SPECIFIC}")
  set(CMAKE_C_FLAGS "${CMAKE_CXX_FLAGS_DEBUG} ${CMAKE_CXX_FLAGS_PLATFORM_SPECIFIC}")
else()
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS_RELEASE} ${CMAKE_CXX_FLAGS_PLATFORM_SPECIFIC}")
  set(CMAKE_C_FLAGS "${CMAKE_CXX_FLAGS_RELEASE} ${CMAKE_CXX_FLAGS_PLATFORM_SPECIFIC}")
endif()

###############################################################################
# Dependencies
###############################################################################
#set(CMAKE_CROSSCOMPILING TRUE CACHE BOOL "")
#set(CMAKE_C_COMPILER_WORKS TRUE CACHE BOOL "")
#set(CMAKE_CXX_COMPILER_WORKS TRUE CACHE BOOL "")
#set(HAVE_STD_REGEX FALSE CACHE BOOL "")
#set(HAVE_POSIX_REGEX FALSE CACHE BOOL "")

set(GTEST_CREATE_SHARED_LIBRARY TRUE CACHE BOOL "")
#set(ALLOW_DUPLICATE_CUSTOM_TARGETS TRUE)

# build google benchmark (target: benchmark)
# do not build tests of benchmarking lib
set(BENCHMARK_ENABLE_TESTING OFF CACHE BOOL "Suppressing benchmark's tests" FORCE)
add_subdirectory(deps/googlebenchmark-1.5.1 EXCLUDE_FROM_ALL)

# build tests (targets: gtest_main, gtest)
add_subdirectory(deps/googletest-1.10.0 EXCLUDE_FROM_ALL)

# build spdlog
add_subdirectory(deps/spdlog-1.7.0 EXCLUDE_FROM_ALL)

# build libevent
#set(EVENT__DISABLE_OPENSSL TRUE CACHE BOOL "")
set(EVENT__DISABLE_REGRESS TRUE CACHE BOOL "")
SET(EVENT__LIBRARY_TYPE STATIC CACHE STRING "EVENT__LIBRARY_TYPE" FORCE)
SET(EVENT__DISABLE_OPENSSL ON CACHE BOOL "EVENT__DISABLE_OPENSSL" FORCE)
#set(EVENT__LIBRARY_TYPE "STATIC")
add_subdirectory(deps/libevent-2.1.12 EXCLUDE_FROM_ALL)

# build mbedtls
add_subdirectory(deps/mbedtls-2.23.0 EXCLUDE_FROM_ALL)

if(NOT CMAKE_BUILD_FOR_DOCKER_IMAGE)
    add_subdirectory(deps/pybind11-2.5.0)
endif()

###############################################################################
# Event Grid
###############################################################################
add_subdirectory(event.grid-node)

if(NOT CMAKE_BUILD_FOR_DOCKER_IMAGE)
    add_subdirectory(event.grid-client.cpp)
    add_subdirectory(event.grid-client.c)
    add_subdirectory(event.grid-client.java)
    add_subdirectory(event.grid-client.python/main)

    if(WIN32)
       add_subdirectory(event.grid-client.dotnet)
    endif()
endif()

set(CPACK_PACKAGE_NAME "enjector-event.grid")
set(CPACK_PACKAGE_VENDOR "Enjector Software Ltd.")
set(CPACK_VERBATIM_VARIABLES true)
set(CPACK_PACKAGE_VERSION_MAJOR 0)
set(CPACK_PACKAGE_VERSION_MINOR 0)
set(CPACK_PACKAGE_VERSION_PATCH 1)
set(CPACK_GENERATOR DEB)
set(CPACK_DEB_COMPONENT_INSTALL ON)
set(CPACK_DEBIAN_PACKAGE_MAINTAINER "Enjector Software <contact@enjector.com>")
include(CPack)
