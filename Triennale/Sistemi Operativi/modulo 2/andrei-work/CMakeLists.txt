cmake_minimum_required(VERSION 3.22)
project(OS_playground C)

set(CMAKE_C_STANDARD 11)

add_executable(forks forks.c)
add_executable(pipe pipes.c)
add_executable(wait wait.c)
add_executable(array_sum array_sum.c)
add_executable(multiple_children multiple_children.c)
add_executable(fifo fifo.c)
add_executable(write_pipe pipe_exercise/write_pipe.c)
add_executable(read_pipe pipe_exercise/read_pipe.c)