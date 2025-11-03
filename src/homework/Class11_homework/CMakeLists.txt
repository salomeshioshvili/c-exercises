cmake_minimum_required(VERSION 3.21)
project(Class11_Homework C)

set(CMAKE_C_STANDARD 23)
set(CMAKE_C_STANDARD_REQUIRED ON)

# Build all exercises
add_executable(exercise1 exercise1_error_handling.c)
add_executable(exercise2 exercise2_logging_system.c)
add_executable(exercise3 exercise3_colored_logger.c)