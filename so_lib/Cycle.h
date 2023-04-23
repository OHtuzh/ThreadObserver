#pragma once

#include <chrono>
#include <atomic>

using namespace std::chrono_literals;

class Cycle {
public:
    enum Status : int;

    void Execute();

    void Interrupt();

    [[nodiscard]] Status GetStatus() const noexcept;

    enum Status : int {
        kProcessing,
        kFinished,
        kInterrupted
    };
private:
    static constexpr std::chrono::seconds timeout = std::chrono::seconds(TIMEOUT);
    static constexpr std::chrono::milliseconds sleep_time = std::chrono::milliseconds(SLEEP_TIME);

    std::atomic<Status> status_;
    std::atomic<bool> work_;
};
