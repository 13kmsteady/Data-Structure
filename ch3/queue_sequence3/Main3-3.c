/**
 * =========================================================
 *
 * 检验 Bo3-3 的主程序
 *
 * =========================================================
 */

#include "../../ch1/C1.h"

typedef int QElemType;

#include "C3-3.h"
#include "Bo3-3.c"

void print(QElemType i) {
    printf("%d ", i);
}

int main() {

    Status j;
    int i = 0, l;
    QElemType d;
    SqQueue Q;
    InitQueue(&Q);
    printf("初始化队列后, 队列是否为空: %d(1:空,0:否)\n", QueueEmpty(Q));
    printf("队列长度为 %d\n", QueueLength(Q));

    printf("依次从队列尾部插入: 2 4 6 8 \n");
    for (i = 1; i <= MAX_QSIZE - 1; i++) {
        EnQueue(&Q, i * 2);
    }
    printf("队列是否为空: %d(1:空,0:否), 队列长度: %d\n", QueueEmpty(Q), QueueLength(Q));
    printf("队列的元素为: ");
    QueueTraverse(Q, print);

    j = GetHead(Q, &d);
    if (j) {
        printf("队头元素为: %d\n", d);
    }

    printf("出队一个元素,");
    DeQueue(&Q, &d);
    printf("出队的元素值是: %d\n", d);

    printf("入队元素: 18 ");
    EnQueue(&Q, 18);
    printf("队列的元素为: ");
    QueueTraverse(Q, print);

    ClearQueue(&Q);
    printf("清空队列后, 队列是否为空: %d(1:空,0:否)\n", QueueEmpty(Q));
    printf("队列长度为 %d\n", QueueLength(Q));

    DestroyQueue(&Q);
    return 0;
}