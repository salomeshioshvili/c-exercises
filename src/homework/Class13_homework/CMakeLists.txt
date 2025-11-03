cmake_minimum_required(VERSION 3.10)
project(LinkedListHomework C)

set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED ON)

add_executable(linked_list_demo
    main.c
    linked_list.c
    linked_list.h
)

# add_executable(doubly_linked_list_demo
#     main_doubly.c
#     doubly_linked_list.c
#     doubly_linked_list.h
# )
