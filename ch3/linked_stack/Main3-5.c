/**
 * =========================================================
 *  
 * 检验 Bo3-5.c 的主 程序
 *
 * =========================================================
 */

#include "../../ch1/C1.h"

typedef int SElemType; // 定义栈的元素类型

#include "C3-2.h"
#include "Bo3-5.c"

void print(SElemType e) {
    printf("%d ", e);
}

int main() {

    int j;
    LinkStack s;
    SElemType e;

    InitStack(&s);
    for (j = 1; j <= 5; j++) {
        Push(&s, j * 2);
    }
    printf("栈中的元素,从栈底到栈顶依次为: ");
    StackTraverse(s, print);

    Pop(&s, &e);
    printf("弹出的栈顶元素为: %d\n", e);

    printf("栈空否: %d(1: 空,0: 否)", StackEmpty(s));

    GetTop(s, &e);
    printf("当前的栈顶元素为: %d,栈的长度为: %d\n", e, StackLength(s));

    ClearStack(&s);
    printf("清空栈后,栈空否: %d(1: 空,0:否), 栈的长度为: %d\n", StackEmpty(s), StackLength(s));
    printf("销毁栈后, s = %p\n", s);
    return 0;
}
