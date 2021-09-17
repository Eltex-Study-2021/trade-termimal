cmake_minimum_required(VERSION 2.6)
project(parser)

include_directories(${PROJECT_SOURCE_DIR}/)
include_directories(${PROJECT_SOURCE_DIR}/../)
include_directories(${PROJECT_SOURCE_DIR}/../../)

set(SOURCES parser.c)

add_library(parser STATIC ${SOURCES} ${HEADERS})
