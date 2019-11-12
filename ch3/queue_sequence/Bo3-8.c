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

}

/**
 * 销毁一个队列
 * @param Q
 */
void DestroyQueue(SqQueue1 *Q) {

}

/**
 * 清空队列
 * @param Q
 */
void ClearQueue(SqQueue1 *Q) {

}

/**
 * 若队列为空,返回 TRUE, 否则返回 FALSE
 * @param Q
 * @return
 */
Status QueueEmpty(SqQueue1 Q) {

}

/**
 * 返回 Q 元素的个数,即队列的长度
 *
 * @param Q
 * @return
 */
int QueueLength(SqQueue1 Q) {

}

/**
 * 若队列不为空,用 e 返回 Q 的队头元素并返回 TRUE, 否则返回 FALSE
 * @param Q
 * @return
 */
Status GetHead(SqQueue1 Q, QElemType *e) {

}

/**
 * 插入元素 e 为新的对尾部元素
 * @param Q
 * @param e
 */
void EnQueue(SqQueue1 *Q, QElemType e) {

}

/**
 * 插入元素 e 为新的对尾部元素
 * 若队列不为空,删除 Q 的队头元素,用 e 返回其值并返回 OK, 否则返回 ERROR
 * @param Q
 * @param e
 */
void DeQueue(SqQueue1 *Q, QElemType *e) {

}

/**
 * 从队头到队尾,依次对队列 Q 中的每个元素调用函数 vi
 */
void QueueTraverse(SqQueue1 Q, void(*vi)(QElemType)) {

}






