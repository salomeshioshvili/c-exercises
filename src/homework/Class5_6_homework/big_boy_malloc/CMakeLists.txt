cmake_minimum_required(VERSION 3.21)
project(big_boy_malloc C)

set(CMAKE_C_STANDARD 23)

add_library(malloc_functions src/library.c)
target_include_directories(malloc_functions PUBLIC include)

add_executable(big_boy_malloc src/main.c)
target_link_libraries(big_boy_malloc malloc_functions)

enable_testing()
add_subdirectory(tests)