/**
 * =========================================================
 *  
 * 用单链表的基本操作实现链队列的基本操作
 *
 * =========================================================
 */

typedef QElemType ElemType;
#define LinkList QueuePtr // 定义单链表的类型和与相应的链队列的类型相同
#define LNode QNode

#include "../../ch2/linked_list_single/head_node/Bo2-2.c" // 单链表的基本操作

void InitQueue(LinkQueue *Q) {

    InitList(&(Q->front));
    Q->rear = Q->front;
}

void DestroyQueue(LinkQueue *Q) {
    DestroyList(&(Q->front));
    Q->rear = Q->front;
}

void ClearQueue(LinkQueue *Q) {
    clearList(Q->front);
    Q->rear = Q->front;
}

Status QueueEmpty(LinkQueue Q) {
    return ListEmpty(Q.front);
}

int QueueLength(LinkQueue Q) {
    return ListLength(Q.front);
}

Status GetHead_Q(LinkQueue Q, QElemType *e) {
    return GetElem(Q.front, 1, e);
}

void EnQueue(LinkQueue *Q, QElemType e) {

    QueuePtr p = (QueuePtr) malloc(sizeof(QNode));
    if (!p) {
        exit(OVERFLOW);
    }
    p->data = e;
    p->next = NULL;
    Q->rear->next = p;
    Q->rear = p;
}

Status DeQueue(LinkQueue *Q, QElemType *e) {
    // 当队列只有一个结点时, 删除第一个结点后,让尾指针指向头指针
    if (Q->front->next == Q->rear) {
        Q->rear = Q->front;
    }
    return ListDelete(Q->front, 1, e);
}

void QueueTraverse(LinkQueue Q, void(*vi)(QElemType)) {
    ListTraverse(Q.front, vi);
}




