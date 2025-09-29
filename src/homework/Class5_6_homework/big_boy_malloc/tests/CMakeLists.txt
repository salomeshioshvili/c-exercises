add_executable(test_malloc_alt test_library.c)
target_link_libraries(test_malloc_alt malloc_functions)
target_include_directories(test_malloc_alt PRIVATE ../third_party)

add_test(NAME alternative_tests COMMAND $<TARGET_FILE:test_malloc_alt>)
