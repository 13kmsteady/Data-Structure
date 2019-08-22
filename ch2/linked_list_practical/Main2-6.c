/**
 * =========================================================
 *
 * 检验 Bo2-6.c 的主程序
 *
 * =========================================================
 */

#include "../../ch1/C1.h"

typedef int ElemType;

#include "C2-5.h"
#include "Bo2-6.c"
#include "../fun/Fun2-3.c"

int main() {

    Link p, h;
    LinkList L;
    Status i;
    int j, k;
    InitList(&L); // 初始化空的线性表
    for (j = 1; j <= 2; j++) {
        MakeNode(&p, j); // 生成有 p 指向值为 j 的结点
        InsFirst(&L, L.tail, p); // 插在表尾
    }

    OrderInsert(&L, 0, comp); // 按升序插在有序表头

    for (j = 0; j <= 3; j++) {
        i = LocateElemP(L, j, &p, comp);
        if (i) {
            printf("链表中有值为 %d 的元素\n", p->data);
        } else {
            printf("链表中没有值为 %d 的元素\n", j);
        }
    }

    printf("输出链表: ");
    ListTraverse(L, print); // 输出 L

    for (j = 1; j <= 4; j++) {
        printf("删除表头结点: ");
        DelFirst(&L, L.head, &p); // 删除 L 的首结点,并以 p 返回

        if (p) {
            printf("%d\n", GetCurElem(p));
        } else {
            printf("表空,无法删除 p= %p\n", p);
        }
    }

    printf("L 中结点个数 = %d, L 是否为空 %d (1:是,0:否)\n", L.len, ListEmpty(L));

    MakeNode(&p, 10);
    p->next = NULL; // p 是尾结点
    for (j = 4; j >= 1; j--) {
        MakeNode(&h, j * 2);
        h->next = p;
        p = h;
    }// h 指向一串 5 个结点,其值依次是: 2 4 6 8 10

    Append(&L, h); // 把结点 h 链接在线性表的最后一个结点之后
    OrderInsert(&L, 12, comp); // 按升序插在有序表尾头
    OrderInsert(&L, 7, comp); // 按升序插在有序表中间
    printf("输出链表: ");
    ListTraverse(L, print); // 输出 L

    for (j = 1; j <= 2; j++) {
        p = LocateElem(L, j * 5, equal);
        if (p) {
            printf("L 中存在值为 %d 的结点\n", j * 5);
        } else {
            printf("L 中不存在值为 %d 的结点\n", j * 5);
        }
    }

    for (j = 1; j <= 2; j++) {
        LocatePos(L, j, &p); // p 指向 L 的第 j 个结点
        h = PriorPos(L, p); // h 指向 p 的前驱
        if (h) {
            printf("%d 的前驱是 %d\n", p->data, h->data);
        } else {
            printf("%d 没有前驱\n", p->data);
        }
    }

    k = ListLength(L);
    for (j = k - 1; j <= k; j++) {
        LocatePos(L, j, &p); // p 指向 L 的第 j 个结点
        h = NextPos(L, p); // h 指向 p 的后继
        if (h) {
            printf("%d 的后继是 %d\n", p->data, h->data);
        } else {
            printf("%d 没有后继\n", p->data);
        }
    }

    printf("L 中结点个数 = %d, L 是否为空 %d (1:是,0:否)\n", L.len, ListEmpty(L));

    p = GetLast(L); // p 指向最后一个结点
    SetCurElem(p, 15); // 将最后一个结点的值变为 15
    printf("第 1 个元素的值为: %d, 最后一个元素的值为: %d\n", GetCurElem(GetHead(L)->next), GetCurElem(p));

    MakeNode(&h, 10);
    InsBefore(&L, &p, h); // 将 10 插到尾结点之前, p 指向新插入的的结点
    printf("输出链表: ");
    ListTraverse(L, print);

    p = p->next; // p 指向尾结点
    MakeNode(&h, 20);
    InsAfter(&L, &p, h);
    printf("输出链表: ");
    ListTraverse(L, print);


    k = ListLength(L);
    printf("依次删除表尾结点并输出其值 ");
    for (j = 0; j <= k; j++) {
        i = Remove(&L, &p);
        if (i) {
            printf("%d ", p->data);
        } else {
            printf("删除不成功 p = %p\n", p);
        }
    }

    MakeNode(&p, 29);
    InsFirst(&L, L.head, p);
    printf("输出链表: ");
    ListTraverse(L, print);

    DestroyList(&L);
    printf("销毁线性链表之后: L.head = %p, L.tail = %p, L.len = %d\n", L.head, L.tail, L.len);
    return 0;
}
/**
 * =========================================================
 *
 *  结果:
 *
    链表中有值为 0 的元素
    链表中有值为 1 的元素
    链表中有值为 2 的元素
    链表中没有值为 3 的元素
    输出链表: 0 1 2
    删除表头结点: 0
    删除表头结点: 1
    删除表头结点: 2
    删除表头结点: 表空,无法删除 p= (nil)
    L 中结点个数 = 0, L 是否为空 1 (1:是,0:否)
    输出链表: 2 4 6 7 8 10 12
    L 中不存在值为 5 的结点
    L 中存在值为 10 的结点
    2 没有前驱
    4 的前驱是 2
    10 的后继是 12
    12 没有后继
    L 中结点个数 = 7, L 是否为空 0 (1:是,0:否)
    第 1 个元素的值为: 2, 最后一个元素的值为: 15
    输出链表: 2 4 6 7 8 10 10 15
    输出链表: 2 4 6 7 8 10 10 15 20
    依次删除表尾结点并输出其值 20 15 10 10 8 7 6 4 2 删除不成功 p = (nil)
    输出链表: 29
    销毁线性链表之后: L.head = (nil), L.tail = (nil), L.len = 0
 * =========================================================
 */