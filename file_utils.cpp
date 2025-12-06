#include "file_utils.h"
#include <fstream>
#include <iostream>
#include <stdexcept>
using namespace std;

// ===============================
// READ: VECTOR
// ===============================
vector<Person> readStudentsFromFile(const string& filename) {
    ifstream file(filename);
    if (!file) throw runtime_error("File not found: " + filename);

    vector<Person> students;

    string name, surname;
    int hw1, hw2, hw3, hw4, hw5, exam;

    string header;
    getline(file, header); // skip header

    while (file >> name >> surname >> hw1 >> hw2 >> hw3 >> hw4 >> hw5 >> exam) {
        Person p;
        p.setName(name, surname);
        p.setGrades({hw1, hw2, hw3, hw4, hw5}, exam);
        p.calculateGrades();
        students.push_back(p);
    }
    return students;
}

// ===============================
// READ: LIST
// ===============================
list<Person> readStudentsList(const string& filename) {
    ifstream file(filename);
    if (!file) throw runtime_error("File not found: " + filename);

    list<Person> students;

    string name, surname;
    int hw1, hw2, hw3, hw4, hw5, exam;

    string header;
    getline(file, header);

    while (file >> name >> surname >> hw1 >> hw2 >> hw3 >> hw4 >> hw5 >> exam) {
        Person p;
        p.setName(name, surname);
        p.setGrades({hw1, hw2, hw3, hw4, hw5}, exam);
        p.calculateGrades();
        students.push_back(p);
    }
    return students;
}

// ===============================
// READ: DEQUE
// ===============================
deque<Person> readStudentsDeque(const string& filename) {
    ifstream file(filename);
    if (!file) throw runtime_error("File not found: " + filename);

    deque<Person> students;

    string name, surname;
    int hw1, hw2, hw3, hw4, hw5, exam;

    string header;
    getline(file, header);

    while (file >> name >> surname >> hw1 >> hw2 >> hw3 >> hw4 >> hw5 >> exam) {
        Person p;
        p.setName(name, surname);
        p.setGrades({hw1, hw2, hw3, hw4, hw5}, exam);
        p.calculateGrades();
        students.push_back(p);
    }
    return students;
}

// ===============================
// WRITE: VECTOR
// ===============================
void writeStudentsToFile(const string& filename, const vector<Person>& students) {
    ofstream out(filename);
    if (!out) throw runtime_error("Cannot open output file!");

    for (const Person& p : students)
        out << p << "\n";
}

// ===============================
// WRITE: LIST
// ===============================
void writeStudentsToFile(const string& filename, const list<Person>& students) {
    ofstream out(filename);
    if (!out) throw runtime_error("Cannot open output file!");

    for (const Person& p : students)
        out << p << "\n";
}

// ===============================
// WRITE: DEQUE
// ===============================
void writeStudentsToFile(const string& filename, const deque<Person>& students) {
    ofstream out(filename);
    if (!out) throw runtime_error("Cannot open output file!");

    for (const Person& p : students)
        out << p << "\n";
}

// ===============================
// FILE GENERATOR
// ===============================
void generateFile(const string& filename, int count) {
    ofstream out(filename);
    if (!out) throw runtime_error("Cannot create file!");

    out << "Name Surname HW1 HW2 HW3 HW4 HW5 Exam\n";

    for (int i = 1; i <= count; i++) {
        out << "Name" << i << " "
            << "Surname" << i << " ";

        for (int j = 0; j < 5; j++)
            out << (rand() % 10 + 1) << " ";

        out << (rand() % 10 + 1) << "\n";
    }
}
