/**
 * =========================================================
 *  
 * 用链表实现算法 2.2
 *
 * 已知线性表 La 和 Lb 中的数元素按值非递减排列
 * 归并 La 和 Lb 得到新的线性表 Lc, Lc 的数据元素也按值非递减排列
 * =========================================================
 */


#include "../../ch1/C1.h"

typedef int ElemType;

#include "C2-2.h"
#include "Bo2-2.c"
#include "../linear_list_order/Fun2-3.c"

/**
 * 已知线性表 La 和 Lb 中的数元素按值非递减排列
 * 归并 La 和 Lb 得到新的线性表 Lc, Lc 的数据元素也按值非递减排列
 *
 * @param La
 * @param Lb
 * @param Lc
 */
void MergeList(LinkList La, LinkList Lb, LinkList *Lc) {
    int i = 1, j = 1, k = 0;
    int La_len, Lb_len;
    InitList(Lc);
    ElemType ai, bj;
    La_len = ListLength(La);
    Lb_len = ListLength(Lb);

    while (i <= La_len && j <= Lb_len) {
        GetElem(La, i, &ai);
        GetElem(Lb, j, &bj);

        if (ai <= bj) {
            ListInsert(*Lc, ++k, ai);
            i++;
        } else {
            ListInsert(*Lc, ++k, bj);
            j++;
        }
    }

    while (i <= La_len) {
        GetElem(La, i++, &ai);
        ListInsert(*Lc, ++k, ai);
    }

    while (j <= Lb_len) {
        GetElem(Lb, j++, &bj);
        ListInsert(*Lc, ++k, bj);
    }
}

int main() {
    LinkList La, Lb, Lc;
    int j, a[4] = {3, 5, 8, 11}, b[7] = {2, 6, 8, 9, 11, 15, 20};
    InitList(&La); // 创建空表 La
    for (j = 1; j <= 4; j++) {
        ListInsert(La, j, a[j - 1]); // 在表 La 中插入 4 个数据元素
    }
    printf("La = ");
    ListTraverse(La, print);

    InitList(&Lb);
    for (j = 1; j <= 7; j++) {
        ListInsert(Lb, j, b[j - 1]); // 在表 Lb 中插入 7 个数据元素
    }
    printf("Lb = ");
    ListTraverse(Lb, print);
    MergeList(La, Lb, &Lc);
    printf("Lc = ");
    ListTraverse(Lc, print);
    return 0;
}
