add_executable(test_rectangle test_rectangle.c)
target_link_libraries(test_rectangle rectangle)
target_include_directories(test_rectangle PRIVATE ../third_party)
add_test(NAME test_rectangle COMMAND $<TARGET_FILE:test_rectangle>)
