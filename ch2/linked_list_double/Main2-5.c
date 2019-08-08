/**
 * =========================================================
 *  
 * 检验 Bo2-5.c 的主程序
 *
 * =========================================================
 */

#include "../../ch1/C1.h"

typedef int ElemType;

#include "C2-4.h"
#include "Bo2-5.c"
#include "../fun/Fun2-3.c"

int main() {

    DuLinkList L;
    int i, n;
    Status j;
    ElemType e;
    InitLinkList(&L);
    for (i = 1; i <= 5; i++) {
        ListInsert(L, i, i);
    }
    printf("正序输出链表: ");
    ListTraverse(L, print);

    printf("逆序输出链表: ");
    ListTraverseBack(L, print);

    n = 2;
    ListDelete(L, n, &e); // 删除并释放第 n 个结点
    printf("删除第 %d 个结点, 值为: %d\n", n, e);
    ListTraverse(L, print); // 正序输出

    printf("链表的元素个数: %d\n", ListLength(L));
    printf("链表是否为空: %d (1:是, 0:否)\n", ListEmpty(L));

    ClearList(L);
    printf("清空后,链表是否为空: %d (1:是, 0:否)\n", ListEmpty(L));

    for (i = 1; i <= 5; i++) {
        ListInsert(L, i, i); // 重新插入 5 个结点
    }
    ListTraverse(L, print); // 正序输出

    n = 3;
    j = GetElem(L, n, &e); // 将链表的第 n 个结点的元素值赋值为 e
    if (j) {
        printf("链表的第 %d 个元素的值为: %d\n", n, e);
    } else {
        printf("不存在第 %d 个元素\n", n);
    }

    n = 4;
    i = LocateElem(L, n, equal);
    if (i) {
        printf("等于 %d 的元素是第 %d 个\n", n, i);
    } else {
        printf("没有等于 %d 的元素\n", n);
    }

    n = 5;
    j = PriorElem(L, n, &e);
    if (j) {
        printf("%d 的前驱是 %d\n", n, e);
    } else {
        printf("不存在 %d 的前驱\n", n);
    }

    n = 5;
    j = NextElem(L, n, &e);
    if (j) {
        printf("%d 的后继是 %d\n", n, e);
    } else {
        printf("不存在 %d 的后继\n", n);
    }

    DestroyList(&L);
    printf("销毁 L 后, L = %p\n",L);
    return 0;
}