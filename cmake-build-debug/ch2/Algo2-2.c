/**
 * =========================================================
 *  算法 2.2
 *  已知线性表 La 和 Lb 中的数据元素按值非递减排列
 *  合并 La 和 Lb 得到新的线性表 Lc. Lc 的数据元素也按值非递减排列
 * =========================================================
 */

#include "../ch1/C1.h"

typedef int ElemType;

#include "C2-1.h"
#include "Bo2-1.c"
#include "Fun2-3.c"

/**
 * 试数
 *
 *
 *
 * @param La
 * @param Lb
 * @param Lc
 */
void MergeList(SqList La, SqList Lb, SqList *Lc) {
    int i = 1, j = 1, k = 0;
    int La_len, Lb_len;
    ElemType ai, bj;
    InitList(Lc); // 创建空表 Lc
    La_len = ListLength(La);
    Lb_len = ListLength(Lb);

    // 表 La 和 Lb 均非空
    while (i <= La_len && j <= Lb_len) {
        GetElem(La, i, &ai);
        GetElem(Lb, j, &bj);
        if (ai < bj) {
            ListInsert(Lc, ++k, ai);
            ++i;
        } else {
            ListInsert(Lc, ++k, bj);
            ++j;
        }
    }

    // 下面两个 While 循环只会有一个被执行
    while (i <= La_len) { // 表 La 非空且表 Lb 空
        GetElem(La, i++, &ai);
        ListInsert(Lc, ++k, ai);
    }

    while (j <= Lb_len) { // 表 Lb 非空且表 La 空
        GetElem(Lb, j++, &bj);
        ListInsert(Lc, ++k, bj);
    }
}

int main() {

    SqList La, Lb, Lc;
    int j, a[4] = {3, 5, 8, 11}, b[7] = {2, 6, 8, 9, 11, 15, 20};
    InitList(&La); // 创建空表 La
    for (j = 1; j <= 4; j++) {
        ListInsert(&La, j, a[j - 1]); // 在表 La 中插入 4 个数据元素
    }
    printf("La = ");
    ListTraverse(La, print1);

    InitList(&Lb);
    for (j = 1; j <= 7; j++) {
        ListInsert(&Lb, j, b[j - 1]); // 在表 Lb 中插入 7 个数据元素
    }
    printf("Lb = ");
    ListTraverse(Lb, print1);

    MergeList(La, Lb, &Lc);
    printf("Lc = ");
    ListTraverse(Lc, print1);
    return 0;
}
/**
 * =========================================================
 *  
 *  程序运行结果:
 *  
 *  La = 3 5 8 11 
    Lb = 2 6 8 9 11 15 20 
    Lc = 2 3 5 6 8 8 9 11 11 15 20 

 * =========================================================
 */