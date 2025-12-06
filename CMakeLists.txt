cmake_minimum_required(VERSION 3.10)
project(StudentGrades LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Source files
set(SRC
    person.cpp
    file_utils.cpp
)

# Header files (for IDE visibility)
set(HDR
    person.h
    file_utils.h
    split_strategies.h
    timer.h
)

# Vector version
add_executable(vector_v1
    main.cpp
    ${SRC}
    ${HDR}
)

# List version
add_executable(list_v1
    list_version.cpp
    ${SRC}
    ${HDR}
)

# Deque version
add_executable(deque_v1
    deque_version.cpp
    ${SRC}
    ${HDR}
)
