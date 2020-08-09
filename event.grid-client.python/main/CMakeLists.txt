project(eventgrid)

pybind11_add_module(${PROJECT_NAME} src/Main.cpp)

#set_target_properties(${PROJECT_NAME} PROPERTIES COMPILE_FLAGS "${CMAKE_CXX_FLAGS} -I../event.grid-client.cpp/main/include -I./include")
#target_link_libraries(${PROJECT_NAME} LINK_PUBLIC ${CMAKE_THREAD_LIBS_INIT} -L../lib -levent.grid-client.cpp ${CMAKE_LIBS_PLATFORM_SPECIFIC})
set_target_properties(${PROJECT_NAME} PROPERTIES COMPILE_FLAGS "${CMAKE_CXX_FLAGS} -I./include")
target_link_libraries(${PROJECT_NAME} LINK_PUBLIC ${CMAKE_THREAD_LIBS_INIT} ${CMAKE_LIBS_PLATFORM_SPECIFIC})
