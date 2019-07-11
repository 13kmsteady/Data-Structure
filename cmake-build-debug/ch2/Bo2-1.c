#include "C2-1.h"
#include "../ch1/C1.h"

/**
 * =========================================================
 *
 *  顺序表示的线性表, 存储结构由 (c2-1.h) 定义, 演示基本的 12 个操作
 *  包括算法 2.3,2.4,2.5,2.6
 *
 * =========================================================
 */


/**
 * 算法 2.3
 * 操作结果: 构造一个空的顺序线性表 L
 * @param L
 */
void InitList(SqList *L) {
    L->elem = (ElemType *) malloc(LIST_INIT_SIZE * sizeof(ElemType));
    if (!L->elem)
        exit(OVERFLOW); // 存储分配失败
    L->length = 0; // 空表的长度为 0
    L->listsize = LIST_INIT_SIZE; // 初始存储容量
}

/**
 * 初始条件: 顺序线性表 L 已存在
 * 操作结果: 销毁顺序线性表 L
 * @param L
 */
void DestroyList(SqList *L) {

    free(L->elem);
    L->elem = NULL;
    L->length = 0;
    L->listsize = 0;
}

/**
 * 初始条件: 顺序线性表 L 已存在
 * 操作结果: 将 L 重置为空表
 */
void ClearList(SqList *L) {
    L->length = 0;
}


