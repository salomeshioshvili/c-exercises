cmake_minimum_required(VERSION 3.21)
project(homework_8)

set(CMAKE_C_STANDARD 23)
set(CMAKE_C_STANDARD_REQUIRED ON)

set(PLPLOT_INCLUDE_DIR "$ENV{CONDA_PREFIX}/include")
set(PLPLOT_LIB_DIR "$ENV{CONDA_PREFIX}/lib")

add_executable(zipf zipf.c)
target_include_directories(zipf PRIVATE ${PLPLOT_INCLUDE_DIR})
target_link_directories(zipf PRIVATE ${PLPLOT_LIB_DIR})
target_link_libraries(zipf plplot)

install(TARGETS zipf DESTINATION bin)

# cmake -DCMAKE_INSTALL_PREFIX=$CONDA_PREFIX -B build
# cmake --build build
# ./build/zipf pg2701.txt output.dat --plot