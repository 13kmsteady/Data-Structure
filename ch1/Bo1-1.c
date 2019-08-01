
/**
 * =========================================================
 *
 *  抽象数据类型 Triplet 和 ElemType 的 8 个基本操作
 *
 * =========================================================
 */

#include "C1.h"
#include "C1-1.h"

/**
 *  操作结果：构造三元组T，依次置T的3个元素的初值为v1，v2和v3
 * @param T
 * @param v1
 * @param v2
 * @param v3
 * @return
 */
Status InitTriplet(Triplet *T, ElemType v1, ElemType v2, ElemType v3) {
    *T = (ElemType *) malloc(3 * sizeof(ElemType));
    if (!*T)
        exit(OVERFLOW);
    (*T)[0] = v1, (*T)[1] = v2, (*T)[2] = v3;
    return OK;
}

/**
 * 销毁三元组 T
 * @param T
 * @return
 */
Status DestroyTriplet(Triplet *T) {
    free(*T);
    *T = NULL;
    return OK;
}

/**
 * 初始条件: 三元组 T 已存在, 1 ≤ i ≤ 3
 * 操作结果: 用 e 返回 T 的第 i 个元素的值
 * @param T
 * @param i
 * @param e
 * @return
 */
Status Get(Triplet T, int i, ElemType *e) {
    if (i < 1 || i > 3)
        return ERROR;
    *e = T[i - 1];
    return OK;
}

/**
 * 初始条件: 三元组 T 已存在, 1 ≤ i ≤ 3
 * 操作结果: 改变 T 的第 i 个元素的值
 *
 * @param T
 * @param i
 * @param e
 * @return
 */
Status PUT(Triplet T, int i, ElemType e) {
    if (i < 1 || i > 3)
        return ERROR;
    T[i - 1] = e;
    return OK;
}

Status IsAscending(Triplet T) {
    return T[0] <= T[1] && T[1] <= T[2];
}

Status IsDescending(Triplet T) {
    return T[0] >= T[1] && T[1] >= T[2];
}

Status Max(Triplet T, ElemType *e) {

    *e = T[0] >= T[1] ? T[0] >= T[2] ? T[0] : T[2] : T[1] >= T[2] ? T[1] : T[2];
    return OK;
}

Status Min(Triplet T, ElemType *e) {
    *e = T[0] <= T[1] ? T[1] <= T[2] ? T[0] : T[2] : T[1] <= T[2] ? T[1] : T[2];
    return OK;
}