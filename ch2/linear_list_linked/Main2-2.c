/**
 * =========================================================
 *
 * 检验 Bo2-2.c 的程序
 *
 * =========================================================
 */

typedef int ElemType;

#include "C2-2.h"
#include "Bo2-2.c"
#include "../linear_list_order/Fun2-3.c"

int main() {
    LinkList L;
    ElemType e, e0;
    Status i;
    int j, k;
    InitList(&L);

    for (j = 1; j <= 5; j++) {
        i = ListInsert(L, 1, j);
    }

    printf("在 L 的表头依次插入 1~5 后: L = ");
    ListTraverse(L, print); // 依次对元素调用 print() 输出元素的值

    i = ListEmpty(L);
    printf("L 是否为空: i = %d(1:是,0:否)\n", i);

    clearList(L);
    printf("清空 L 后: L = ");
    ListTraverse(L, print);

    i = ListEmpty(L);
    printf("L 是否为空: i = %d(1:是,0:否)\n", i);

    for (j = 1; j <= 10; j++) {
        ListInsert(L, j, j);
    }
    printf("在 L 的表尾插入 1~10 后: L = ");
    ListTraverse(L, print);

    GetElem(L, 5, &e);
    printf("第 5 个元素的值为: %d\n", e);

    for (j = 0; j <= 1; j++) {
        k = LocateElem(L, j, equal);
        if (k)
            printf("第 %d 个元素的值为: %d\n", k, j);
        else
            printf("没有值为 %d 的元素\n", j);
    }

    // 前两个数据
    for (j = 1; j <= 2; j++) {
        GetElem(L, j, &e0); // 把第 j 个数据赋值给 e0
        i = PriorElem(L, e0, &e); // 求 e0 的前驱
        if (i == INFEASIBLE)
            printf("元素 %d 无前驱\n", e0);
        else
            printf("元素 %d 的前驱为 %d\n", e0, e);
    }

//    // 最后两个数据
    for (j = ListLength(L) - 1; j <= ListLength(L); j++) {
        GetElem(L, j, &e0); // 把第 j 个数据赋值给 e0
        i = NextElem(L, e0, &e); // 求 e0 的后继
        if (i == INFEASIBLE)
            printf("元素 %d 无后继\n", e0);
        else
            printf("元素 %d 的后继为 %d\n", e0, e);
    }

    k = ListLength(L); // k 为表长
    for (j = k + 1; j >= k; j--) {
        i = ListDelete(L, j, &e); // 删除第 j 个数据
        if (i == ERROR)
            printf("删除第 %d 个元素失败\n", j);
        else
            printf("删除第 %d 个元素成功,其值为 %d\n", j, e);
    }

    printf("依次输出 L 的元素: ");
    ListTraverse(L, print);
    DestroyList(&L);
    printf("销毁 L 后, L=%p\n", L);

    return 0;
}