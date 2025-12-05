#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <algorithm>
#include "person.h"
#include "file_utils.h"
#include "timer.h"

using namespace std;

int main() {
    Timer programTimer;  // Start measuring execution time

    cout << "==== STUDENT PROCESSOR V0.2 ====\n";
    cout << "1 - Read students from file\n";
    cout << "2 - Generate student files (10k, 100k, 1M, 10M)\n";
    cout << "Choose option: ";

    int choice;
    cin >> choice;

    if (choice == 2) {
        cout << "Generating files... This may take some time.\n";

        generateFile("students_10000.txt", 10000);
        generateFile("students_100000.txt", 100000);
        generateFile("students_1000000.txt", 1000000);
        generateFile("students_10000000.txt", 10000000);

        cout << "Files generated successfully.\n";
        return 0;
    }

    string filename;
    cout << "Enter file name: ";
    cin >> filename;

    Timer loadTimer;
    vector<Person> students = readStudentsFromFile(filename);
    double loadTime = loadTimer.elapsed();

    cout << "Loaded " << students.size() << " students in "
         << loadTime << " sec.\n";

    // SORTING
    Timer sortTimer;
    sort(students.begin(), students.end(),
         [](const Person& a, const Person& b) {
             return a.getSurname() < b.getSurname();
         });
    double sortTime = sortTimer.elapsed();

    cout << "Sorting completed in " << sortTime << " sec.\n";

    // SPLIT INTO FAILED AND PASSED
    Timer splitTimer;
    vector<Person> failed, passed;

    for (const auto& s : students) {
        if (s.getFinalAverage() < 5.0)
            failed.push_back(s);
        else
            passed.push_back(s);
    }

    double splitTime = splitTimer.elapsed();
    cout << "Splitting completed in " << splitTime << " sec.\n";

    // WRITE TO OUTPUT FILES
    Timer writeTimer;
    writeStudentsToFile("failed.txt", failed);
    writeStudentsToFile("passed.txt", passed);
    double writeTime = writeTimer.elapsed();

    cout << "Writing completed in " << writeTime << " sec.\n";

    cout << "\n==== SUMMARY ====\n";
    cout << "Loading:  " << loadTime << " sec\n";
    cout << "Sorting:  " << sortTime << " sec\n";
    cout << "Splitting:" << splitTime << " sec\n";
    cout << "Writing:  " << writeTime << " sec\n";
    cout << "TOTAL:    " << programTimer.elapsed() << " sec\n";

    return 0;
}
