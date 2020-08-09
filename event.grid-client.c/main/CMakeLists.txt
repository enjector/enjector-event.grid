project(event.grid-client.c C)

set(INCLUDE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/include/event.grid/client)
set(SOURCE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/src)

set(SOURCE_FILES
    ${INCLUDE_PATH}/node_client.h
    ${SOURCE_PATH}/node_client.c
)

add_library(${PROJECT_NAME} ${SOURCE_FILES})

set_target_properties(${PROJECT_NAME} PROPERTIES COMPILE_FLAGS "${CMAKE_CXX_FLAGS} -I./include")
target_link_libraries(${PROJECT_NAME} LINK_PUBLIC event mbedtls ${CMAKE_THREAD_LIBS_INIT} ${CMAKE_LIBS_PLATFORM_SPECIFIC})

# Exports
target_include_directories(${PROJECT_NAME} PUBLIC
	$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
	$<INSTALL_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
)
