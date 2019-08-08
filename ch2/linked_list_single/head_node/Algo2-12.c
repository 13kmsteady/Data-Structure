/**
 * =========================================================
 *
 * 用单链表实现算法 2.1
 *
 * 将所有在线性表 Lb 中,但不在 La 中的数据元素插入到 La 中
 * =========================================================
 */
#include "../../../ch1/C1.h"

typedef int ElemType;

#include "C2-2.h"
#include "Bo2-2.c"
#include "../../fun/Fun2-3.c"

/**
 * 用链表实现算法 2.1
 * 将所有在线性表 Lb 中,但不在 La 中的数据元素插入到 La 中
 *
 * @param La
 * @param Lb
 */
void Union(LinkList La, LinkList Lb) {
    ElemType e;
    int j;
    int La_len, Lb_len;
    La_len = ListLength(La);
    Lb_len = ListLength(Lb);

    for (j = 1; j <= Lb_len; j++) {
        GetElem(Lb, j, &e); // 取出 Lb 中第 i 个数据元素赋值给 e

        if (!LocateElem(La, e, equal)) {
            ListInsert(La, ++La_len, e); // La 中不存在和 e 相同的数据元素,则插入
        }
    }
}

int main() {
    LinkList La, Lb;
    int j;
    InitList(&La); // 创建空表 La
    for (j = 1; j <= 5; j++) {
        ListInsert(La, j, j); // 在 La 中插入 5 个数据元素
    }
    printf("La = "); // 输出 La 的内容
    ListTraverse(La, print);

    InitList(&Lb); // 创建空表 Lb
    for (j = 1; j <= 5; j++) {
        ListInsert(Lb, j, j * 2); // 在 Lb 中插入 5 个数据元素
    }
    printf("Lb = "); // 输出 Lb 的内容
    ListTraverse(Lb, print);

    Union(La, Lb);
    printf("new La = "); // 输出新表 La 的内容
    ListTraverse(La, print);

    return 0;
}

/**
 * =========================================================
 *
 * 结果
 *
 * La = 1 2 3 4 5
   Lb = 2 4 6 8 10
   new La = 1 2 3 4 5 6 8 10
 * =========================================================
 */