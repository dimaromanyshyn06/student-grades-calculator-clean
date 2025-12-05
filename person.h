#ifndef PERSON_H
#define PERSON_H

#include <vector>
#include <string>

class Person {
private:
    std::string name;
    std::string surname;
    std::vector<int> homework;
    int exam;
    double finalAverage;
    double finalMedian;

public:
    Person();
    Person(const Person& other);
    Person& operator=(const Person& other);
    ~Person();

    friend std::istream& operator>>(std::istream& in, Person& p);
    friend std::ostream& operator<<(std::ostream& out, const Person& p);

    void calculateGrades();
    void setName(const std::string& n, const std::string& s);

    std::string getName() const;
    std::string getSurname() const;

    void setHomework(const std::vector<int>& hw);
    void setExam(int ex);

    double getFinalAverage() const;
};

#endif
