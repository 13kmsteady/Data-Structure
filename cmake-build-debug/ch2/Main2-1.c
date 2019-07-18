/**
 * =========================================================
 *
 *  检验 Bo2-1.c 的程序
 *
 * =========================================================
 */

#include "../ch1/C1.h"

typedef int ElemType;

#include "C2-1.h"
#include "Bo2-1.c"
#include "Fun2-3.c"

/**
 * 数据元素判定函数(平方关系), LocateElem() 调用的函数
 * @param c1
 * @param c2
 * @return
 */
Status sq(ElemType c1, ElemType c2) {
    if (c1 == c2 * c2)
        return TRUE;
    else
        return FALSE;
}

/**
 * ListTraverse() 调用的另一函数(元素值加倍)
 * @param c
 */
void dbl(ElemType *c) {

    *c *= 2;
}

int main() {
    SqList L;
    ElemType e, e0;
    Status i;
    int j, k;
    InitList(&L);
    printf("初始化 L 后, L.elem=%p, L.length=%d, L.listsize=%d\n", L.elem, L.length, L.listsize);

    for (j = 1; j <= 5; j++) {
        i = ListInsert(&L, 1, j);
    }
    printf("在 L 的表头依次插入 1~5 之后: *L.elem = ");
    for (j = 1; j <= 5; j++) {
        printf("%d ", L.elem[j - 1]);
    }
    printf("\n");
    printf("L.elem=%p, L.length=%d, L.listsize=%d, ", L.elem, L.length, L.listsize);
    i = ListEmpty(L);
    printf("L 是否空: i=%d(1:是 0:否)\n", i);

    ClearList(&L);
    printf("清空 L 后, L.elem=%p, L.length=%d, L.listsize=%d, ", L.elem, L.length, L.listsize);
    i = ListEmpty(L);
    printf("L 是否空: i=%d(1:是 0:否)\n", i);

    for (j = 1; j <= 10; j++)
        ListInsert(&L, j, j);
    printf("在 L 的表尾依次插入 1~10 后: *L.elem=");
    for (j = 1; j <= 10; j++)
        printf("%d ", L.elem[j - 1]);
    printf("\n");
    printf("L.elem=%p, L.length=%d, L.listsize=%d, ", L.elem, L.length, L.listsize);

    ListInsert(&L, 1, 0);
    for (j = 1; j <= ListLength(L); j++)
        printf("%d ", L.elem[j - 1]);
    printf("\n");
    printf("L.elem=%p(有可能改变), L.length=%d(改变), L.listsize=%d(改变)\n", L.elem, L.length, L.listsize);

    GetElem(L, 5, &e);
    printf("第5个元素的值为: %d\n", e);

    for (j = 10; j <= 11; j++) {
        k = LocateElem(L, j, equal);

        if (k) { // k 不为0, 表明有符合条件的元素, 且位序为 k
            printf("第%d个元素的值为%d\n", k, j);
        } else {
            printf("没有值为%d的元素\n", j);
        }
    }

    for (j = 3; j <= 4; j++) {
        k = LocateElem(L, j, sq);
        if (k) {
            printf("第%d个元素的值为%d\n", k, j);
        } else {
            printf("没有值为%d平方的元素\n", j);
        }
    }

    // 测试头两个数据
    for (j = 1; j <= 2; j++) {
        GetElem(L, j, &e0); // 把第 j 个数据赋值给 e0
        i = PriorElem(L, e0, &e); // 求 e0 的前驱
        if (i == INFEASIBLE)
            printf("元素%d无前驱\n", e0);
        else
            printf("元素%d的前驱为%d\n", e0, e);
    }

    // 测试后两个数据
    for (j = 10; j <= 11; j++) {
        GetElem(L, j, &e0); // 把第 j 个数据赋值给 e0
        i = NextElem(L, e0, &e); // 求 e0 的后继
        if (i == INFEASIBLE)
            printf("元素%d无后继\n", e0);
        else
            printf("元素%d的后继为%d\n", e0, e);
    }

    k = ListLength(L);
    for (j = k + 1; j >= k; j--) {
        i = ListDelete(&L, j, &e);
        if (i == ERROR)
            printf("删除第%d个元素失败\n", j);
        else
            printf("删除第%d个元素成功,其值为%d\n", j, e);
    }

    printf("依次输出 L 的元素:");
    ListTraverse(L, print1);// 依次对元素调用 print1 函数,输出元素的值

    printf("L 的元素值加倍后");
    ListTraverse(L,dbl); // 依次对元素调用 dbl, 元素值乘2
    ListTraverse(L, print1);

    DestroyList(&L);
    printf("销毁 L 后, L.elem=%p, L.length=%d, L.listsize=%d\n", L.elem, L.length, L.listsize);
}

/**
 * =========================================================
 *
 *  程序运行结果:
 *
 *  初始化 L 后, L.elem=0x55f51abbc260, L.length=0, L.listsize=10
    在 L 的表头依次插入 1~5 之后: *L.elem = 5 4 3 2 1
    L.elem=0x55f51abbc260, L.length=5, L.listsize=10, L 是否空: i=0(1:是 0:否)
    清空 L 后, L.elem=0x55f51abbc260, L.length=0, L.listsize=10, L 是否空: i=1(1:是 0:否)
    在 L 的表尾依次插入 1~10 后: *L.elem=1 2 3 4 5 6 7 8 9 10
    L.elem=0x55f51abbc260, L.length=10, L.listsize=10, 0 1 2 3 4 5 6 7 8 9 10
    L.elem=0x55f51abbc6a0(有可能改变), L.length=11(改变), L.listsize=12(改变)
    第5个元素的值为: 4
    第11个元素的值为10
    没有值为11的元素
    第10个元素的值为3
    没有值为4平方的元素
    元素0无前驱
    元素1的前驱为0
    元素9的后继为10
    元素10无后继
    删除第12个元素失败
    删除第11个元素成功,其值为10
    依次输出 L 的元素:0 1 2 3 4 5 6 7 8 9
    L 的元素值加倍后
    0 2 4 6 8 10 12 14 16 18
    销毁 L 后, L.elem=(nil), L.length=0, L.listsize=0
 * =========================================================
 */
