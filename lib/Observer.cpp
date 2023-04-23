#include "Observer.h"

#include <thread>
#include <unordered_map>
#include <boost/log/trivial.hpp>

void Observer::StartAndLogExecution() {
    static const std::unordered_map<Cycle::Status, std::string> status_convertor {
            {Cycle::Status::kProcessing, "Processing"},
            {Cycle::Status::kFinished, "Finished"},
            {Cycle::Status::kInterrupted, "Interrupted"}
    };
    const auto start = std::chrono::system_clock::now();
    Cycle cycle;
    std::thread th([](Cycle& cycle) {
        cycle.Execute();
    }, std::ref(cycle));


    auto v = (std::chrono::system_clock::now() - start);

    while (cycle.GetStatus() != Cycle::kFinished) {
        std::this_thread::sleep_for(update_frequency);

        const auto time_elapsed =
                std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now() - start);
        BOOST_LOG_TRIVIAL(info) << "STATUS:" << status_convertor.at(cycle.GetStatus()) << ", time elapsed: "
                                << time_elapsed << "ms";

        if (time_elapsed >= upper_bound) {
            cycle.Interrupt();
            break;
        }
    }
    th.join();

    const auto time_elapsed =
            std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now() - start);
    BOOST_LOG_TRIVIAL(info) << "STATUS:" << status_convertor.at(cycle.GetStatus()) << ", time elapsed: "
                            << time_elapsed << "ms";
}
