project(client)
add_definitions(-Wall)

#include_directories(${PROJECT_SOURCE_DIR}/../libs/net)
#include_directories(${PROJECT_SOURCE_DIR}/../libs/list)
include_directories(${PROJECT_SOURCE_DIR}/)

include_directories(${PROJECT_SOURCE_DIR}/../libs)

add_executable(client main.c client.c)

#add_executable(client main_cli.c client.c)

target_link_libraries(client net list cli parser)
#target_link_libraries(client ${PROJECT_SOURCE_DIR}/../libs/build/liblist.a)
#target_link_libraries(client ${PROJECT_SOURCE_DIR}/../libs/build/libnet.a)
