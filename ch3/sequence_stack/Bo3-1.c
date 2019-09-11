/**
 * =========================================================
 *  
 * 顺序栈(存储结构由 C3-1.h 定义)的基本操作
 *
 * =========================================================
 */
#include "../../ch1/C1.h"

/**
 * 构造一个空栈
 *
 * @param S
 * @return
 */
void InitStack(SqStack *S) {

    S->base = (SElemType *) malloc(STACK_INIT_SIZE * sizeof(SElemType));
    if (!S->base) {
        exit(OVERFLOW);
    }

    S->top = S->base;
    S->stacksize = STACK_INIT_SIZE;
}


/**
 * 销毁栈 s, s 不存在
 *
 * @param S
 * @return
 */
Status DestroyStack(SqStack *S) {
    free(S->base);
    S->top = NULL;
    S->base = NULL;
    S->stacksize = 0;
}

/**
 * 把 s 置为空栈
 *
 * @param s
 * @return
 */
Status ClearStack(SqStack *S) {
    S->top = S->base;
}

/**
 * 若栈 s 为空栈,则返回 TRUE,否则返回 FALSE
 * @param S
 * @return
 */
Status StackEmpty(SqStack S) {
    if (S.top == S.base) {
        return TRUE;
    } else {
        return FALSE;
    }
}

/**
 * 返回 s 的 元素个数,即栈的长度
 *
 * @param s
 * @return
 */
int StackLength(SqStack S) {
    return S.top - S.base;
}

/**
 * 若栈不为空,则返回 s 的 栈顶元素,并返回 OK,否则返回 ERROR
 *
 * @param S
 * @param e
 * @return
 */
Status GetTop(SqStack S, SElemType *e) {
    if (S.top == S.base) {
        return ERROR;
    }

    *e = *(S.top - 1);
    return OK;
}

/**
 * 插入元素 e 为新的栈顶元素
 *
 * @param S
 * @param e
 * @return
 */
Status Push(SqStack *S, SElemType e) {

    if (S->top - S->base >= S->stacksize) { // 栈满,追加存储空间
        S->base = (SElemType *) realloc(S->base, (S->stacksize + STACK_INCREMENT) * sizeof(SElemType));
        if (!S->base) { // 存储分配失败
            exit(OVERFLOW);
        }
        S->top = S->base + S->stacksize;
        S->stacksize += STACK_INCREMENT;
    }

    *(S->top)++ = e;
}

/**
 * 若栈不为空,则删除 s 的栈顶元素(top 指针减 1),用 e 返回其值,并返回 OK,否则返回 ERROR
 *
 * @param S
 * @param e
 * @return
 */
Status Pop(SqStack *S, SElemType *e) {
    if (S->base == S->top) {
        return ERROR;
    }

    *e = *(--S->top);
    return OK;
}

/**
 * 从栈底到栈顶依次对栈中每个元素调用函数 visit(). 一旦 visit 失败,则操作失败
 *
 * @param s
 * @param visit
 * @return
 */
Status StackTraverse(SqStack S, void (*visit)(SElemType)) {

    while (S.base != S.top) {
        visit(*S.base++);
    }
    printf("\n");
}

