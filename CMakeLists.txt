cmake_minimum_required(VERSION 3.22)
# Our Project
project(tree-benchmark)
add_executable(${PROJECT_NAME} main.cpp abp.cpp avl.cpp)
target_include_directories(tree-benchmark PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(${PROJECT_NAME})