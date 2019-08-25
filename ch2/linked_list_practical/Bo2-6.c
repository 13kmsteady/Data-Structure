/**
 * =========================================================
 *
 * 具有实际意义的单链表( 存储结构由 C2-5.h 定义)的 24 个基础操作
 *
 * =========================================================
 */

#include "../../ch1/C1.h"

/**
 * 构造一个空的线性链表 L
 *
 * @param L
 */
void InitList(LinkList *L) {
    Link p;
    p = (Link) malloc(sizeof(struct LNode)); // 生成一个头结点

    if (!p) {
        exit(ERROR); // 分配结点失败
    }
    p->next = NULL;
    L->head = L->tail = p;
    L->len = 0;
}

/**
 * 分配有 p 执行的值 e 的结点,若分配失败,则退出
 * @param p
 * @param e
 */
void MakeNode(Link *p, ElemType e) {
    *p = (Link) malloc(sizeof(struct LNode));
    if (!*p) {
        exit(ERROR);
    }
    (*p)->data = e;
    (*p)->next = NULL;
}

/**
 * 释放 p 所指结点
 * @param p
 */
void FreeNode(Link *p) {
    free(*p);
    *p = NULL;
}

/**
 * 返回线性链表 L 中元素的个数
 *
 * @param L
 * @return
 */
int ListLength(LinkList L) {
    return L.len;
}

/**
 * 将指针 s 所指的一串结点,链接在线性表 L 的最后一个结点
 *
 * @param L
 * @param s
 * @return
 */
Status Append(LinkList *L, Link s) {
    L->tail->next = s; // 将链表的尾指针指向 s
    // 修改链表的尾指针
    Link p = s;
    int len = 1;
    while (p->next) {
        p = p->next;
        len++;
    }
    L->tail = p;
    L->len += len;
}

/**
 * 若线性链表 L 为空, 则返回 TRUE, 否则返回 FALSE
 *
 * @param L
 * @return
 */
Status ListEmpty(LinkList L) {
    if (L.head == L.tail) {
        return TRUE;
    } else {
        return FALSE;
    }
}


/**
 * 已知 h 指向线性链表的头结点, 将 s 所指结点插入在第一个结点之前
 *
 * 当 h 为 (*L)->head 时, 只会移动一次尾指针
 * 当 h 为 (*L)->tail 时, 每次都会移动尾指针
 * @param L
 * @param h
 * @param s
 */
void InsFirst(LinkList *L, Link h, Link s) {
    s->next = h->next;
    h->next = s;
    if (h == (*L).tail) {
        L->tail = s;
    }
    L->len++;
}

/**
 * 已知 L 为有序线性链表,将元素 e 按非降序插入在 L 中
 *
 * @param L
 * @param e
 * @param comp
 */
void OrderInsert(LinkList *L, ElemType e, int (*comp)(ElemType, ElemType)) {

    Link s, p, q = (*L).head; // q 指向头结点
    p = q->next; // p 指向第一个结点

    while (p != NULL && comp(p->data, e) < 0) { // p 不是表尾,并且元素值小于 e
        q = p;
        p = q->next;
    }
    s = (Link) malloc(sizeof(struct LNode));
    s->data = e;

    q->next = s;
    s->next = p;

    if (q == L->tail)
        L->tail = s;
    L->len++;
}

/**
 * 若升序链表 L 中存在与 e 满足判定函数 compare()取值为 0 的元素，则 q 指示 L 中
 * 第一个值为 e 的结点的位置，并返回 TRUE；
 * 否则 q 指示第一个与 e 满足判定函数
 * compare()取值>0的元素的前驱的位置。并返回 FALSE。(用于一元多项式)
 *
 * @param L
 * @param e
 * @param s
 * @param comp
 * @return
 */
Status LocateElemP(LinkList L, ElemType e, Link *s, int(*comp)(ElemType, ElemType)) {
    Link p = L.head->next; // p 指向第一个结点
    while (p) {
        if (comp(p->data, e) == 0) {
            *s = p;
            return TRUE;
        }
        p = p->next;
    }
    return FALSE;
}


/**
 * 返回线性链表 L 中第 1 个与 e 满足函数 compare() 判定关系的元素的位置
 * 若不存在这样的元素,则返回 NULL
 *
 * @param L
 * @param e
 * @param equal
 * @return
 */
Position LocateElem(LinkList L, ElemType e, Status (*compare)(ElemType, ElemType)) {
    Link p = L.head->next; // p 指向第一个结点
    while (p) {
        if (compare(p->data, e)) {
            return p;
        }
        p = p->next;
    }
    return NULL;
}


/**
 * h 指向 L 的一个结点,把 h 当做头结点,删除链表中的第一个结点并以 q 返回
 * 若链表为空(h 指向尾结点),q = null,返回 false
 *
 * @param L
 * @param h
 * @param q
 */
