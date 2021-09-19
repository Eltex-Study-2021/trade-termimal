project(test)
add_definitions(-Wall)

include_directories(${PROJECT_SOURCE_DIR}/../)
include_directories(${PROJECT_SOURCE_DIR}/../../)
include_directories(${PROJECT_SOURCE_DIR}/../../../)

add_executable(test test.c ../parser.c)
target_link_libraries(test net list parser cJSON)

