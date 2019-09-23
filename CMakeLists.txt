cmake_minimum_required(VERSION 3.14)
project(Data_Structure C)

set(CMAKE_C_STANDARD 99)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY cmake-build-debug/outpus)
add_executable(Data_Structure main.c)
add_executable(algo1-1 ch1/Algo1-1.c)
add_executable(algo1-2 ch1/Algo1-2.c)
add_executable(algo1-3 ch1/Algo1-3.c)
add_executable(algo1-4 ch1/Algo1-4.c)
add_executable(main1-1 ch1/Main1-1.c)

# 顺序线性表
add_executable(main2-1 ch2/linear_list_order/Main2-1.c)
add_executable(algo2-1 ch2/linear_list_order/Algo2-1.c)
add_executable(algo2-2 ch2/linear_list_order/Algo2-2.c)
add_executable(algo2-3 ch2/linear_list_order/Algo2-3.c)
add_executable(algo2-4 ch2/linear_list_order/Algo2-4.c)

# 链式线性表
add_executable(main2-2 ch2/linked_list_single/head_node/Main2-2.c)
add_executable(main2-8 ch2/linked_list_single/no_head_node/Main2-8.c)
add_executable(main2-4 ch2/linked_list_single_cycle/Main2-4.c)
add_executable(main2-5 ch2/linked_list_double/Main2-5.c)
add_executable(main2-6 ch2/linked_list_practical/Main2-6.c)
add_executable(algo2-5 ch2/linked_list_single/head_node/Algo2-5.c)
add_executable(algo2-10 ch2/linked_list_single_cycle/Algo2-10.c)
add_executable(algo2-11 ch2/linked_list_practical/Algo2-11.c)
add_executable(algo2-12 ch2/linked_list_single/head_node/Algo2-12.c)
add_executable(algo2-13 ch2/linked_list_single/head_node/Algo2-13.c)

# 栈
add_executable(main3-1 ch3/sequence_stack/Main3-1.c)
add_executable(main3-5 ch3/linked_stack/Main3-5.c)
add_executable(algo3-1 ch3/algo/Algo3-1.c)
add_executable(algo3-3 ch3/algo/Algo3-3.c)
add_executable(algo3-4 ch3/algo/Algo3-4.c)