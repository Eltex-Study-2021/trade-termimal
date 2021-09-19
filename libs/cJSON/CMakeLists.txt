cmake_minimum_required(VERSION 2.6)
project(cJSON)
add_definitions(-Wall)

set(SRC cJSON.c)

add_library(${PROJECT_NAME} STATIC ${SRC})
install(FILES libcJSON.a DESTINATION ${PROJECT_SOURCE_DIR}/../build)
