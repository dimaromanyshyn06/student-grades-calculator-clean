#ifndef FILE_UTILS_H
#define FILE_UTILS_H

#include <vector>
#include <string>
#include "person.h"

// Read students from file
std::vector<Person> readStudentsFromFile(const std::string& filename);

// Write students to file
void writeStudentsToFile(const std::string& filename, const std::vector<Person>& students);

// Generator
void generateFile(const std::string& filename, int count);

#endif
