cmake_minimum_required(VERSION 3.28)
project(RPNCalculator_HA_2024)

set(CMAKE_CXX_STANDARD 17)

include_directories(include)


add_executable(main_app src/main.cpp src/RPNCalculator.cpp
        include/RPNCalculator.h)

add_executable(stack_test tests/stack_test.cpp
        include/RPNCalculator.h)
target_link_libraries(stack_test gtest_main)  # Assuming you use Google Test


enable_testing()
include(GoogleTest)
gtest_discover_tests(stack_test)

add_executable(RPNCalculator_HA_2024 src/main.cpp
        include/RPNCalculator.h
        include/Stack.h
        src/RPNCalculator.cpp
        include/RPNCalculator.h
)
include(FetchContent)
FetchContent_Declare(
        googletest
        GIT_REPOSITORY https://github.com/google/googletest.git
        GIT_TAG release-1.10.0  # Specify the release you need
)
FetchContent_MakeAvailable(googletest)

enable_testing()

file(GLOB TEST_SOURCES "tests/*.cpp")
add_executable(my_test ${TEST_SOURCES}
        tests/stack_test.cpp
        tests/stack_test.cpp
        tests/RPNCalculator_test.cpp
        include/RPNCalculator.h)
target_link_libraries(my_test gtest_main)  # Link against gtest

include(GoogleTest)
gtest_discover_tests(my_test)
