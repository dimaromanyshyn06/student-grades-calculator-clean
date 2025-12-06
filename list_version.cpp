#include <iostream>
#include <list>
#include <vector>

#include "person.h"
#include "file_utils.h"
#include "timer.h"
#include "split_strategies.h"

int main() {
    std::string filename = "students_100000.txt";

    // We read using vector (faster), then copy into list
    std::vector<Person> vec = readStudentsFromFile(filename);

    Timer tConvert;
    tConvert.start();
    std::list<Person> students(vec.begin(), vec.end());
    tConvert.stop();

    std::cout << "Convert vector -> list time: " 
              << tConvert.elapsed() << " s\n";

    // ---------------------------
    // STRATEGY 1 — Two containers
    // ---------------------------
    {
        std::list<Person> failed, passed;

        Timer t1;
        t1.start();
        split_strategy1(students, failed, passed);
        t1.stop();

        std::cout << "List Strategy 1 time: " 
                  << t1.elapsed() << " s\n";

        std::cout << "  Failed: " << failed.size()
                  << " | Passed: " << passed.size() << "\n\n";
    }

    // ---------------------------
    // STRATEGY 2 — One container
    // ---------------------------
    {
        std::list<Person> base(students.begin(), students.end());
        std::list<Person> failed;

        Timer t2;
        t2.start();
        split_strategy2(base, failed);
        t2.stop();

        std::cout << "List Strategy 2 time: " 
                  << t2.elapsed() << " s\n";

        std::cout << "  Failed: " << failed.size()
                  << " | Passed: " << base.size() << "\n\n";
    }

    return 0;
}