Status DelFirst(LinkList *L, Link h, Link *q) {
    *q = h->next; // q 指向第一个结点
    if (*q) {
        h->next = (*q)->next;
        if (*q == (*L).tail) {
            L->tail = h;
        }
        (*L).len--;
        return TRUE;
    } else {
        return FALSE;
    }
}


/**
 * 返回 p 指向线性链表 L 中第 i 个 结点的位置并返回 OK
 * i 值不合法时,返回 ERROR,i = 0 时,返回头结点
 * @param L
 * @param i
 * @param p
 * @return
 */
Status LocatePos(LinkList L, int i, Link *p) {
    if (i < 0 || i > L.len) {
        return ERROR; // i 值不合法
    } else {
        int j;
        *p = L.head;
        for (j = 1; j <= i; j++) {
            *p = (*p)->next;
        }
        return OK;
    }
}

/**
 * 已知 p 指向线性链表 L 中的一个结点,返回 p 所指结点的直接前驱的位置
 * 若无前驱,则返回 NULL
 *
 * @param L
 * @param p
 * @return
 */
Position PriorPos(LinkList L, Link p) {
    Link q = L.head->next; // s 指向第一个结点
    if (q == p) {
        return NULL; // p 指向第一个结点
    } else {
        while (q->next != p) {
            q = q->next;
        }
        return q;
    }
}

/**
 * 已知 p 指向线性链表 L 中的一个结点,返回 p 所指结点的直接后继的位置,
 * 若无后继,则返回 NULL
 *
 * @param L
 * @param p
 * @return
 */
Position NextPos(Link p) {
    return p->next;
}

/**
 * 返回线性链表 L 中最后一个结点的位置
 *
 * @param L
 * @return
 */
Position GetLast(LinkList L) {
    return L.tail;
}

/**
 * 返回线性链表 L 中第一个结点的位置
 * @param L
 * @return
 */
Position GetHead(LinkList L) {
    return L.head;
}

/**
 * 已知 p 指向线性链表中的一个结点, 用 e 更新 p 所指结点中数据元素的值
 *
 * @param p
 * @param e
 */
void SetCurElem(Link p, ElemType e) {
    p->data = e;
}

/**
 * 已知 p 指向线性链表中的一个结点, 返回 p 所指结点中数据元素的值
 *
 * @param p
 * @return
 */
ElemType GetCurElem(Link p) {
    return p->data;
}

/**
 * 已知 p 指向线性链表 L 中的一个结点,将 s 所指结点插入值在 p 所指结点之前,
 * 并修改指针 p 指向新插入的结点
 *
 * @param L
 * @param p
 * @param s
 */
void InsBefore(LinkList *L, Link *p, Link s) {
    Link q = L->head->next; // q 指向第一个结点
    if (*p == q) {
        // 说明 p 指向第一个结点
        L->head->next = s;
        s->next = q;
    } else {
        while (q->next != *p) {
            q = q->next;
        }
    }
    s->next = q->next;
    q->next = s;
    *p = s;
    L->len++;
}

/**
 * 已知 p 指向线性链表 L 中的一个结点,将 s 所指结点插入值在 p 所指结点之后,
 * 并修改指针 p 指向新插入的结点
 *
 * @param L
 * @param p
 * @param s
 */
void InsAfter(LinkList *L, Link *p, Link s) {

    if (*p == L->tail) {
        L->tail = s;
    }
    s->next = (*p)->next;
    (*p)->next = s;
    (*p) = s;
    L->len++;
}

/**
 * 删除线性链表 L 中的尾结点,并以 q 返回,改变链表 L 的尾指针指向新的尾结点
 *
 * @param L
 * @param q
 * @return
 */
Status Remove(LinkList *L, Link *q) {
    Link p = L->head; // p 指向头结点
    if (L->head == L->tail) {
        *q = NULL;
        return FALSE; // 说明是空表
    } else {
        while (p->next != L->tail) {
            p = p->next;
        }
        *q = L->tail;
        L->tail = p;
        p->next = NULL;
        L->len--;
        return TRUE;
    }
}

/**
 * 将线性链表 L 重置为空表, 并释放原链表的结点空间
 * @param L
 */
void ClearList(LinkList *L) {
    Link p = L->head->next; // p 指向第一个结点
    Link q;
    while (p) {
        q = p->next;
        free(p);
        p = q;
    }
    L->tail = L->head;
    L->len = 0;
}

/**
 * 销毁线性链表 L, L 将不存在
 *
 * @param L
 */
void DestroyList(LinkList *L) {
    ClearList(L);
    free(L->head);
    L->head = NULL;
    L->tail = NULL;
    L->len = 0;
}

/**
 * 初始条件: 线性表 L 已存在
 * 操作结果: 依次对 L 的每个数据元素调用函数 visit()
 *
 * @param L
 * @param visit
 */
void ListTraverse(LinkList L, void(*visit)(ElemType)) {
    Link p = L.head->next;
    while (p) {
        visit(p->data);
        p = p->next;
    }
    printf("\n");
}