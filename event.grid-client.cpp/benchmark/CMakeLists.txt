project(event.grid-client.cpp.benchmark CXX)

set(INCLUDE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/src)
set(SOURCE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/src)

set(SOURCE_FILES
	${SOURCE_PATH}/Main.cpp
)

add_executable (${PROJECT_NAME} ${SOURCE_FILES})

target_include_directories (${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries (${PROJECT_NAME} LINK_PUBLIC benchmark event.grid-client.cpp)

set_property(TARGET ${PROJECT_NAME} PROPERTY VS_DEBUGGER_WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
