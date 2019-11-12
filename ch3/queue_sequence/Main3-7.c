/**
 * =========================================================
 *  
 * 检验 Bo3-7.c 的主程序
 *
 * =========================================================
 */
#include "../../ch1/C1.h"

typedef int QElemType;

#include "C3-5.h"
#include "Bo3-7.c"

void print(QElemType i) {
    printf("%d ", i);
}

int main() {

    Status j;
    int i, k = 5;
    QElemType d;
    SqQueue1 Q;
    InitQueue(&Q);
    printf("初始化队列后, 队列是否为空: %d(1:空,0:否)\n", QueueEmpty(Q));

    for (i = 1; i <= k; i++) {
        EnQueue(&Q, i);
    }
    printf("依次入队 %d 个元素后,队列中的元素为: ", k);
    QueueTraverse(Q, print);
    printf("队列长度: %d, 队列是否为空: %d(1:空,0:否)\n", QueueLength(Q), QueueEmpty(Q));

    DeQueue(&Q, &d);
    printf("出队一个元素,其值是: %d\n", d);
    j = GetHead(Q, &d);
    if(j){
        printf("现在队头元素是: %d\n", d);
    }
    printf("队列中元素为: ");
    QueueTraverse(Q, print);

    ClearQueue(&Q);
    printf("清空队列后, 队列是否为空: %d(1:空,0:否)\n", QueueEmpty(Q));
    DestroyQueue(&Q);
    return 0;
}
