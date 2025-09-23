cmake_minimum_required(VERSION 3.21)
project(Homework C)

include_directories(${PROJECT_SOURCE_DIR}/include)
add_subdirectory(src)
enable_testing()
add_subdirectory(tests)