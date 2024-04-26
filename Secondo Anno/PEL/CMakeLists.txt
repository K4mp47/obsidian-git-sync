# set minimum cmake version
cmake_minimum_required(VERSION 3.25)
# project name, version and language
project(PEL_project_2023 VERSION 0.0.1 LANGUAGES CXX)
# require a C++17
set(CMAKE_CXX_STANDARD 17)
# configure run-time flags
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Ofast -lstdc++ -std=c++17")

# testing
#enable_testing()

add_executable(
        #${PROJECT_NAME}_container_test
        #test/test.cpp
        #include/json.hpp src/json.cpp
)

add_test(
        NAME ${PROJECT_NAME}_campa_test
        COMMAND $<TARGET_FILE:${PROJECT_NAME}_container_test>
)

add_test(
        NAME ${PROJECT_NAME}_container_test
        COMMAND $<TARGET_FILE:${PROJECT_NAME}_container_test>
)

add_executable(
        #${PROJECT_NAME}_streaming_test
        #test/test_io.cpp
        #include/json.hpp src/json.cpp
)

add_test(
        NAME ${PROJECT_NAME}_streaming_test
        COMMAND $<TARGET_FILE:${PROJECT_NAME}_streaming_test>
)