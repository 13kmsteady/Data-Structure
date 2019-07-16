/**
 * =========================================================
 *
 * 实现算法 2.1
 *
 * =========================================================
 */

typedef int ElemType;

#include "C2-1.h" // 采用线性表的动态分配顺序存储结构

#include "Bo2-1.c"

#include "Fun2-3.c"

/**
 * 算法 2.1
 * 将所有在线性表 Lb 中,但不在 La 中的数据元素插入到 La 中
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

    for (int i = 0; i <= lbLen; ++i) {
        GetElem(Lb, i, &e); // 取 Lb 中第 i 个数据元素赋值给 e;
        // La 中不存在和 e 相同的元素,则插入
        if (LocateElem(*La, e, equal)) {
            ListInsert(La, i, e);
        }
    }
}

int main() {

    SqList La, Lb;
    int j;
    InitList(&La); // 创建空表 La, 若不成功,则退出程序
    for (j = 0; j <= 5; j++) {
        ListInsert(&La, j, j); // 在表 La 中插入 5 个元素,依次为 1,2,3,4,5
    }
    printf("La = "); // 输出表 a 的内容
    ListTraverse(La, print1);

    return 0;
}







