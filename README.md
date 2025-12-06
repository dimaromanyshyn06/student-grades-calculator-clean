v0.25 — Performance Testing Using std::list and std::deque

In version v0.25, the project was extended to evaluate the performance of two additional Standard Library containers: std::list and std::deque.
The main goal of this version was to compare their efficiency in processing large datasets of students and to analyze the performance of different operations such as reading, sorting, splitting, and writing data.

1. Implementation of List and Deque Versions

Two new program variants were created:

list_version.cpp — processes student records using std::list

deque_version.cpp — processes the same logic using std::deque

Both versions reuse the core functionality from v0.2:

reading students from a file

sorting them by surname

splitting into “passed” (final ≥ 5.0) and “failed” (final < 5.0)

writing results into separate output files

2. Benchmark Datasets

The following datasets were used for testing:

File Name	Size
students_1000.txt	1 000 records
students_10000.txt	10 000 records
students_100000.txt	100 000 records
students_1000000.txt	1 000 000 records
students_10000000.txt	10 000 000 records

These datasets were generated earlier in version v0.2.

3. Operations Measured

A custom Timer class was used to measure the duration of the following tasks:

Reading input data

Sorting student records

Splitting them into passed/failed groups

Writing results to output files

Total execution time

4. Benchmark Results
List (std::list) Performance
Records	Total Time
1 000	~0.74 s
10 000	~0.74 s
100 000	~0.76 s
1 000 000	~7.52 s
10 000 000	~83.3 s
Deque (std::deque) Performance
Records	Total Time
1 000	~0.02 s
10 000	~0.15 s
100 000	~1.54 s
1 000 000	~19.32 s
10 000 000	~209.9 s
5. Analysis and Conclusions
Key Observations

std::deque is significantly faster on small datasets due to its efficient contiguous memory layout.

std::list performs better on extremely large datasets, especially during sorting, because list::sort() does not require element relocation.

Sorting dominates total execution time in both containers, especially for files with millions of records.

Final Conclusion

Both containers have advantages:

deque is ideal for fast operations on small and medium datasets.

list is more efficient when sorting very large datasets (1M+ records).

Version v0.25 completes the performance comparison stage of the project and provides insight into the trade-offs between different STL containers.