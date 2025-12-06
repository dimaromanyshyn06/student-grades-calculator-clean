#ifndef PERSON_H
#define PERSON_H

#include <vector>
#include <string>
#include <iostream>

class Person {
private:
    std::string name;
    std::string surname;
    std::vector<int> homework;
    int exam;
    double finalAverage;
    double finalMedian;

public:
    // Constructors (rule of three)
    Person();
    Person(const Person& other);
    Person& operator=(const Person& other);
    ~Person();

    // I/O operators
    friend std::istream& operator>>(std::istream& in, Person& p);
    friend std::ostream& operator<<(std::ostream& out, const Person& p);

    // Grade calculation
    void calculateGrades();

    // Basic setters
    void setName(const std::string& n, const std::string& s);
    void setHomework(const std::vector<int>& hw);
    void setExam(int ex);

    // New unified setter (used for file loading)
    void setGrades(const std::vector<int>& hw, int examScore);

    // Getters
    std::string getName() const;
    std::string getSurname() const;

    double getFinalAverage() const { return finalAverage; }
    double getFinalMedian() const { return finalMedian; }
};

#endif
