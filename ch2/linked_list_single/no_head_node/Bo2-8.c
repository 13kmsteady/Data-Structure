/**
 * =================================================
 * 
 * 不带头结点的单链表(存储结构由 C2-2.h 定义)
 * 
 * ==================================================
 */

#include "../../../ch1/C1.h"
#include "../head_node/C2-2.h"
#include <stdlib.h>

#define DestroyList ClearList

/**
 * 构造一个空的线性表
 *
 * @param L
 */
void InitList(LinkList *L) {
    *L = NULL;
}

/**
 * 初始条件：线性表 L 已存在
 * 操作结果：将 L 重置为空表
 * @param L
 */
void ClearList(LinkList *L) {
    LinkList p;
    while (*L) {
        p = (*L)->next;
        free(*L);
        *L = p;
    }
}

/**
 * 初始条件：线性表 L 已存在
 * 操作结果：若 L 为空表，则返回 TRUE，否则返回 FALSE
 * @param L
 * @return
 */
Status ListEmtpy(LinkList L) {
    if (L)
        return FALSE;
    else
        return TRUE;
}

/**
 * 初始条件：线性表 L 已存在
 * 操作结果：返回 L 中元素个数
 * @param L
 * @return
 */
int ListLength(LinkList L) {
    int j = 0;
    LinkList p = L;
    while (p) {
        p = p->next;
        j++;
    }
    return j;
}

/**
 * L 为不带头结点的单链表的头指针，当第 i 个元素存在时，其值赋值给 e 并返回 OK，否则返回 ERROR
 * @param L
 * @param i
 * @param e
 * @return
 */
Status GetElem(LinkList L, int i, ElemType *e) {
    int j = 1;
    LinkList p = L;
    while (p && j < i) {
        p = p->next;
        j++;
    }
    if (!p || j > i) {
        return ERROR;
    }
    *e = p->data;
    return OK;
}

/**
 * 初始条件: 线性表 L 已存在,compare() 是数据元素判定函数(满足为 1, 否则为 0)
 * 操作结果: 返回 L 中第一个与 e 满足关系 compare() 的数据元素的位序
 *
 * @param L
 * @param compare
 * @return
 */
int LocateElem(LinkList L, ElemType e, Status(*compare)(ElemType, ElemType)) {
    LinkList p = L;
    int j = 1;
    while (p) {
        if (compare(p->data, e)) {
            return j;
        }
        p = p->next;
        j++;
    }
    return 0;
}

/**
 * 在不带头结点的单链线性表 L 中，第 i 个位置之前插入元素 e
 * @param L
 * @param i
 * @param e
 * @return
 */
Status ListInsert(LinkList *L, int i, ElemType e) {
    LinkList s, p = *L;
    int j = 1;
    if (1 == i) {
        s = (LinkList) malloc(sizeof(struct LNode));
        s->data = e;
        s->next = *L;
        *L = s;
    } else {
        while (p && j < i - 1) {
            p = p->next;
            j++;
        }
        if (!p || j > i - 1)
            return ERROR;
        s = (LinkList) malloc(sizeof(struct LNode));
        s->data = e;
        s->next = p->next;
        p->next = s;
    }
    return OK;
}

/**
 * 在不带头结点的单链线性表 L 中，删除第 i 个元素，并由 e 返回其值
 * @param L
 * @param i
 * @param e
 * @return
 */
Status ListDelete(LinkList *L, int i, ElemType *e) {
    LinkList p = *L, q;
    int j = 1;
    if (1 == i) {
        *L = p->next;
        *e = p->data;
        free(p);
    } else {

        while (p->next && j < i - 1) {
            p = p->next;
            j++;
        }

        if (!p->next || j > i - 1) {
            return ERROR;
        }
        q = p->next;
        p->next = q->next;
        free(q);
    }
    return OK;
}

/**
 * 初始条件: 线性表 L 已存在
 * 操作结果: 依次对 L 的每个数据元素调用函数 vi()
 * @param L
 * @param vi
 */
void ListTraverse(LinkList L, void(*vi)(ElemType)) {
    LinkList p = L;
    while (p) {
        vi(p->data);
        p = p->next;
    }
    printf("\n");
}





