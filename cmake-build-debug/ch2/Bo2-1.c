/**
 * =========================================================
 *
 *  顺序表示的线性表, 存储结构由 (c2-1.h) 定义, 演示基本的 12 个操作
 *  包括算法 2.3,2.4,2.5,2.6
 *
 * =========================================================
 */

#include "../ch1/C1.h"

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

/**
 * 初始条件: 顺序线性表 L 已存在
 * 操作结果: 若 L 为空表,则返回 true,否则返回 false
 * @param L
 * @return
 */
Status ListEmpty(SqList L) {
    if (0 == L.length)
        return TRUE;
    else
        return FALSE;
}

/**
 * 初始条件: 顺序线性表 L 已存在
 * 操作结果: 返回 L 中元素个数
 * @return
 */
int ListLength(SqList L) {
    return L.length;
}

/**
 * 初始条件: 顺序线性表 L 已存在
 * 操作结果: 用 e 返回 L 中第 i 个元素的值
 * @param L
 * @param i
 * @param e
 * @return
 */
Status GetElem(SqList L, int i, ElemType *e) {
    if (i < 1 || i > L.length)
        return ERROR;
    *e = L.elem[i-1];
    return OK;
}

/**
 * 算法 2.6
 * 初始条件: 顺序线性表 L 已存在, compare() 是数据元素判定函数(满足为 1, 否则为 0)
 * 操作结果: 返回 L 中第一个与 e 满足关系 compare() 的数据元素的位序
 *          若这样的数据元素不存在,则返回值为 0
 * @param L
 * @param e
 * @param compare
 * @return
 */
int LocateElem(SqList L, ElemType e, Status(*compare)(ElemType, ElemType)) {
    ElemType *p;
    int i = 1; // i 的初始值为第一个元素的位序
    p = L.elem; // p 的初始值为第一个元素的存储位置
    while (i <= L.length && !compare(*p++, e))
        ++i;
    if (i <= L.length)
        return i;
    else
        return 0;
}

/**
 * 初始条件: 顺序线性表 L 已存在
 * 操作结果: 若 cur_e 是 L 的数据元素,且不是第一个,则用 pre_e 返回它的前驱
 *          否则操作失败,pre_e 无定义
 * @param L
 * @param cur_e
 * @param pre_e
 * @return
 */
Status PriorElem(SqList L, ElemType cur_e, ElemType *pre_e) { // L 0 地址
    int i = 2;
    ElemType *p = L.elem + 1;
    while (i <= L.length && *p != cur_e) {
        p++;
        i++;
    }
    if (i > L.length)
        return INFEASIBLE; // 操作失败
    else {
        *pre_e = *--p;
        return OK;
    }
}

/**
 * 初始条件: 顺序线性表 L 已存在
 * 操作结果: 若 cur_e 是 L 的数据元素,且不是最后一个,则用 next_e 返回它的后继
 *          若操作失败, next_e 无定义
 * @param L
 * @param cur_e
 * @param next_e
 * @return
 */
Status NextElem(SqList L, ElemType cur_e, ElemType *next_e) {
    int i = 1;
    ElemType *p = L.elem;
    while (i < L.length && *p != cur_e) {
        i++;
        p++;
    }
    if (i == L.length)
        return INFEASIBLE; // 操作失败
    else {
        *next_e = *++p;
        return OK;
    }
}

/**
 * 算法 2.4
 * 初始条件: 顺序线性表 L 已存在
 * 操作结果: 在 L 中第 i 个位置之前插入新的数据元素 e, L 的长度加 1
 * @param L
 * @param i
 * @param e
 * @return
 */
Status ListInsert(SqList *L, int i, ElemType e) {
    ElemType *newbase, *q, *p;
    if (i < 1 || i > L->length + 1) // 采用一块地址连续的内从存储数据
        return ERROR; // i 值不合法

    if (L->length >= L->listsize) { // 当前存储空间已满,增加分配
        newbase = (ElemType *) realloc(L->elem, (L->listsize + LIST_INCREMENT) * sizeof(ElemType));
        if (!newbase)
            exit(OVERFLOW); // 存储分配失败
        L->elem = newbase; // 新的地址
        L->listsize += LIST_INCREMENT; // 增加存储容量
    }
    q = L->elem + i - 1; // q 为插入位置
    // 插入位置及之后的元素右移
    for (p = L->elem+L->length-1; p >= q; --p)
        *(p + 1) = *p;
    *q = e; // 插入 e
    ++L->length; // 表长加 1
    return OK;
}

/**
 * 算法 2.5
 * 初始条件: 顺序线性表 L 已存在
 * 操作结果: 删除 L 的第i个数据元素, 并用 e 返回其值
 * @param L
 * @param i
 * @param e
 * @return
 */
Status ListDelete(SqList *L, int i, ElemType *e) {
    ElemType *p, *q;
    if (i < 1 || i > L->length)
        return ERROR; // i 值不合法
    p = L->elem + i - 1; // p 为被删除元素的位置
    *e = *p;// 被删除元素的值赋给 e
    q = L->elem + L->length - 1; // 表尾元素的位置
    // 被删除元素之后的元素左移
    for (++p; p <= q; ++p) {
        *(p - 1) = *p;
    }
    L->length--;
    return OK;
}

/**
 * 初始条件: 顺序线性表 L 已存在
 * 操作结果: 依次对 L 的每个数据元素调用函数 vi()
 * @param L
 * @param vi
 */
void ListTraverse(SqList L, void(*vi)(ElemType *)) {
    ElemType *p;
    int i;
    p = L.elem;
    for (i = 1; i <= L.length; i++) {
        vi(p++);
    }
    printf("\n");
}






