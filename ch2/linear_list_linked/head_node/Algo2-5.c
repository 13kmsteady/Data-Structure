/**
 * =================================================
 *
 * 实现算法 2.11 和 2.12
 *
 * ==================================================
 */

#include "../../../ch1/C1.h"

typedef int ElemType;

#include "C2-2.h"
#include "Bo2-2.c"
#include "../../linear_list_order/Fun2-3.c"

/**
 * 算法 2.11
 *
 * 逆位序(插在表头)输入 N 个元素的值，建立带头结点的单链线性表 L
 *
 *
 * 输入：1 2 3 4 5
 * 链表：5 4 3 2 1
 * @param L
 * @param n
 */
void CreateList(LinkList *L, int n) {

    LinkList s;
    *L = (LinkList) malloc(n * sizeof(struct LNode));
    (*L)->next = NULL;
    int j;
    printf("请输入 %d 个数据\n", n);
    for (j = 1; j <= n; j++) {
        s = (LinkList) malloc(sizeof(struct LNode));
        scanf("%d", &s->data);
        s->next = (*L)->next;
        (*L)->next = s;
    }
}

/**
 *
 * 顺位序(插在表尾)输入 N 个元素的值，建立带头结点的单链线性表 L
 *
 * 输入：1 2 3 4 5
 * 链表：1 2 3 4 5
 */
void CreateList2(LinkList *L, int n) {

    LinkList s, p;
    *L = (LinkList) malloc(n * sizeof(struct LNode));
    (*L)->next = NULL;
    p = *L;
    int j;
    printf("请输入 %d 个数据\n", n);
    for (j = 1; j <= n; j++) {
        s = (LinkList) malloc(n * sizeof(struct LNode));
        scanf("%d", &s->data);
        p->next = s;
        p = p->next;
    }
    s->next = NULL;
}

/**
 * 算法 2.12
 *
 * 已知单链线性表 La 和 Lb 的元素按值非递减排列
 * 归并 La 和 Lb 得到新的单链线性表 Lc，Lc 的元素也按值非递减排列
 *
 */
void MergeList(LinkList La, LinkList *Lb, LinkList *Lc) {
    LinkList pa = La->next, pb = (*Lb)->next, pc;
    *Lc = pc = La; // 用 La 的头结点作为 Lc 的头结点
    while (pa && pb) {
        if (pa->data <= pb->data) {
            pc->next = pa;
            pc = pa;
            pa = pa->next;
        } else {
            pc->next = pb;
            pc = pb;
            pb = pb->next;
        }
    }
    pc->next = pa ? pa : pb;
    free(*Lb);
    Lb = NULL;
}

int main() {
    int n = 5;
    LinkList La, Lb, Lc;
    printf("按非递减顺序, ");
    CreateList2(&La, n);
    printf("La = ");
    ListTraverse(La, print);
    printf("按非递增顺序, ");
    CreateList(&Lb, n);
    printf("Lb = ");
    ListTraverse(Lb, print);
    MergeList(La, &Lb, &Lc);
    printf("Lc = ");
    ListTraverse(Lc, print);
    return 0;
}