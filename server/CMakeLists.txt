project(server)
add_definitions(-Wall)

include_directories(${PROJECT_SOURCE_DIR}/)
include_directories(${PROJECT_SOURCE_DIR}/../libs)

add_executable(server main.c server.c)
target_link_libraries(server net list cli parser)
