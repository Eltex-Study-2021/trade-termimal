cmake_minimum_required(VERSION 2.6)
project(client)
add_definitions(-Wall)

#include_directories(${PROJECT_SOURCE_DIR}/../libs/net)
#include_directories(${PROJECT_SOURCE_DIR}/../libs/list)
include_directories(${PROJECT_SOURCE_DIR}/)
include_directories(${PROJECT_SOURCE_DIR}/../libs)

add_executable(client cli_client.c)
target_link_libraries(client net list cli parser)
#target_link_libraries(client ${PROJECT_SOURCE_DIR}/../libs/build/liblist.a)
#target_link_libraries(client ${PROJECT_SOURCE_DIR}/../libs/build/libnet.a)
