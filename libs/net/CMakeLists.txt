project(net)

include_directories(${PROJECT_SOURCE_DIR}/)
include_directories(${PROJECT_SOURCE_DIR}/../)

set(SOURCES net.c)

add_library(net STATIC ${SOURCES} ${HEADERS})
install(FILES libnet.a DESTINATION ${PROJECT_SOURCE_DIR}/../build)
