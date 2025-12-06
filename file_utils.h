#ifndef FILE_UTILS_H
#define FILE_UTILS_H

#include <vector>
#include <string>
#include <list>
#include <deque>
#include "person.h"

// Reading
std::vector<Person> readStudentsFromFile(const std::string& filename);
std::list<Person> readStudentsList(const std::string& filename);
std::deque<Person> readStudentsDeque(const std::string& filename);

// Writing
void writeStudentsToFile(const std::string& filename, const std::vector<Person>& students);
void writeStudentsToFile(const std::string& filename, const std::list<Person>& students);
void writeStudentsToFile(const std::string& filename, const std::deque<Person>& students);

// Generator (for test files)
void generateFile(const std::string& filename, int count);

#endif
