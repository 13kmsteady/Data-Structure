/**
 * =========================================================
 *
 * 算法 2.1
 * 将所有在线性表 Lb 中,但不在 La 中的数据元素插入到 La 中
 *
 * =========================================================
 */

typedef int ElemType;

#include "C2-1.h" // 采用线性表的动态分配顺序存储结构
#include "Bo2-1.c"
#include "Fun2-3.c"

/**
 * 算法 2.1
 * @param la
 * @param lb
 */
void Union(SqList *La, SqList Lb) {
    ElemType e;
    int laLen, lbLen;
    int i;

    // 求线性表的长度
    laLen = ListLength(*La);
    lbLen = ListLength(Lb);

    for ( i = 1; i <= lbLen; ++i) {
        GetElem(Lb, i, &e); // 取 Lb 中第 i 个数据元素赋值给 e;
        // La 中不存在和 e 相同的元素,则插入
        if (!LocateElem(*La, e, equal)) {
            ListInsert(La, ++laLen, e);
        }
    }
}

int main() {

    SqList La, Lb;
    int j;
    InitList(&La); // 创建空表 La, 若不成功,则退出程序
    for (j = 1; j <= 5; j++) {
        ListInsert(&La, j, j); // 在表 La 中插入 5 个元素,依次为 1,2,3,4,5
    }
    printf("La = "); // 输出表 La 的内容
    ListTraverse(La, print1);


    InitList(&Lb); // 创建空表 Lb
    for (j = 1; j <= 5; j++) {
        ListInsert(&Lb, j, j * 2); // 在表 Lb 中插入 5 个元素,依次为2,4,6,8,10
    }
    printf("Lb = "); // 输出表 Lb 的内容
    ListTraverse(Lb, print1);

    Union(&La, Lb); // 调用 Union, 将 Lb 中满足条件的元素插入 La
    printf("new La = ");
    ListTraverse(La, print1);
    return 0;
}







