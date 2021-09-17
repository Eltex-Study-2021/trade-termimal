cmake_minimum_required(VERSION 2.6)
project(list)
include_directories(${PROJECT_SOURCE_DIR}/)

set(SOURCES list.c)
set(HEADERS list.h)
add_library(list STATIC ${SOURCES} ${HEADERS})
