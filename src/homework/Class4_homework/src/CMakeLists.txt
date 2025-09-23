add_library(name_length name_length.c)
add_executable(main main.c)
target_link_libraries(main name_length)