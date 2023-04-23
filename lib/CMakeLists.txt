add_library(
        observer
        Observer.h
        Observer.cpp
)

find_package(Boost 1.81 COMPONENTS log)
target_link_libraries(observer ${Boost_LIBRARIES})

target_link_libraries(observer ${CMAKE_SOURCE_DIR}/libcycle_so_lib.so)

target_compile_definitions(observer PUBLIC MAX_TIMEOUT=12 SLEEP_TIME TIMEOUT)