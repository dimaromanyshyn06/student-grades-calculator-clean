#include <iostream>
#include <vector>
#include "person.h"
#include "file_utils.h"
#include "timer.h"
#include "split_strategies.h"

int main() {
    std::string filename = "students_100000.txt"; // тут став будь-який файл

    // ---------------------------
    // READ STUDENTS (VECTOR)
    // ---------------------------
    Timer t;
    t.start();
    std::vector<Person> students = readStudentsFromFile(filename);
    t.stop();

    std::cout << "Reading time (vector): "
              << t.elapsed() << " s\n";

    // ---------------------------
    // STRATEGY 1 — Two containers
    // ---------------------------
    {
        std::vector<Person> failed, passed;

        Timer t1;
        t1.start();
        split_strategy1(students, failed, passed);
        t1.stop();

        std::cout << "Strategy 1 (two containers) time: "
                  << t1.elapsed() << " s\n";

        std::cout << "  Failed: " << failed.size()
                  << " | Passed: " << passed.size() << "\n\n";
    }

    // ---------------------------
    // STRATEGY 2 — One container
    // ---------------------------
    {
        std::vector<Person> base = students; // копія, щоб не псувати students
        std::vector<Person> failed;

        Timer t2;
        t2.start();
        split_strategy2(base, failed);
        t2.stop();

        std::cout << "Strategy 2 (one container) time: "
                  << t2.elapsed() << " s\n";

        std::cout << "  Failed: " << failed.size()
                  << " | Passed: " << base.size() << "\n\n";
    }

    return 0;
}
