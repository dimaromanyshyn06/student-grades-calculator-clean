#include "file_utils.h"
#include <iostream>

int main() {
    std::cout << "Generating files...\n";

    generateFile("students_1000.txt", 1000);
    std::cout << "Generated 1000\n";

    generateFile("students_10000.txt", 10000);
    std::cout << "Generated 10000\n";

    generateFile("students_100000.txt", 100000);
    std::cout << "Generated 100000\n";

    generateFile("students_1000000.txt", 1000000);
    std::cout << "Generated 1M\n";

    generateFile("students_10000000.txt", 10000000);
    std::cout << "Generated 10M\n";

    return 0;
}
