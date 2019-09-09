/**
 * =========================================================
 *  
 * 栈的顺序存储表示
 *
 * =========================================================
 */

#define STACK_INIT_SIZE 10 // 存储空间初始分配量
#define STACK_INCREMENT 2 // 存储空间分配增量

typedef struct SqStack {
    SElemType *base; // 栈底指针,在栈构造之前和销毁之后, base 的值为 null
    SElemType *top; // 栈顶指针
    int stacksize; // 当前以分配的存储空间,以元素为单位
} SqStack;