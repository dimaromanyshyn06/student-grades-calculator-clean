#include "file_utils.h"
#include <fstream>
#include <iostream>
#include <stdexcept>
using namespace std;

// Read students from file
vector<Person> readStudentsFromFile(const string& filename) {
    ifstream file(filename);
    if (!file) throw runtime_error("File not found: " + filename);

    vector<Person> students;

    string name, surname;
    while (file >> name >> surname) {
        Person p;
        p.setName(name, surname);

        vector<int> hw(5);
        for (int i = 0; i < 5; i++) file >> hw[i];

        int exam;
        file >> exam;

        p.setHomework(hw);
        p.setExam(exam);
        p.calculateGrades();

        students.push_back(p);
    }

    return students;
}

// Write to file
void writeStudentsToFile(const string& filename, const vector<Person>& students) {
    ofstream out(filename);
    if (!out) throw runtime_error("Cannot open output file");

    for (const Person& p : students)
        out << p << "\n";
}

// Generator
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
