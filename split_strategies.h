#ifndef SPLIT_STRATEGIES_H
#define SPLIT_STRATEGIES_H

#include <algorithm>
#include <iterator>
#include "person.h"

inline bool is_failed(const Person& p) {
    return p.getFinalAverage() < 5.0;
}

// ---------------------------------------------
// STRATEGY 1 — Two-container split
// (copies students into failed and passed)
// ---------------------------------------------
template <typename Container>
void split_strategy1(const Container& students,
                     Container& failed,
                     Container& passed)
{
    failed.clear();
    passed.clear();

    std::partition_copy(
        students.begin(), students.end(),
        std::back_inserter(failed),   // students who failed (<5)
        std::back_inserter(passed),   // students who passed
        [](const Person& p) { return is_failed(p); }
    );
}

// ---------------------------------------------
// STRATEGY 2 — One-container split
// (moves failed into a new container and removes them from the base)
// ---------------------------------------------
template <typename Container>
void split_strategy2(Container& students,
                     Container& failed)
{
    failed.clear();

    // Partition so that PASS students are first, FAIL students after
    auto firstFail = std::stable_partition(
        students.begin(), students.end(),
        [](const Person& p) { return !is_failed(p); }
    );

    // Copy fail students into "failed"
    failed.insert(failed.end(), firstFail, students.end());

    // Erase failed from base container → leaves only passed students
    students.erase(firstFail, students.end());
}

#endif // SPLIT_STRATEGIES_H
