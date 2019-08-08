/**
 * =================================================
 * 
 * 两个仅设尾指针的循环链表的合并
 * 
 * ==================================================
 */

#include "../../ch1/C1.h"

typedef int ElemType;

#include "../linked_list_single/head_node/C2-2.h"
#include "Bo2-4.c"
#include "../fun/Fun2-3.c"

void MergeList(LinkList *La, LinkList Lb) {
    LinkList p = Lb->next;
    Lb->next = (*La)->next;
    (*La)->next = p->next;
    (*La) = Lb;
    free(p);
}

int main() {

    int n = 5, i;
    LinkList La,Lb;
    InitList(&La);
    InitList(&Lb);
    for (i = 1;  i<=5 ; i++) {
        ListInsert(&La, i, i);
    }
    printf("La = ");
    ListTraverse(La, print);

    for (i = 1;  i <=n; i++) {
        ListInsert(&Lb, 1, i * 2);
    }
    printf("Lb = ");
    ListTraverse(Lb, print);

    printf("New La = ");
    MergeList(&La, Lb);
    ListTraverse(La, print);
    return 0;
}