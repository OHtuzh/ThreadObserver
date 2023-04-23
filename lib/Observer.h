#pragma once


#include "../so_lib/Cycle.h"

class Observer {
public:
    static void StartAndLogExecution();
private:
    // You can change this variable and it would affect on result
    // 15s for finished, 7 for interrupt for example
    static constexpr std::chrono::seconds upper_bound = std::chrono::seconds(MAX_TIMEOUT);

    static constexpr std::chrono::milliseconds update_frequency = 500ms;

};
