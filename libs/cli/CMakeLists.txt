cmake_minimum_required(VERSION 2.6)
project(cli)
include_directories(${PROJECT_SOURCE_DIR}/)

set(SOURCES cli.c)
set(HEADERS cli.h)
add_library(cli STATIC ${SOURCES} ${HEADERS})

