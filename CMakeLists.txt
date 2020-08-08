project(Enjector.EventGrid.Server)

cmake_minimum_required (VERSION 3.5.1)

set(TMPDIR "${CMAKE_BINARY_DIR}/tmp")

if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE $ENV{BUILD_TYPE})
endif()

# Defaults
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY_DEBUG ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY_DEBUG ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY_RELEASE ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY_RELEASE ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELEASE ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_SHARED_LIBRARY_PREFIX_C "")
set(CMAKE_SHARED_LIBRARY_PREFIX_CXX "")
set(CMAKE_REQUIRED_DEFINITIONS "-std=c++11")

message(STATUS "Build type: ${CMAKE_BUILD_TYPE}")

if(WIN32)
  # Windows
  message("Configuring for Windows")
  set(MSVC, true)
  if(CMAKE_BUILD_TYPE MATCHES "Debug")
    set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} /MDd /bigobj /Zi /EHsc")
    set(CMAKE_CXX_FLAGS_PLATFORM_SPECIFIC "-D_WIN32 -D_DEBUG")
    SET(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} /DEBUG")
    SET(CMAKE_SHARED_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} /DEBUG")
  else()
    set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} /MD /bigobj /EHsc")
    set(CMAKE_CXX_FLAGS_PLATFORM_SPECIFIC "-D_WIN32 -D_M_IX86")
  endif()
else()
  # Other - Linux
  message("Configuring for Linux")
  set_property(GLOBAL PROPERTY TARGET_SUPPORTS_SHARED_LIBS TRUE)
  SET(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -Wl,-rpath -Wl,../lib")

   find_package (Threads REQUIRED)
  if(CMAKE_BUILD_TYPE MATCHES "Debug")
    set(CMAKE_CXX_FLAGS_PLATFORM_SPECIFIC "-D_LINUX -D_DEBUG -g -fprofile-arcs -fPIC -O0")
    set(CMAKE_LIBS_PLATFORM_SPECIFIC "-ldl -lm -lrt -static-libgcc -static-libstdc++ -Wl,-t ${CMAKE_LIBS_PLATFORM_SPECIFIC}")
  else()
    set(CMAKE_CXX_FLAGS_PLATFORM_SPECIFIC "-D_LINUX -Wall -fPIC -fpic -O3 -Wl,-t")
    set(CMAKE_LIBS_PLATFORM_SPECIFIC "-ldl -lm -lrt -static-libgcc -static-libstdc++ -Wl,-t ${CMAKE_LIBS_PLATFORM_SPECIFIC}")
  endif()
endif()

if(CMAKE_BUILD_TYPE MATCHES "Debug")
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS_DEBUG} ${CMAKE_CXX_FLAGS_PLATFORM_SPECIFIC}")
else()
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS_RELEASE} ${CMAKE_CXX_FLAGS_PLATFORM_SPECIFIC}")
endif()

###############################################################################
# Dependencies
###############################################################################
set(CMAKE_CROSSCOMPILING TRUE CACHE BOOL "")
set(CMAKE_C_COMPILER_WORKS TRUE CACHE BOOL "")
set(CMAKE_CXX_COMPILER_WORKS TRUE CACHE BOOL "")
set(HAVE_STD_REGEX FALSE CACHE BOOL "")
set(HAVE_POSIX_REGEX FALSE CACHE BOOL "")

# build google benchmark (target: benchmark)
# do not build tests of benchmarking lib
set(BENCHMARK_ENABLE_TESTING OFF CACHE BOOL "Suppressing benchmark's tests" FORCE)
add_subdirectory(deps/googlebenchmark-1.5.1)

# build tests (targets: gtest_main, gtest)
add_subdirectory(deps/googletest-1.10.0)

# build spdlog
add_subdirectory(deps/spdlog-1.7.0)

# build libevent
set(EVENT__DISABLE_OPENSSL TRUE CACHE BOOL "")
add_subdirectory(deps/libevent-2.1.12)

