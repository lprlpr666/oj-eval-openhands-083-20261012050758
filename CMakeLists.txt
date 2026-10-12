cmake_minimum_required(VERSION 3.1)
project(JosephusRing C)

set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED ON)

# Add executable
add_executable(code main.c)

# Set compiler flags
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Wextra -O2")