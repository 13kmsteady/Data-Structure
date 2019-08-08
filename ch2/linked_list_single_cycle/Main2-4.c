/**
 * =========================================================
 *  
 * 检验 Bo2-4.c 的程序
 *
 * =========================================================
 */

#include "../../ch1/C1.h"

typedef int ElemType;

#include "../linked_list_single/head_node/C2-2.h"
#include "Bo2-4.c"
#include "../fun/Fun2-3.c"

int main() {
    LinkList L;
    ElemType e;
    Status i;
    int j;
    InitList(&L); // 初始化单循环链表
    i = ListEmpty(L);
    printf("L 是否为空: i = %d(1:是, 0:否)\n", i);


    ListInsert(&L, 1, 3); // 在表中依次插入 3,5
    ListInsert(&L, 2, 5);

    i = GetElem(L, 1, &e);
    j = ListLength(L);
    printf("L 中数据元素的个数 = %d, 第 1 个元素的值 = %d\n", j, e);
    printf("L 中的数据元素依次为: ");
    ListTraverse(L, print);

    PriorElem(L, 5, &e); // 求元素 5 的前驱
    printf("5 前面的元素值为: %d\n", e);

    NextElem(L, 3, &e); // 求元素 3 的后继
    printf("3 后面的元素值为: %d\n", e);

    i = ListEmpty(L);
    printf("L 是否为空: i = %d(1:是, 0:否)\n", i);

    j = LocateElem(L, 5, equal);
    if (j) {
        printf("L 中第 %d 个元素的值为 5\n", j);
    } else {
        printf("不存在值为 5 的元素");
    }

    i = ListDelete(&L, 2, &e);
    printf("删除 L 中的第 2 个元素: \n");
    if(i){
        printf("删除的元素值为: %d, 现在 L 中的元素依次为: ", e);
        ListTraverse(L,print);
    } else{
        printf("删除不成功\n");
    }

    ClearList(&L);
    printf("清空L后，L是否空：%d(1:空 0:否)\n",ListEmpty(L));

    DestroyList(&L);
    printf("销毁 L 后, L = %p\n",L);
    return 0;
}

/**
 * =========================================================
 *
 * 结果:
 *
 *  L 是否为空: i = 1(1:是, 0:否)
    L 中数据元素的个数 = 2, 第 1 个元素的值 = 3
    L 中的数据元素依次为: 3 5
    5 前面的元素值为: 3
    3 后面的元素值为: 5
    L 是否为空: i = 0(1:是, 0:否)
    L 中第 2 个元素的值为 5
    删除 L 中的第 2 个元素:
    删除的元素值为: 5, 现在 L 中的元素依次为: 3
    清空L后，L是否空：1(1:空 0:否)
 * =========================================================
 */