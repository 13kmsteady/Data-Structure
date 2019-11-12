/**
 * =========================================================
 *  
 * 顺序非循环队列(存储结构由(c3-5.h定义)) 的基本操作
 *
 * =========================================================
 */

/**
 * 构造一个空队列
 * @param Q
 */
void InitQueue(SqQueue1 *Q) {
    Q->base = (QElemType *) malloc(QUEUE_INIT_SIZE * sizeof(QElemType));
    if (!Q->base) {
        exit(OVERFLOW);
    }
    Q->queuesize = QUEUE_INIT_SIZE;
    Q->rear = 0;
}

/**
 * 销毁一个队列
 * @param Q
 */
void DestroyQueue(SqQueue1 *Q) {
    free(Q->base);
    Q->base = NULL;
    Q->rear = Q->queuesize = 0;
}

/**
 * 清空队列
 * @param Q
 */
void ClearQueue(SqQueue1 *Q) {
    Q->rear = Q->queuesize = 0;
}

/**
 * 若队列为空,返回 TRUE, 否则返回 FALSE
 * @param Q
 * @return
 */
Status QueueEmpty(SqQueue1 Q) {
    if (Q.rear == 0) {
        return TRUE;
    } else {
        return FALSE;
    }
}

/**
 * 返回 Q 元素的个数,即队列的长度
 *
 * @param Q
 * @return
 */
int QueueLength(SqQueue1 Q) {
    return Q.rear;
}

/**
 * 若队列不为空,用 e 返回 Q 的队头元素并返回 TRUE, 否则返回 FALSE
 * @param Q
 * @return
 */
Status GetHead(SqQueue1 Q, QElemType *e) {
    if (Q.rear) {
        *e = Q.base[0];
        return TRUE;
    } else {
        return ERROR;
    }
}

/**
 * 插入元素 e 为新的队尾部元素
 * @param Q
 * @param e
 */
void EnQueue(SqQueue1 *Q, QElemType e) {
    if (Q->rear == QUEUE_INIT_SIZE) {
        Q->base = realloc(Q->base, (Q->queuesize + QUEUE_INCREMENT) * sizeof(QElemType));
        if (!Q->base) {
            exit(OVERFLOW);
        }
        Q->queuesize += QUEUE_INCREMENT;
    }

    Q->base[Q->rear++] = e;
}

/**

 * 若队列不为空,删除 Q 的队头元素,用 e 返回其值并返回 OK, 否则返回 ERROR
 * @param Q
 * @param e
 */
Status DeQueue(SqQueue1 *Q, QElemType *e) {
    if (Q->rear) {
        *e = *(Q->base);
        int i;
        for (i = 0; i < Q->rear; i++) {
            Q->base[i] = Q->base[i + 1];
        }
        Q->rear--;
        return OK;
    } else {
        return ERROR;
    }
}

/**
 * 从队头到队尾,依次对队列 Q 中的每个元素调用函数 vi
 */
void QueueTraverse(SqQueue1 Q, void(*vi)(QElemType)) {
    int i;
    for (i = 0; i < Q.rear; i++) {
        vi(Q.base[i]);
    }
    printf("\n");
}






