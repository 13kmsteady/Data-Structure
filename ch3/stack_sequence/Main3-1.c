/**
 * =========================================================
 *
 * 检验 Bo3-1 的主程序
 *
 * =========================================================
 */

#include "../../ch1/C1.h"

typedef int SElemType;

#include "C3-1.h"
#include "Bo3-1.c"

void print(SElemType e) {
    printf("%d ", e);
}

int main() {

    int j;
    SqStack s;
    SElemType e;

    InitStack(&s);
    for (j = 1; j <= 12; j++) {
        Push(&s, j);
    }
    printf("栈中元素依次为: ");
    StackTraverse(s,print);

    Pop(&s, &e);
    printf("弹出的栈顶元素 e = %d\n", e);

    printf("栈是否为空: %d(1: 空,0: 否)\n", StackEmpty(s));
    GetTop(s, &e);
    printf("栈顶元素 e = %d, 栈的长度为: %d\n", e, StackLength(s));

    ClearStack(&s);
    printf("清空栈后,栈是否为空: %d(1: 空,0: 否)\n", StackEmpty(s));

    DestroyStack(&s);
    printf("销毁栈后, s.top = %p, s.base = %p, s.stacksize = %d\n",s.top,s.base,s.stacksize);
    return 0;
}

/**
 * =========================================================
 *
 * 结果:

    栈中元素依次为: 1 2 3 4 5 6 7 8 9 10 11 12
    弹出的栈顶元素 e = 12
    栈是否为空: 0(1: 空,0: 否)
    栈顶元素 e = 11, 栈的长度为: 11
    清空栈后,栈是否为空: 1(1: 空,0: 否)
    销毁栈后, s.top = (nil), s.base = (nil), s.stacksize = 0

 * =========================================================
 */