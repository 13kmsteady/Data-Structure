/**
 * =========================================================
 *  
 * 链栈(存储结构有 C2-2.h 定义)的基本操作
 *
 * =========================================================
 */

#define DestroyStack ClearStack

/**
 * 构造一个空的链栈
 *
 * @param S
 */
void InitStack(LinkStack *S) {
    *S = NULL;
}

/**
 * 销毁 S
 *
 * @param S
 */
void DestroyStack(LinkStack *S) {
    LinkStack p;
    while (*S) {
        p = (*S)->next;
        free(p);
        *S = p;
    }
}

/**
 * 若 S 为空,返回 TRUE,否则返回 FALSE
 */
Status StackEmpty(LinkStack S) {
    if (S) {
        return FALSE;
    } else {
        return TRUE;
    }
}

/**
 * 返回 S 的长度
 */
int StackLength(LinkStack S) {
    int j = 0;
    while (S) {
        j++;
        S = S->next;
    }
    return j;
}

/**
 * 若栈不为空,则用 e 返回 S 的栈顶元素.并返回 OK, 否则返回 ERROR
 *
 * @param S
 * @param e
 * @return
 */
Status GetTop(LinkStack S, SElemType *e) {
    if (NULL != S) {
        *e = S->data;
        return OK;
    } else {
        return ERROR;
    }
}

/**
 * 插入元素 e 为新的栈顶元素
 *
 * @param S
 * @param e
 * @return
 */
Status Push(LinkStack *S, SElemType e) {
    LinkStack p;
    p = (LinkStack) malloc(sizeof(struct SNode));
    p->data = e;
    p->next = *S;
    *S = p;
}

/**
 * 若栈不为空, 则删除 S 的栈顶元素,用 e 返回其值,并返回 OK,否则返回 ERROR
 *
 * @param S
 * @param e
 * @return
 */
Status Pop(LinkStack *S, SElemType *e) {
    if (NULL == *S) {
        return ERROR;
    } else {
        LinkStack p = *S;
        *e = p->data;
        *S = p->next;
        free(p);
        return OK;
    }
}

/**
 * 从栈底到栈顶,依次对栈中每个元素调用函数 visit()
 *
 * @param S
 * @param visit
 */
void StackTraverse(LinkStack S, void(*visit)(SElemType)) {

    LinkStack temp;
    InitStack(&temp);
    while (S) {
        Push(&temp, S->data);
        S = S->next;
    }

    while (temp) {
        visit(temp->data);
        temp = temp->next;
    }
    printf("\n");
}
