project(event.grid-server)

set(INCLUDE_PATH_DAEMON ${CMAKE_CURRENT_SOURCE_DIR}/include/event.grid/)
set(SOURCE_PATH_DAEMON ${CMAKE_CURRENT_SOURCE_DIR}/src)

set(SOURCE_FILES
	${SOURCE_PATH_DAEMON}/main.cpp
)

add_executable (${PROJECT_NAME} ${SOURCE_FILES})

target_include_directories (${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries (${PROJECT_NAME} LINK_PUBLIC event.grid-server.core)

set_property(TARGET ${PROJECT_NAME} PROPERTY VS_DEBUGGER_WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
