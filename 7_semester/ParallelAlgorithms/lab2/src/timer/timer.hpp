#include <chrono>


class Timer {
private:
    std::chrono::time_point<std::chrono::system_clock> startTime;
    std::chrono::time_point<std::chrono::system_clock> stopTime;
    bool isRunning;
public:
    Timer();
    void start();
    void stop();
    double elapsed() const;
};