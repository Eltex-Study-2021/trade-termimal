cmake_minimum_required(VERSION 2.6)
project(server)
add_definitions(-Wall)

include_directories(${PROJECT_SOURCE_DIR}/../libs/net)
include_directories(${PROJECT_SOURCE_DIR}/../libs/list)
include_directories(${PROJECT_SOURCE_DIR}/)
include_directories(${PROJECT_SOURCE_DIR}/../libs)

add_executable(server main.c server.c)
target_link_libraries(server ${PROJECT_SOURCE_DIR}/../libs/build/libnet.a)
target_link_libraries(server ${PROJECT_SOURCE_DIR}/../libs/build/liblist.a)
