/**
 * =========================================================
 *  
 * 检验 Bo3-2.c 的主程序
 *
 * 队列: 在队尾插入元素,在队头删除元素
 *
 * =========================================================
 */

#include "../../ch1/C1.h"

typedef int QElemType;

#include "C3-3.h"
#include "Bo3-2.c"

void print(QElemType i) {

    printf("%d ", i);
}

int main() {

    int i;
    QElemType d;
    LinkQueue q;
    InitQueue(&q);
    printf("成功构造了一个空队列!\n");
    printf("队列是否为空: %d(1:空, 0:否)\n", QueueEmpty(q));
    printf("队列长度: %d\n", QueueLength(q));

    EndQueue(&q, -5);
    EndQueue(&q, 5);
    EndQueue(&q, 10);

    printf("插入 3 个元素(-5,5,10)后,队列长度: %d\n", QueueLength(q));
    printf("队列是否为空: %d(1:空, 0:否)\n", QueueEmpty(q));

    printf("队列元素依次为: ");
    QueueTraverse(q, print);

    i = GetHead(q, &d);
    if (i == OK)
        printf("队头元素是: %d\n", d);

    DeQueue(&q, &d);
    printf("删除了头元素 %d\n", d);

    i = GetHead(q, &d);
    if (i == OK)
        printf("队头元素是: %d\n", d);

    clearQueue(&q);
    printf("将队列清空后: q.front = %p, q.rear = %p, q.front->next = %p\n", q.front, q.rear, q.front->next);

    DestroyQueue(&q);
    printf("将队列销毁后: q.front = %p, q.rear = %p,", q.front, q.rear);
    return 0;
}