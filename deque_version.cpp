#include <iostream>
#include <deque>
#include <vector>

#include "person.h"
#include "file_utils.h"
#include "timer.h"
#include "split_strategies.h"

int main() {
    std::string filename = "students_100000.txt";

    // Read using vector (fastest)
    std::vector<Person> vec = readStudentsFromFile(filename);

    // Convert vector → deque
    Timer tConvert;
    tConvert.start();
    std::deque<Person> students(vec.begin(), vec.end());
    tConvert.stop();

    std::cout << "Convert vector -> deque time: "
              << tConvert.elapsed() << " s\n";

    // --------------------------------
    // STRATEGY 1 — two containers
    // --------------------------------
    {
        std::deque<Person> failed, passed;

        Timer t1;
        t1.start();
        split_strategy1(students, failed, passed);
        t1.stop();

        std::cout << "Deque Strategy 1 time: "
                  << t1.elapsed() << " s\n";

        std::cout << "  Failed: " << failed.size()
                  << " | Passed: " << passed.size() << "\n\n";
    }

    // --------------------------------
    // STRATEGY 2 — one container
    // --------------------------------
    {
        std::deque<Person> base(students.begin(), students.end());
        std::deque<Person> failed;

        Timer t2;
        t2.start();
        split_strategy2(base, failed);
        t2.stop();

        std::cout << "Deque Strategy 2 time: "
                  << t2.elapsed() << " s\n";

        std::cout << "  Failed: " << failed.size()
                  << " | Passed: " << base.size() << "\n\n";
    }

    return 0;
}
