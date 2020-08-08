project(event.grid-client.java Java)

find_package(Java)
include(UseJava)

set(SOURCE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/src)

set(SOURCE_FILES
    ${SOURCE_PATH}/NodeClient.java
)

add_jar(${PROJECT_NAME}
 SOURCES ${SOURCE_FILES}
 MANIFEST ${SOURCE_PATH}/META-INF/MANIFEST.MF
 OUTPUT_DIR ${CMAKE_LIBRARY_OUTPUT_DIRECTORY}
 OUTPUT_NAME event.grid-client
 )
