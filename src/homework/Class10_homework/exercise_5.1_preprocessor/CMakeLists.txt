cmake_minimum_required(VERSION 3.21)
project(homework_10)

set(CMAKE_C_STANDARD 23)

if(NOT DEFINED LANGUAGE)
    set(LANGUAGE "EN")
endif()

include_directories(include)
add_library(welcome src/welcome.c)

if(LANGUAGE STREQUAL "EN")
    target_compile_definitions(welcome PRIVATE LANGUAGE=EN)
elseif(LANGUAGE STREQUAL "ES")
    target_compile_definitions(welcome PRIVATE LANGUAGE=ES)
else()
    message(FATAL_ERROR "LANGUAGE must be EN or ES")
endif()

add_executable(main src/main.c)
target_link_libraries(main welcome)

enable_testing()

add_executable(test_welcome test/test_welcome.c)
target_link_libraries(test_welcome welcome)
target_include_directories(test_welcome PRIVATE test)

target_compile_definitions(test_welcome PRIVATE LANGUAGE=${LANGUAGE})

add_test(NAME test_welcome COMMAND test_welcome)
