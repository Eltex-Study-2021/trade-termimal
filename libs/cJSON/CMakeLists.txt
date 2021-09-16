project(cJSON)

add_definitions(-Wall)

set(SRC cJSON.c)

add_library(${PROJECT_NAME} STATIC ${SRC})

