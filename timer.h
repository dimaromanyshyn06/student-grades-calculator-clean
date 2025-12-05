#ifndef TIMER_H
#define TIMER_H

#include <chrono>

class Timer {
    std::chrono::time_point<std::chrono::high_resolution_clock> startTime;
public:
    Timer();
    double elapsed();
};

#endif
