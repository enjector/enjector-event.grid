project(event.grid-client.c.test C)

set(INCLUDE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/src)
set(SOURCE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/src)

set(SOURCE_FILES
	${SOURCE_PATH}/Main.cpp
)

add_executable (${PROJECT_NAME} ${SOURCE_FILES})

set_target_properties(${PROJECT_NAME} PROPERTIES COMPILE_FLAGS "${CMAKE_CXX_FLAGS}")

target_include_directories (${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries (${PROJECT_NAME} LINK_PUBLIC gtest gmock event.grid-client.c)

set_property(TARGET ${PROJECT_NAME} PROPERTY VS_DEBUGGER_WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
