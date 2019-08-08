/**
 * =================================================
 *
 * 带头结点的双向循环链表( 存储结构由 C2-4.h 定义 )的基本操作
 * 包括算法 2.18 2.19
 *
 * ==================================================
 */

#include "../../ch1/C1.h"

/**
 * 产生空的双向循环链表
 *
 * @param L
 */
void InitLinkList(DuLinkList *L) {

    *L = (DuLinkList) malloc(sizeof(DuLNode));

    if (!*L) {
        exit(OVERFLOW);
    }
    (*L)->next = *L;
    (*L)->prior = *L;
}

/**
 * 操作结果： 销毁双向循环链表 L
 *
 * @param L
 */
void DestroyList(DuLinkList *L) {
    DuLinkList q, p = (*L)->next; // p 指向第一个结点
    while (p != *L) {
        q = p->next;
        free(p);
        p = q;
    }
    free(*L);
    *L = NULL;
}

/**
 * 初始条件： 双向循环链表 L 已存在
 * 操作结果： 将 L 重置为空表
 *
 * @param L
 */
void ClearList(DuLinkList L) {
    DuLinkList q, p = L->next; // p 指向第一个结点
    while (p != L) {
        q = p->next;
        free(p);
        p = q;
    }
    L->next = L->prior = L; // 头结点的指针域都指向自己
}

/**
 * 初始条件： 双向循环链表 L 已存在
 * 操作结果： 若 L 为空表，则返回 TRUE，否则返回 FALSE
 *
 * @param L
 * @return
 */
Status ListEmpty(DuLinkList L) {
    if (L->prior == L && L->next == L) {
        return TRUE;
    } else {
        return FALSE;
    }
}

/**
 * 初始条件： 双向循环链表 L 已存在
 * 操作结果： 返回 L 中结点的个数
 *
 * @param L
 * @return
 */
int ListLength(DuLinkList L) {
    DuLinkList p = L->next; // p 指向第 1 个结点
    int j = 0;
    while (p != L) {
        p = p->next;
        j++;
    }
    return j;
}

/**
 * 当第 i 个元素存在时，其值赋给 e 并返回 OK，否则返回 ERROR
 *
 * @param L
 * @param i
 * @param e
 * @return
 */
Status GetElem(DuLinkList L, int i, ElemType *e) {
    if (i <= 0 || i > ListLength(L)) {
        return ERROR;
    }
    int j = 1;
    DuLinkList p = L->next;
    while (p != L && j < i) {
        p = p->next;
        j++;
    }
    *e = p->data;
    return OK;
}

/**
 * 初始条件：双向循环链表 L 已存在，compare() 是数据元素判定函数
 * 操作结果：返回 L 中第 1 个与 e 满足关系 compare() 的数据元素的位序，若这样的数据元素不存在，则返回值为 0
 *
 * @param L
 * @param e
 * @param compare
 * @return
 */
int LocateElem(DuLinkList L, ElemType e, Status(*compare)(ElemType, ElemType)) {
    DuLinkList p = L->next;
    int j = 0;
    while (p != L) {
        j++;
        if (compare(p->data, e)) {
            return j;
        }
        p = p->next;
    }
    return 0;
}

/**
 * 操作结果：若 cur_e 是 L 的数据元素，且不是第一个，则用 pre_e 返回它的前驱，
 * 否则操作失败，pre_e 无定义
 *
 * @param L
 * @param cur_e
 * @param pre_e
 * @return
 */
Status PriorElem(DuLinkList L, ElemType cur_e, ElemType *pre_e) {
    DuLinkList p = L->next->next; // p 指向第二个结点
    while (p != L) {
        if (p->data == cur_e) {
            *pre_e = p->prior->data;
            return TRUE;
        }
        p = p->next;
    }
    return FALSE;

}

/**
 * 操作结果：若 cur_e 是 L 的数据元素，且不是最后一个，则用 next_e 返回它的后继
 * 否则操作失败，next_e 无定义
 * @param L
 * @param cur_e
 * @param next_e
 * @return
 */
Status NextElem(DuLinkList L, ElemType cur_e, ElemType *next_e) {
    DuLinkList p = L->next->next; // p 指向第二个结点
    while (p != L) {
        if (p->prior->data == cur_e) {
            *next_e = p->data;
            return TRUE;
        }
        p = p->next;
    }
    return FALSE;
}

/**
 * 算法 2.18
 *
 * 在带头结点的双链循环链表 L 中第 i 个位置之前插入元素 e
 *
 * @param L
 * @param i
 * @param e
 * @return
 */
Status ListInsert(DuLinkList L, int i, ElemType e) {

    if (i <= 0 || i > ListLength(L) + 1) {
        return ERROR;
    }

    int j = 0;
    DuLinkList s, p = L; // p 指向头结点
    while (j < i) { // p 指向第 i 个元素
        p = p->next;
        j++;
    }

    s = (DuLinkList) malloc(sizeof(DuLNode));
    if (!s) {
        return ERROR;
    }

    s->data = e;
    s->prior = p->prior;
    s->next = p;
    p->prior->next = s;
    p->prior = s;

    return OK;
}

/**
 * 算法 2.19
 *
 * 删除带头结点的双链循环线性表 L 的第 i 个元素
 *
 * @param L
 * @param i
 * @param e
 * @return
 */
Status ListDelete(DuLinkList L, int i, ElemType *e) {

    if (i <= 0 || i > ListLength(L) + 1) {
        return ERROR; // i 值不合法
    }

    int j = 0;
    DuLinkList p = L;

    while (j < i) { // p 指向第 i 个元素
        p = p->next;
        j++;
    }

    *e = p->data;
    p->prior->next = p->next;
    p->next->prior = p->prior;
    free(p);
    return OK;
}

/**
 * 由双链循环线性表 L 的头结点出发，正序对每个数据元素调用函数 vi()
 * @param L
 * @param vi
 */
void ListTraverse(DuLinkList L, void(*vi)(ElemType)) {

    DuLinkList p = L->next; // p 指向第一个结点
    while (p != L) {
        vi(p->data);
        p = p->next;
    }
    printf("\n");
}

/**
 * 由双链循环线性表 L 的头结点出发，逆序对每个数据元素调用函数 vi()
 * @param L
 * @param vi
 */
void ListTraverseBack(DuLinkList L, void(*vi)(ElemType)) {
    DuLinkList p = L->prior; // p 指向尾结点
    while (p != L) {
        vi(p->data);
        p = p->prior;
    }
    printf("\n");
}