project(std)
cmake_minimum_required(VERSION 2.8)
aux_source_directory(. SRC_LIST)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -Werror=sign-compare")
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -Wall")


INCLUDE_DIRECTORIES(/home/pawwik/dev/std/)
INCLUDE_DIRECTORIES(/home/pawwik/dev/libcoap/)
add_executable(${PROJECT_NAME} ${SRC_LIST})

