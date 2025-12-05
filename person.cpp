#include "person.h"
#include <algorithm>
#include <numeric>
#include <iomanip>
#include <iostream>

Person::Person() : exam(0), finalAverage(0.0), finalMedian(0.0) {}

Person::Person(const Person& other)
    : name(other.name), surname(other.surname),
      homework(other.homework), exam(other.exam),
      finalAverage(other.finalAverage), finalMedian(other.finalMedian) {}

Person& Person::operator=(const Person& other) {
    if (this != &other) {
        name = other.name;
        surname = other.surname;
        homework = other.homework;
        exam = other.exam;
        finalAverage = other.finalAverage;
        finalMedian = other.finalMedian;
    }
    return *this;
}

Person::~Person() {}

std::istream& operator>>(std::istream& in, Person& p) {
    in >> p.name >> p.surname;
    return in;
}

std::ostream& operator<<(std::ostream& out, const Person& p) {
    out << std::left << std::setw(15) << p.name
        << std::left << std::setw(15) << p.surname
        << std::right << std::setw(10) << std::fixed << std::setprecision(2)
        << p.finalAverage;
    return out;
}

void Person::calculateGrades() {
    if (homework.empty()) {
        finalAverage = 0;
        finalMedian = 0;
        return;
    }

    double avg = std::accumulate(homework.begin(), homework.end(), 0.0) / homework.size();
    finalAverage = 0.4 * avg + 0.6 * exam;

    std::vector<int> sorted = homework;
    std::sort(sorted.begin(), sorted.end());

    double med;
    int n = sorted.size();
    if (n % 2 == 0) med = (sorted[n/2 - 1] + sorted[n/2]) / 2.0;
    else med = sorted[n/2];

    finalMedian = 0.4 * med + 0.6 * exam;
}

void Person::setName(const std::string& n, const std::string& s) {
    name = n;
    surname = s;
}

std::string Person::getName() const { return name; }
std::string Person::getSurname() const { return surname; }

void Person::setHomework(const std::vector<int>& hw) {
    homework = hw;
}

void Person::setExam(int ex) {
    exam = ex;
}

double Person::getFinalAverage() const {
    return finalAverage;
}
