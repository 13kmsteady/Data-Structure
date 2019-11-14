/**
 * =========================================================
 *
 * 检验 Bo3-8.c 的主程序
 *
 * =========================================================
 */

#include "../../ch1/C1.h"

typedef int QElemType;

#include "C3-4.h"
#include "Bo3-4.c"

void print(QElemType i) {
    printf("%d ", i);
}

int main() {

    Status j;
    int i, n = 11;
    QElemType d;
    SqQueue2 Q;

    InitQueue(&Q);
    printf("初始化队列后, 队列是否为空: %d(1:空,0:否)\n", QueueEmpty(Q));
    printf("队列长度为 %d\n", QueueLength(Q));

    for (i = 1; i <= n; ++i) {
        EnQueue(&Q, i);
    }
    printf("队列长度: %d, 队列是否为空: %d(1:空,0:否)\n", QueueLength(Q), QueueEmpty(Q));

    printf("现在队列中的元素为: \n");
    QueueTraverse(Q, print);

    DeQueue(&Q, &d);
    printf("出队一个元素,其值是: %d\n", d);
    printf("现在队列中的元素为: \n");
    QueueTraverse(Q, print);

    j = GetHead(Q,&d);
    if(j)
        printf("队头元素为: %d\n", d);
    else
        printf("无队头元素(空队列)\n");

    ClearQueue(&Q);
    printf("清空队列后, 队列是否为空: %d(1:空,0:否)\n", QueueEmpty(Q));

    j = GetHead(Q,&d);
    if(j)
        printf("队头元素为: %d\n", d);
    else
        printf("无队头元素(空队列)\n");

    DestroyQueue(&Q);
    return 0;
}