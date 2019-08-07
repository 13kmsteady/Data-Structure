/**
 * =========================================================
 *
 * 设立尾指针的单循环链表(存储结构由 C2-2.h 定义)的 12 个基本操作
 *
 * =========================================================
 */

/**
 * 操作结果: 构造一个空的线性表
 * @param L
 */
void InitList(LinkList *L) {
    *L = (LinkList) malloc(sizeof(struct LNode)); // 生成一个头结点,并使 L 指向头结点
    if (!*L) {
        exit(OVERFLOW);
    }
    (*L)->next = *L; // 头结点的指针域指向自己
}

/**
 * 操作结果: 销毁线性表
 * @param L
 */
void DestroyList(LinkList *L) {
    LinkList q, p = (*L)->next; // 指向头结点
    while (p != *L) {
        q = p->next;
        free(q);
        p = q;
    }
    free(*L);
    *L = NULL;
}

/**
 * 初始条件: 线性表 L 已存在
 * 操作结果: 将 L 重置为空表(剩下一个头结点,并且头结点的指针域指向自己)
 * @param L
 */
void ClearList(LinkList *L) {
    LinkList q, p;
    *L = (*L)->next; // L 指向头结点
    p = (*L)->next; // p 指向第一个结点
    while (p != *L) {
        q = p->next;
        free(p);
        p = q;
    }
    (*L)->next = *L;
}

/**
 * 初始条件: 线性表 L 已存在
 * 操作结果: 若 L 为空表,返回 TRUE,否则返回 FALSE
 * @param L
 * @return
 */
Status ListEmpty(LinkList L) {
    if (L->next == L) {
        return TRUE;
    } else {
        return FALSE;
    }
}

/**
 * 初始条件: 线性表 L 已存在
 * 操作结果: 返回 L 中数据元素个数
 * @param L
 * @return
 */
int ListLength(LinkList L) {
    int j = 0;
    LinkList p = L->next;
    while (p != L) {
        p = p->next;
        j++;
    }
    return j;
}

/**
 * 当第 i 个 元素存在时,其值赋给 e 并返回 Ok,否则返回 ERROR
 * @param L
 * @param i
 * @param e
 * @return
 */
Status GetElem(LinkList L, int i, ElemType *e) {
    if (i <= 0 || i > ListLength(L))
        return ERROR;
    LinkList p = L->next; // p 指向头结点
    int j = 0;
    while (j < i - 1) {
        p = p->next;
        j++;
    }
    *e = p->next->data;
    return OK;
}

/**
 * 初始条件: 线性表 L 已存在,compare() 是数据元素判定函数
 * 操作结果: 返回 L 中第一个与 e 满足关系 compare() 的数据元素的位序
 *          若这样的数据元素不存在,则返回值为 0
 * @param L
 * @param i
 * @param compare
 * @return
 */
int LocateElem(LinkList L, ElemType e, Status(*compare)(ElemType, ElemType)) {
    int j = 0;
    LinkList p = L->next; // p 指向头结点
    while (p != L) {
        j++;
        if (compare(p->data, e)) {
            return j;
        }
        p = p->next;
    }
    return j;
}


/**
 * 初始条件: 线性表 L 已存在
 * 操作结果: 若 cur_e 是 L 的数据元素,且不是第一个,则用 pre_e 返回它的前驱,返回 OK.
 *          否则操作失败,pre_e 无定义,返回 INFEASIBLE
 *
 * @param L
 * @param cure_e
 * @param pre_e
 * @return
 */
Status PriorElem(LinkList L, ElemType cure_e, ElemType *pre_e) {
    LinkList q, p = L->next;
    while (p != L) {
        q = p->next;
        if (q->data == cure_e) {
            *pre_e = p->data;
            return OK;
        }
        p = q;
    }
    return INFEASIBLE;
}

/**
 * 初始条件: 线性表 L 已存在
 * 操作结果: 若 cur_e 是 L 的数据元素,且不是最后一个,则用 next_e 返回它的后驱,返回 OK.
 *          否则操作失败,next_e 无定义,返回 INFEASIBLE
 *
 * @param L
 * @param cure_e
 * @param pre_e
 * @return
 */
Status NextElem(LinkList L, ElemType cur_e, ElemType *next_e) {
    LinkList p = L->next; // 指向头结点
    while (p != L) {
        if (p->data == cur_e) {
            *next_e = p->next->data;
            return OK;
        }
        p = p->next;
    }
    return INFEASIBLE;
}

/**
 * 算法 2.9
 * 在带头结点的单循环链表 L 中,第 i 个位置之前插入元素 e
 * @param L
 * @param i
 * @param e
 * @return
 */
Status ListInsert(LinkList *L, int i, ElemType e) {

    int j = 0;
    LinkList p = (*L)->next, s; // p 指向头结点
    if (i <= 0 || i > ListLength(*L) + 1)
        return ERROR;
    s = (LinkList) malloc(sizeof(struct LNode));
    while (j < i - 1) {
        p = p->next;
        j++;
    }
    s->data = e;
    s->next = p->next;
    p->next = s;

    if (p == *L) {
        *L = s;
    }
    return OK;
}

/**
 *
 * 在带头结点的单链线性表 L 中,删除第 i 个元素,并由 e 返回其值
 *
 * @param L
 * @param i
 * @param e
 * @return
 */
Status ListDelete(LinkList *L, int i, ElemType *e) {
    if (i <= 0 || i > ListLength(*L)) {
        return ERROR;
    }
    LinkList q, p = (*L)->next;
    int j = 0;
    while (j < i - 1) {
        p = p->next;
        j++;
    }
    q = p->next;  // 要删除的结点
    p->next = q->next;
    *e = q->data;
    if (q == *L) {
        *L = p;
    }
    free(q);
    return OK;
}

/**
 * 初始条件: 线性表 L 已存在
 * 操作结果: 依次对 L 的每个数据元素调用函数 vi()
 * @param L
 * @param vi
 */
void ListTraverse(LinkList L, void(*vi)(ElemType)) {
    LinkList p = L->next->next; // p 指向第一个结点
    while (p != L->next) { // p 不指向头结点
        vi(p->data);
        p = p->next;
    }
    printf("\n");
}