cmake_minimum_required(VERSION 2.6)
project(cli)
include_directories(${PROJECT_SOURCE_DIR}/)
include_directories(${PROJECT_SOURCE_DIR}/../)
include_directories(${PROJECT_SOURCE_DIR}/../../)

set(SOURCES cli.c)
add_library(cli STATIC ${SOURCES} ${HEADERS})
install(FILES libcli.a DESTINATION ${PROJECT_SOURCE_DIR}/../build)
