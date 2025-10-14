cmake_minimum_required(VERSION 3.21)
project(Class7_homework C)

set(CMAKE_C_STANDARD 23)

add_library(rectangle src/rectangle.c)
target_include_directories(rectangle PUBLIC include)

add_executable(main src/main.c)
target_link_libraries(main rectangle)

enable_testing()
add_subdirectory(tests)