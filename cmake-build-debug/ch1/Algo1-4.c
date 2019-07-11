#include "C1.h"

/**
 * =========================================================
 *
 * 展示 exit() 函数的作用
 *
 * =========================================================
 */

int a(int);

int main() {

    int i;
    printf("请输入i: ");
    scanf("%d", &i);
    printf("a(i)=%d\n", a(i));
    return 0;
}

int a(int i) {
    if (1 == i) {
        printf("退出程序的运行\n");
        exit(1);
    }
    return i;
}