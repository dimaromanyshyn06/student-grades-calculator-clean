#include <iostream>
#include <list>
#include <algorithm>
#include "file_utils.h"
#include "timer.h"

int main() {
    std::string filename = "students_10000000.txt";


    Timer t_total;
    Timer t;

    std::cout << "Reading list...\n";
    t.reset();
    std::list<Person> students = readStudentsList(filename);
    std::cout << "Read time: " << t.elapsed() << " s\n";

    // SORT
    std::cout << "Sorting...\n";
    t.reset();
    students.sort([](const Person& a, const Person& b) {
        return a.getSurname() < b.getSurname();
    });
    std::cout << "Sort time: " << t.elapsed() << " s\n";

    // SPLIT
    std::cout << "Splitting...\n";
    t.reset();
    std::list<Person> failed, passed;

    for (const auto& s : students) {
        if (s.getFinalAverage() < 5.0)
            failed.push_back(s);
        else
            passed.push_back(s);
    }
    std::cout << "Split time: " << t.elapsed() << " s\n";

    // WRITE TO FILES
    std::cout << "Writing failed.txt...\n";
    t.reset();
    writeStudentsToFile("failed_list.txt", failed);
    std::cout << "Write time (failed): " << t.elapsed() << " s\n";

    std::cout << "Writing passed_list.txt...\n";
    t.reset();
    writeStudentsToFile("passed_list.txt", passed);
    std::cout << "Write time (passed): " << t.elapsed() << " s\n";

    std::cout << "\nTOTAL TIME: " << t_total.elapsed() << " s\n";

    return 0;
}
