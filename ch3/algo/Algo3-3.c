/**
 * =========================================================
 *
 * 括号匹配的检验
 *
 * =========================================================
 */

typedef char SElemType;

#include "../../ch1/C1.h"
#include "../sequence_stack/C3-1.h"
#include "../sequence_stack/Bo3-1.c"

/**
 * 对于输入的任何一个字符串,检验括号是否匹配
 *
 * 算法思路
 *      1. 如果是左括号入栈
 *      2. 如果是右括号,和栈顶的元素比较
 *              判读栈是否为空
 *                  1. 栈为空,说明缺少左括号
 *                  2. 栈不为空,栈顶元素出栈,和右括号比较.如果不匹配,退出应用程序
 *
 *      3. 如果是其它字符,字符指针后移
 *      4. 字符串结束时,栈为空,说明括号匹配.否则不匹配
 */
void check() {

    SqStack s;
    SElemType ch[80] = "{([])}", *p, e;
    InitStack(&s); // 初始化空栈

    p = ch; // p 指向字符串的首字符
    while (*p) {
        switch (*p) {
            case '(':
            case '[':
            case '{':
                Push(&s, *p++); // 左括号入栈, 字符指针后移
                break;
            case ')':
            case ']':
            case '}':
                if (!StackEmpty(s)) {
                    Pop(&s, &e); // 弹出栈顶元素,并赋值给 e
                    if (!(e == '(' && *p == ')' || e == '[' && *p == ']' ||
                          e == '{' && *p == '}')) {
                        printf("左右括号不配对\n");
                        exit(ERROR);
                    }
                } else {
                    // 栈为空
                    printf("缺乏左括号,栈为空\n");
                    exit(ERROR);
                }
            default:
                p++;
                break;
        }
    }
    if (StackEmpty(s)) { // 字符串结束时栈空
        printf("括号匹配\n");
    } else {
        printf("缺少右括号\n");
    }
}

int main() {
    check();
    return 0;
}