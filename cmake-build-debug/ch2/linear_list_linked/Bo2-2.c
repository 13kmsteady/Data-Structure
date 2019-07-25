/**
 * =========================================================
 *
 * 带有头结点的单链表(存储结构由 C2-2.h 定义)的基本操作 12 个,
 * 包括算法: 2.8,2.9,2.10
 *
 * =========================================================
 */

#include "../../ch1/C1.h"
#include <stdlib.h>

/**
 * 操作结果: 构造一个空的线性表 L
 * @param L
 */
void InitList(LinkList *L) {
    *L = (LinkList) malloc(sizeof(struct LNode)); // 产生头结点,并使 L 指向头结点
    if (!*L) // 存储分配失败
        exit(OVERFLOW);
    (*L)->next = NULL; // 指针域为空
}

/**
 * 初始条件: 线性表 L 已存在
 * 操作结果: 销毁线性表 L
 * @param L
 */
void DestroyList(LinkList *L) {
    LinkList q;
    while (*L) {
        q = (*L)->next;
        free(*L);
        *L = q;
    }
}

/**
 *初始条件: 线性表 L 已存在
 * 操作结果: 将 L 重置为空表
 * @param L
 */
void clearList(LinkList L) {
    LinkList p, q;
    p = L->next; // p 指向第一个结点
    while (p) { // 没有到表尾
        q = p->next;
        free(p);
        p = q;
    }
    L->next = NULL; // 头结点指针域为空
}

/**
 * 初始条件: 线性表 L 已存在
 * 操作结果: 若 L 为空表,返回 TRUE, 否则返回 FALSE
 * @param L
 * @return
 */
Status ListEmpty(LinkList L) {
    if (L->next)
        return FALSE;
    else
        return TRUE;
}

/**
 * 初始条件: 线性表 L 已存在
 * 操作结果: 返回 L 中数据元素个数
 * @param L
 * @return
 */
int ListLength(LinkList L) {
    int i = 0;
    LinkList p = L->next;
    while (p) {
        p = p->next;
        ++i;
    }
    return i;
}

/**
 * 算法 2.8
 * L 为带头结点的的单链表的头指针
 * 当 i 个元素存在时,其值赋给 e 并返回 OK,否则返回 ERROR
 *
 * @param L
 * @param i
 * @param e
 * @return
 */
Status GetElem(LinkList L, int i, ElemType *e) {

    int j = 1; // j 为计数器
    LinkList p = L->next; // p 指向第一个节点
    while (p && j < i) {
        p = p->next;
        j++;
    }

    if (!p || j > i) // 第 i 个元素不存在
        return ERROR;
    *e = p->data; // 取第 i 个元素
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

    int i = 0;
    LinkList p = L->next;
    while (p) {
        i++;
        if (compare(p->data, e)) // 找到这样的数据元素
            return i;
        p = p->next;
    }
    return 0;
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

    LinkList q, p = L->next; // p 指向第一个结点

    while (p->next) { // p 所指结点有后继

        q = p->next; // q 为 p 的后继
        if (cure_e == q->data) {

            *pre_e = p->data;
            return OK;
        }
        p = q; // p 向后移
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

    LinkList p = L->next;
    while (p->next) {

        if (cur_e == p->data) {
            *next_e = p->next->data;
            return OK;
        }
        p = p->next;
    }
    return INFEASIBLE;
}

/**
 * 算法 2.9
 * 在带头结点的单链线性表 L 中,第 i 个位置之前插入元素 e
 * @param L
 * @param i
 * @param e
 * @return
 */
Status ListInsert(LinkList L, int i, ElemType e) {

    // 先找到 i 的前驱
    LinkList s, p = L;
    int j = 0;
    while (p && j < i - 1) { // 寻找第 i-1 个结点
        p = p->next;
        j++;
    }

    if (!p && j > i - 1) // i 小于 1, 或者大于表长
        return ERROR;
    s = (LinkList) malloc(sizeof(struct LNode)); // 生成新结点
    s->data = e;
    s->next = p->next;
    p->next = s;
    return OK;
}

/**
 * 算法 2.10
 * 在带头结点的单链线性表 L 中,删除第 i 个元素,并由 e 返回其值
 *
 * @param L
 * @param i
 * @param e
 * @return
 */
Status ListDelete(LinkList L, int i, ElemType *e) {

    LinkList q, p = L;
    int j = 0;
    while (p->next && j < i - 1) { // 寻找第 i 个结点,并令 p 指向其前驱
        p = p->next;
        j++;
    }

    if (!p->next || j > i - 1) { // 删除位置不合理
        return ERROR;
    }
    // 删除并释放结点
    q = p->next;
    p->next = q->next;
    *e = q->data;
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
    LinkList p = L->next;
    while (p) {
        vi(p->data);
        p = p->next;
    }
    printf("\n");
}