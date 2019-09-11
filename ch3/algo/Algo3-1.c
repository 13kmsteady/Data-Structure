/**
 * =========================================================
 *
 * 进制转换
 *
 * =========================================================
 */

#define N 8 // 定义待转换的进制 n(二进制 ~ 九进制)

typedef int SElemType;

#include "../../ch1/C1.h"
#include "../sequence_stack/C3-1.h"
#include "../sequence_stack/Bo3-1.c"


/**
 * 将输入的 10 进制整数,转换为其 N 进制整数并输出
 */
void conversion() {
    SqStack s;
    unsigned n; // 非负整数
    SElemType e;

    InitStack(&s); // 初始话空栈
    printf("将十进制整数 n 转换为 %d 进制数,请输入: n( >=0 ) = ", N);
    scanf("%d", &n); // 输入非负十进制整数
    while (n) {
        Push(&s, n % N);
        n = n / N;
    }

    while (!StackEmpty(s)){
        Pop(&s, &e);
        printf("%d", e);
    }
    printf("\n");
}

int main() {

    conversion();

    return 0;
}
