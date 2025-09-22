


add_executable(1-first-unit-test 1-first-unit-test.c)
target_include_directories(1-first-unit-test PRIVATE ${PROJECT_SOURCE_DIR}/third_party)
add_test(NAME 1-first-unit-test COMMAND 1-first-unit-test)



add_library(library library.c library.h)
add_executable(2-unit-test-library 2-unit-test-library.c)
target_link_libraries(2-unit-test-library library)
target_include_directories(2-unit-test-library PRIVATE ${PROJECT_SOURCE_DIR}/third_party)
add_test(NAME 2-unit-test-library COMMAND 2-unit-test-library)
