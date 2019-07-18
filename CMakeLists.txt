cmake_minimum_required(VERSION 3.14)
project(Data_Structure C)

set(CMAKE_C_STANDARD 99)

add_executable(Data_Structure main.c cmake-build-debug/ch1/C1.h cmake-build-debug/ch2/C2-1.h
        cmake-build-debug/ch1/C1-1.h cmake-build-debug/ch1/Bo1-1.c)

add_executable(algo1-1 cmake-build-debug/ch1/Algo1-1.c  cmake-build-debug/ch2/Bo2-1.c cmake-build-debug/ch2/Fun2-3.c )
add_executable(algo1-2 cmake-build-debug/ch1/Algo1-2.c)
add_executable(algo1-3 cmake-build-debug/ch1/Algo1-3.c)
add_executable(algo1-4 cmake-build-debug/ch1/Algo1-4.c)
add_executable(main1-1 cmake-build-debug/ch1/Main1-1.c)

# 算法 2.1
# 将所有在线性表 Lb 中,但不在 La 中的数据元素插入到 La 中
add_executable(algo2-1 cmake-build-debug/ch2/Algo2-1.c)

# 算法 2.2
# 已知线性表 La 和 Lb 中的数据元素按值非递减排列
# 合并 La 和 Lb 得到新的线性表 Lc. Lc 的数据元素也按值非递减排列
add_executable(algo2-2 cmake-build-debug/ch2/Algo2-2.c)

# 算法 2.7
add_executable(alog2-3 cmake-build-debug/ch2/Algo2-3.c)

add_executable(main2-1 cmake-build-debug/ch2/Main2-1.c)
