project(parser)
include_directories(${PROJECT_SOURCE_DIR}/)

set(SOURCES parser.c)
set(HEADERS parser.h)
add_library(parser STATIC ${SOURCES} ${HEADERS})
#target_include_directories(lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
