/**
 * =========================================================
 *  
 * 链队列( 存储结构由 C3-3.h 定义)的基本操作
 *
 * =========================================================
 */

/**
 * 构造一个空队列
 *
 * @param Q
 */
void InitQueue(LinkQueue *Q) {

    Q->front = Q->rear = (QueuePtr) malloc(sizeof(QNode));
    if (!Q->front) {
        exit(OVERFLOW);
    }
    Q->front->next = NULL;
}

/**
 * 销毁队列
 *
 * @param Q
 */
void DestroyQueue(LinkQueue *Q) {
    while (Q->front){
        Q->rear = Q->front ->next;
        free(Q->front);
        Q->front = Q->rear;
    }
}

/**
 * 将 Q 清为空队列
 *
 * @param Q
 */
void clearQueue(LinkQueue *Q) {

    QueuePtr q, p = Q->front->next;
    while (p) {
        q = p;
        p = p->next;
        free(q);
    }
    Q->rear = Q->front;
}

/**
 * 若 Q 为空队列,则返回 TRUE
 * 否则,返回 FALSE
 *
 * @param Q
 * @return
 */
Status QueueEmpty(LinkQueue Q) {
    if (Q.front == Q.rear) {
        return TRUE;
    } else {
        return FALSE;
    }
}

/**
 * 求队列的长度
 *
 * @param Q
 * @return
 */
int QueueLength(LinkQueue Q) {

    int length = 0;

    QueuePtr p = Q.front->next; // p -> 指向第一个结点
    while (p) {
        p = p->next;
        length++;
    }
    return length;
}

/**
 * 若队列不为空,用 e 返回 Q 的队头元素,并返回 OK
 * 否则,返回 ERROR
 *
 * @param Q
 * @param e
 * @return
 */
Status GetHead(LinkQueue Q, QElemType *e) {

    if (Q.front == Q.rear) {
        return ERROR;
    } else {
        *e = Q.front->next->data;
        return OK;
    }
}

/**
 * 插入元素 e 为 Q 的新队尾元素
 *
 * @param Q
 * @param e
 */
void EndQueue(LinkQueue *Q, QElemType e) {

    QueuePtr p = (QueuePtr) malloc(sizeof(QNode));
    if (!p) {
        exit(OVERFLOW);
    }

    p->data = e;
    p->next = NULL;
    Q->rear->next = p; // 尾指针指向结点的 next -> 新生成的结点 p
    Q->rear = p; // 尾指针指向新生成的结点 p
}

/**
 * 若队列不为空,删除 Q 的队头元素,用 e 返回其值 ,并返回 OK
 * 否则返回 ERROR
 * @param Q
 * @param e
 * @return
 */
Status DeQueue(LinkQueue *Q, QElemType *e) {

    if (Q->front == Q->rear) {
        return ERROR;
    } else {

        QueuePtr p = Q->front->next; // p 指向第一个结点

        *e = p->data;
        Q->front->next = p->next; // 头结点的 next 域指向新的结点
        if (Q->rear == p)
            Q->rear = Q->front;
        free(p);
        return OK;
    }
}

/**
 * 从队头到队尾,依次队队列 Q 中的元素调用函数 vi()
 *
 * @param Q
 * @param vi
 */
void QueueTraverse(LinkQueue Q, void(*vi)(QElemType)) {

    QueuePtr p = Q.front->next;
    while (p) {
        vi(p->data);
        p = p->next;
    }
    printf("\n");
}