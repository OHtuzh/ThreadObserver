#include "Cycle.h"

#include <thread>

void Cycle::Execute() {
    status_ = kProcessing;
    work_ = true;
    const auto iterations = (timeout + sleep_time - 1ms) / sleep_time;

    for (auto it = 0; it < iterations; ++it) {
        std::this_thread::sleep_for(sleep_time);
        if (!work_) {
            status_ = kInterrupted;
            return;
        }
    }
    status_ = kFinished;
}

Cycle::Status Cycle::GetStatus() const noexcept {
    return status_;
}

void Cycle::Interrupt() {
    work_ = false;
}
