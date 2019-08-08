/**
 * =========================================================
 *
 * 线性表的双向链表存储结构
 *
 * =========================================================
 */

typedef struct DuLNode{
    ElemType data;
    struct DuLNode * prior;
    struct DuLNode * next;
}DuLNode,*DuLinkList;