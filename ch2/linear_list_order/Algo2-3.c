/**
 * =========================================================
 *
 * 算法 2.7
 *
 * 已知顺序线性表 La 和 Lb 的元素按值非递减排列
 * 归并 La 和 Lb 得到新的顺序线性表 Lc,Lc 的元素也按值非递减排列
 *
 * =========================================================
 */

#include "../../ch1/C1.h"

typedef int ElemType;

#include "C2-1.h"
#include "Bo2-1.c"
#include "Fun2-3.c"

void MergeList(SqList La, SqList Lb, SqList *Lc) {
    ElemType *pa, *pa_last, *pb, *pb_last, *pc;
    pa = La.elem;
    pb = Lb.elem;

    Lc->listsize = Lc->length = La.length + Lb.length; // 创建空表 Lc

    pc = Lc->elem = (ElemType *) malloc(Lc->listsize * sizeof(ElemType));
    if (!Lc->elem) // 存储分配失败
        exit(OVERFLOW);

    pa_last = La.elem + La.length - 1;
    pb_last = Lb.elem + Lb.length - 1;

    // 表 La 和 Lb 都不为空
    while (pa <= pa_last && pb <= pb_last) {
        if (*pa <= *pb) {
            *pc++=*pa++; // 将 pa 所指单元的值赋给 pc 所指单元后, pa 和 pc 分别+1(指向下一个单元)
        } else {
            *pc++=*pb++; // 将 pb 所指单元的值赋给 pc 所指单元后, pb 和 pc 分别+1(指向下一个单元)
        }
    }

    // 以下两个 while 循环只有一个会被执行
    while (pa<= pa_last) // 表 La 非空,且表 Lb 为空
        *pc++ = *pa++;

    while (pb <= pb_last) // 表 Lb 非空,且表 La 为空
        *pc++ = *pb++;
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

    return 0;
}