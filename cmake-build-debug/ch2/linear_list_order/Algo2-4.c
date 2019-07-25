/**
 * =========================================================
 *
 * 算法 2.7 的另外一种实现
 *
 * 修改原算法 2.7 的第一个循环语句中条件语句为 switch 语句,
 * 当 *pa = *pb 时,只将两者中之一插入 Lc
 *
 * =========================================================
 */

#include "../../ch1/C1.h"

typedef int ElemType;

#include "C2-1.h"
#include "Bo2-1.c"
#include "Fun2-3.c"

/**
 * 另外一种合并线性表的方法
 * @param La
 * @param Lb
 * @param Lc
 */
void MergeList(SqList La, SqList Lb, SqList *Lc) {
    ElemType *pa, *pa_last, *pb, *pb_last, *pc;
    pa = La.elem;
    pb = Lb.elem;
    Lc->listsize = La.length + Lb.length;
    pc = Lc->elem = (ElemType *) malloc(Lc->listsize * sizeof(ElemType));

    if (!Lc->elem)
        exit(OVERFLOW);
    pa_last = La.elem + La.length - 1;
    pb_last = Lb.elem + Lb.length - 1;

    // 表 La 和 表 Lb 均不为空
    while (pa <= pa_last && pb <= pb_last) {
        switch (comp(*pa, *pb)) {
            case 0:
                pb++;
            case -1:
                *pc++ = *pa++;
                break;
            case 1:
                *pc++ = *pb++;

        }
    }

    // 表 La 非空且表 Lb 为空
    while (pa <= pa_last)
        *pc++ = *pa++;

    // 表 Lb 非空且表 La 为空
    while (pb <= pb_last)
        *pc++ = *pb++;

    Lc->length = pc - Lc->elem;
}

int main() {

    SqList La, Lb, Lc;
    int j;
    InitList(&La); // 创建空表 La
    for (j = 1; j <= 5; j++) {
        ListInsert(&La, j, j); // 在表 La 中插入 5 个元素,依次为: 1,2,3,4,5
    }
    printf("La = "); // 输出表 La 的内容
    ListTraverse(La, print1);

    InitList(&Lb);
    for (j = 1; j <= 5; j++) {
        ListInsert(&Lb, j, j * 2); // 在表 Lb 中插入 5 个元素,依次为: 2,4,6,8,10
    }
    printf("Lb = "); // 输出表 Lb 的内容
    ListTraverse(Lb, print1);

    MergeList(La, Lb, &Lc); // 由按非递减排列的 La,Lb 得到非递减排列的 Lc
    printf("Lc = "); // 输出表 Lc 的内容
    ListTraverse(Lc, print1);
}

/**
 * =========================================================
 *
 *  结果:
 *
 *  La = 1 2 3 4 5
    Lb = 2 4 6 8 10
    Lc = 1 2 3 4 5 6 8 10

 * =========================================================
 */