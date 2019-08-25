/**
 * =========================================================
 *  
 * 实现算法 2.20, 2.11 的程序
 *
 * =========================================================
 */

#include "../../ch1/C1.h"

typedef int ElemType;

#include "C2-5.h"
#include "Bo2-6.c"
#include "../fun/Fun2-3.c"

/**
 * 算法 2.20
 * 在带头结点的单链线性表 L 的第 i 个元素之前插入元素 e
 *
 * @param L
 * @param i
 * @param e
 * @return
 */
Status ListInsert(LinkList *L, int i, ElemType e) {
    Link h, s;
    if (!LocatePos(*L, i - 1, &h)) {
        return ERROR; // i 值不合法
    }
    MakeNode(&s, e);
    InsFirst(L, h, s); // 对于从 i 个结点开始的链表, i - 1 个结点就是它的头结点. h 指向 i-1
    return OK;

}

int diff(ElemType e1, ElemType e2) {
    return e1 - e2;
}

Status MergeList(LinkList *La, LinkList *Lb, LinkList *Lc, int (*compare)(ElemType, ElemType)) {
    Link ha, hb, pa, pb, q;
    ElemType a, b;
    InitList(Lc);
    // ha 和 hb 分别指向 La 和 Lb 的头结点
    ha = GetHead(*La);
    hb = GetHead(*Lb);
    // pa 和 pb 分别 La 和 Lb 的第一个结点
    pa = NextPos(ha);
    pb = NextPos(hb);

    while (pa && pb) {
        a = GetCurElem(pa);
        b = GetCurElem(pb);
        if (compare(a, b) <= 0) { // a <= b
            DelFirst(La, ha, &q); // 移去 La 的首元结点,并以 q 返回
            q->next = NULL;
            Append(Lc, q);  // q 链接在 Lc 的尾部
            pa = NextPos(ha); // pa 指向 La 新的首元结点
        } else {
            DelFirst(Lb, hb, &q);
            q->next = NULL;
            Append(Lc, q);
            pb = NextPos(hb);
        }
    }

    if (pa) {
        Append(Lc, pa);
    } else {
        Append(Lc, pb);
    }

    free(ha);
    La->head = La->tail = NULL;
    La->len = 0;

    free(hb);
    Lb->head = Lb->tail = NULL;
    Lb->len = 0;

}

int main() {
    LinkList La, Lb, Lc;
    int j;
    InitList(&La);
    for (j = 1; j <= 5; j++) {
        ListInsert(&La, j, j); // 依次插入 1,2,3,4,5
    }
    printf("La = ");
    ListTraverse(La, print);

    printf("La = ");
    ListTraverse(La, print);

    InitList(&Lb);
    for (j = 1; j <= 5; j++) {
        ListInsert(&Lb, j, j * 2); // 依次插入 2,4,6,8,10
    }
    printf("Lb = ");
    ListTraverse(Lb, print);

    MergeList(&La, &Lb, &Lc,diff);
    printf("Lc = ");
    ListTraverse(Lc, print);
    return 0;
}
/**
 * =========================================================
 *
 * 结果:
 *  La = 1 2 3 4 5
    La = 1 2 3 4 5
    Lb = 2 4 6 8 10
    Lc = 1 2 2 3 4 4 5 6 8 10
 * =========================================================
 */