cmake_minimum_required(VERSION 2.6)
project(net)

include_directories(${PROJECT_SOURCE_DIR}/)
include_directories(${PROJECT_SOURCE_DIR}/../)
include_directories(${PROJECT_SOURCE_DIR}/../../)

set(SOURCES net.c)

add_library(net STATIC ${SOURCES} ${HEADERS})
