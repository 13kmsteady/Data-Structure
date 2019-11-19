/**
 * =========================================================
 *  
 * 顺序非循环队列(存储结构由(C3-3.h定义)) 的基本操作
 *
 * =========================================================
 */

/**
 * 构造一个空队列
 * @param Q
 */
void InitQueue(SqQueue *Q) {

    Q->base = (QElemType *) malloc(MAX_QSIZE * sizeof(QElemType));
    if (!Q->base) {
        exit(OVERFLOW);
    }
    Q->front = Q->rear = 0;
}

/**
 * 销毁一个队列
 * @param Q
 */
void DestroyQueue(SqQueue *Q) {
    if (Q->base) {
        free(Q->base);
    }
    Q->base = NULL;
    Q->front = Q->rear = 0;
}

/**
 * 清空队列
 * @param Q
 */
void ClearQueue(SqQueue *Q) {
    Q->front = Q->rear = 0;
}

/**
 * 若队列为空,返回 TRUE, 否则返回 FALSE
 * @param Q
 * @return
 */
Status QueueEmpty(SqQueue Q) {
    if (Q.front == Q.rear)
        return TRUE;
    else
        return FALSE;
}

/**
 * 返回 Q 元素的个数,即队列的长度
 *
 * @param Q
 * @return
 */
int QueueLength(SqQueue Q) {
    return (Q.rear - Q.front + MAX_QSIZE) % MAX_QSIZE;
}

/**
 * 若队列不为空,用 e 返回 Q 的队头元素并返回 TRUE, 否则返回 FALSE
 * @param Q
 * @return
 */
Status GetHead(SqQueue Q, QElemType *e) {
    if (Q.front == Q.rear) {
        return FALSE;
    } else {
        *e = Q.base[Q.front];
        return TRUE;
    }
}

/**
 * 插入元素 e 为新的队尾元素
 * @param Q
 * @param e
 */
Status EnQueue(SqQueue *Q, QElemType e) {
    if ((Q->rear + 1) % MAX_QSIZE == Q->front) { // 队列满
        return ERROR;
    }
    Q->base[Q->rear] = e;
    Q->rear = (Q->rear + 1) % MAX_QSIZE;
    return OK;
}

/**
 * 若队列不为空,删除 Q 的队头元素,用 e 返回其值并返回 OK, 否则返回 ERROR
 * @param Q
 * @param e
 */
Status DeQueue(SqQueue *Q, QElemType *e) {
    if (Q->front == Q->rear) {
        return ERROR;
    } else {
        *e = Q->base[Q->front];
        Q->front = (Q->front + 1) % MAX_QSIZE;
    }
}

/**
 * 从队头到队尾,依次对队列 Q 中的每个元素调用函数 vi
 */
void QueueTraverse(SqQueue Q, void(*vi)(QElemType)) {
    int i = Q.front;
    while (i != Q.rear) {
        vi(Q.base[i]);
        i = (i + 1) % MAX_QSIZE;
    }
    printf("\n");
}






