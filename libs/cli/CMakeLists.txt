project(cli)
include_directories(${PROJECT_SOURCE_DIR}/)

set(SOURCES cli.c)
set(HEADERS cli.h)
add_library(cli STATIC ${SOURCES} ${HEADERS})
#target_include_directories(lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
