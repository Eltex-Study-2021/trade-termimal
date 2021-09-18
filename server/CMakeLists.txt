cmake_minimum_required(VERSION 2.6)
project(server)
add_definitions(-Wall)
include_directories(${PROJECT_SOURCE_DIR}/../libs)

add_executable(server main.c server.c)

