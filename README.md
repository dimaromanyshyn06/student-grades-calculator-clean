 Student Grades Calculator — Final Project Report

This repository contains the full implementation and performance analysis of a student grade processing system using various data containers (vector, list, deque) and different splitting strategies.
Each release introduces new features, optimizations, refactoring, and performance improvements.

 Release v0.1 – Initial OOP Implementation
Implemented:

Class Person with:

name, surname

homework grades

exam grade

final average and median

Rule of Three:

Constructor

Copy constructor

Assignment operator

Destructor

Operator overloading:

>> input

<< output

Final grade calculation:

using average or median

Reads:

manual input

unlimited amount of homework

Outputs:

formatted table sorted by surname

This version uses std::vector for homework management only.

 Release v0.2 – Refactoring + File Input + Exceptions + Large Data Generation
Added:

Code separated into modules:

person.cpp/.h

file_utils.cpp/.h

main.cpp

Exceptions:

file not found

invalid format

Added random generator for:

10 000

100 000

1 000 000

10 000 000 student records

Implemented reading from large input files

Implemented sorted formatted output

Split students into:

failed (< 5.0)

passed (≥ 5.0)

Measured performance for:

reading

sorting

splitting

writing

 Release v0.25 – Comparison of Containers (Vector, List, Deque)
Implemented:

Full support for vector, list, deque

Separate executables:

vector_version

list_version

deque_version

Performance measurement for operations:

reading

sorting

splitting

writing results

Timer class for accurate measurement

Large dataset benchmarks collected

General Observations:

vector is fastest for sorting and STL algorithms

list is slow for sorting but fast for many erase operations

deque performance is between vector and list

 Release v1.0 – Final Optimized Version (Algorithms + Strategies)

This version optimizes the v0.25 implementation using advanced STL algorithms and comparing two splitting strategies.

 Splitting Strategies
Strategy 1 — Two-Container Split

Original container stays unchanged

Create:

failed

passed

Each student is copied into one of the two containers

High memory usage

Very fast execution for vector using std::partition_copy

Strategy 2 — One-Container Split

Create only failed

Move failed students there

Remove them from base container

Base container now contains only passed students

Uses:

std::stable_partition

std::remove_if

Much lower memory usage

Speed heavily dependent on container type

 Algorithms Used in Optimization

std::find

std::find_if

std::search

std::copy

std::remove

std::remove_if

std::remove_copy

std::remove_copy_if

std::transform

std::partition

std::stable_partition

These algorithms significantly reduce manual loops and improve maintainability and speed.

 Performance Summary
Vector

Fastest sorting

Fastest splitting using std::partition_copy

Best overall performance

List

Erase operations are fast

Sorting is very slow

Good for Strategy 2 when removing many elements

Deque

Middle performance

Sorting slower than vector

Still acceptable

Winner:
 Vector + Strategy 2 (optimized using erase-remove idiom)

 Usage Instructions
✔ Building with Makefile (Linux/MacOS/MinGW)

Run:

make


This generates:

vector_v1.exe

list_v1.exe

deque_v1.exe

To clean:

make clean

✔ Building with CMake (Windows/Linux/MacOS)
mkdir build
cd build
cmake ..
cmake --build .


Executables created:

vector_v1
list_v1
deque_v1

✔ Running Programs
Vector version:
./vector_v1

List version:
./list_v1

Deque version:
./deque_v1


Each version prints:

reading time

sorting time

splitting time (strategy 1 & 2)

counts of failed and passed students

✔ Repository Structure (Final Clean Version)
person.h / person.cpp
file_utils.h / file_utils.cpp
split_strategies.h
timer.h
main.cpp
list_version.cpp
deque_version.cpp
Makefile
CMakeLists.txt
README.md

 Final Notes

This project demonstrates deep understanding of:

OOP

Rule of three

STL containers

STL algorithms

Large dataset processing

Performance optimization

Clean architecture & modular design

Final release v1.0 is a complete, optimized, professional-grade implementation.