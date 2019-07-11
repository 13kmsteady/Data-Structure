#include <stdio.h>

/**
 * =========================================================
 *
 * 用函数指针代替 c++ 的引用参数
 * =========================================================
 */

void fa(int);

void fb(int*);

int main() {
    int n = 1;
    printf("在主程序中,调用函数 fa 之前: n=%d\n", n);

    fa(n);
    printf("在主程序中,调用函数 fa 之后,调用函数 fb 之前: n=%d\n", n);

    fb(&n);
    printf("在主程序中,调用函数 fb 之后: n=%d\n", n);
    return 0;
}

/**
 * 在函数中改变 a, 但不会影响主调函数中的值
 * @param a
 */
void fa(int a) {
    a++;
    printf("在函数 fa 中: a=%d\n", a);
}

/**
 * a 是指针类型, 改变 a 的值,将影响主调函数中的值
 * @param a
 */
void fb(int *a) {
    (*a)++;
    printf("在函数 fb 中: *a=%d\n", *a);
}