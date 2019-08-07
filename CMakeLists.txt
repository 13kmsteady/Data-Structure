cmake_minimum_required(VERSION 3.14)
project(Data_Structure C)

set(CMAKE_C_STANDARD 99)

add_executable(Data_Structur main.c)
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
add_executable(main2-2 ch2/linear_list_linked/head_node/Main2-2.c)
add_executable(main2-8 ch2/linear_list_linked/no_head_node/Main2-8.c)
add_executable(main2-4 ch2/linked_list_single_cycle/Main2-4.c)
add_executable(algo2-5 ch2/linear_list_linked/head_node/Algo2-5.c)
add_executable(algo2-12 ch2/linear_list_linked/head_node/Algo2-12.c)
add_executable(algo2-13 ch2/linear_list_linked/head_node/Algo2-13.c)
