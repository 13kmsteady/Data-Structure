#include "../ch1/C1.h"

/**
 * =========================================================
 *
 * 常用函数
 *
 * =========================================================
 */

Status equal(ElemType e1, ElemType e2) {
    if (e1 == e2)
        return TRUE;
    else
        return FALSE;
}

int comp(ElemType a, ElemType b) {
    if (a == b)
        return 0;
    else
        return 1;
}

void print(ElemType c) {
    printf("%d ", c);
}

void print1(ElemType *c) {
    printf("%d ", *c);
}

void print2(ElemType c) {
    printf("%c ", c);
}



