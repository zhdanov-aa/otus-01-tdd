cmake_minimum_required(VERSION 3.15)

project(otus-01-tdd LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_definitions(-DGTEST_LANGUAGE_CXX11)

include_directories(/usr/include)

set(SOURCE_FILES 
    ./tests/main.cpp 
    ./tests/QuadraticEquation_test.cpp
    QuadraticEquation.cpp
    )

find_package(Threads REQUIRED)
find_package(GTest REQUIRED)

add_executable(qe_test ${SOURCE_FILES})
target_link_libraries(qe_test PRIVATE ${GTEST_LIBRARIES} ${GTEST_MAIN_LIBRARIES} Threads::Threads)