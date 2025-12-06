#ifndef TIMER_H
#define TIMER_H

#include <chrono>

class Timer {
private:
    std::chrono::high_resolution_clock::time_point start;

public:
    Timer() {
        start = std::chrono::high_resolution_clock::now();
    }

    // Reset timer
    void reset() {
        start = std::chrono::high_resolution_clock::now();
    }

    // Return elapsed time in seconds
    double elapsed() const {
        auto end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> diff = end - start;
        return diff.count();
    }
};

#endif
