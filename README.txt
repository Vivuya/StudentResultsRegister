
BCS 2204 - DATA STRUCTURES AND ALGORITHMS
GROUP COURSEWORK 1

PROJECT: STUDENT RESULTS REGISTER
SCENARIO 6: DYNAMIC ARRAY WITH CAPACITY DOUBLING

1. PROJECT DESCRIPTION

This project implements a Student Results Register using a
custom Dynamic Array data structure in C++.

The system stores student IDs, names, courses and scores.
It supports adding, finding, removing, displaying, loading
and saving student records.

2. DATA STRUCTURE

The main data structure is a templated DynamicArray class.

Its capacity doubles whenever the current capacity is full.
This reduces the frequency of memory allocation.

3. ALGORITHMS

Insertion Sort:
Used to sort student records by score.

Merge Sort:
Used to sort student records by student ID.

Binary Search:
Used to find student records in an array sorted by ID.

4. PROJECT STRUCTURE

include/
    DynamicArray.h
    sorting.h
    searching.h

src/
    StudentResultsRegister.cpp
    CourseworkTests.cpp
    DynamicArrayTest.cpp

students.txt
students_updated.txt
README.txt

5. COMPILATION

Compile the main application:

g++ -std=c++17 -Wall -Wextra -pedantic src/StudentResultsRegister.cpp -o student_register

Run:

./student_register

Compile the coursework tests:

g++ -std=c++17 -Wall -Wextra -pedantic src/CourseworkTests.cpp -o coursework_tests

Run:

./coursework_tests

6. SAMPLE DATA

The students.txt file contains the initial student records.
The application saves updated records to students_updated.txt.

7. REQUIREMENTS

Compiler: GCC
Language standard: C++17
Primary data structure: Custom Dynamic Array
Sorting algorithms: Insertion Sort and Merge Sort
Searching algorithm: Iterative Binary Search
