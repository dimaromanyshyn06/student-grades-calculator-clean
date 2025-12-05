#include "timer.h"

Timer::Timer() {
    startTime = std::chrono::high_resolution_clock::now();
}

double Timer::elapsed() {
    auto end = std::chrono::high_resolution_clock::now();
    return std::chrono::duration<double>(end - startTime).count();
}
