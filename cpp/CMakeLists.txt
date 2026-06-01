cmake_minimum_required(VERSION 3.20)

project(low_level_ml_cpp VERSION 0.1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_library(llml src/linalg/matrix.cpp src/linalg/vector.cpp)

target_include_directories(llml PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)

add_executable(basic_linalg examples/linalg/basic_linalg.cpp)

target_link_libraries(basic_linalg PRIVATE llml)

enable_testing()

add_executable(test_matrix tests/linalg/test_matrix.cpp)

target_link_libraries(test_matrix PRIVATE llml)

add_test(NAME test_matrix COMMAND test_matrix)

add_executable(test_vector tests/linalg/test_vector.cpp)

target_link_libraries(test_vector PRIVATE llml)

add_test(NAME test_vector COMMAND test_vector)