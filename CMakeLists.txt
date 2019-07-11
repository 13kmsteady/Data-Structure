cmake_minimum_required(VERSION 3.14)
project(Data_Structure C)

set(CMAKE_C_STANDARD 99)

add_executable(Data_Structure main.c cmake-build-debug/ch1/C1.h cmake-build-debug/ch1/C1-1.h  cmake-build-debug/ch1/Bo1-1.c)

add_executable(algo1-1 cmake-build-debug/ch1/Algo1-1.c cmake-build-debug/ch2/Algo2-1.c cmake-build-debug/ch2/C2-1.h cmake-build-debug/ch2/Bo2-1.c)
add_executable(algo1-2 cmake-build-debug/ch1/Algo1-2.c)
add_executable(algo1-3 cmake-build-debug/ch1/Algo1-3.c)
add_executable(algo1-4 cmake-build-debug/ch1/Algo1-4.c)
add_executable(main1-1 cmake-build-debug/ch1/Main1-1.c)