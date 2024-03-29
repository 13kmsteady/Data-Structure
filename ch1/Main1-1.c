/**
 * =========================================================
 *
 * 检验基本操作 Bo1-1.c 的主函数
 *
 * =========================================================
 */

#include "C1.h"

typedef int ElemType; // 定义抽象数据类型 ElemType 在本程序中为整型

#include "C1-1.h" // 在此命令之前要定义 ElemType 的类型
#include "Bo1-1.c" // 在此命令之前要包含 c1-1.h 文件(因为其中定义了 Triplet)
#include <windows.h>

int main() {
    system("chcp 65001 > nul");
    Triplet T;
    ElemType M;
    Status i;
    i = InitTriplet(&T, 5, 7, 9); // 初始化 3 元组 T, 其 3 个元素依次为 5,7,9
    printf("调用初始化函数后，i = %d(1:成功), T 的 3 个值为：%d %d %d\n", i, T[0], T[1], T[2]);

    i = Get(T, 2, &M); // 将 3 元组的第二个值赋值给 m
    if (OK == i)
        printf("T 的第二个值为: %d\n", M);

    i = PUT(T, 2, 6);
    if (OK == i)
        printf("将 T 的第二个值改为 6 以后, T 的 3 个值为: %d %d %d\n", T[0], T[1], T[2]);

    i = IsAscending(T);
    printf("调用测试升序的函数后, i=%d(0:否,1:是)\n", i);

    i = IsDescending(T);
    printf("调用测试降序的函数后, i=%d(0:否,1:是)\n", i);

    if (OK == Max(T, &M))
        printf("T 中的最大值为: %d\n", M);

    if (OK == Min(T, &M))
        printf("T 中的最小值为: %d\n", M);

    DestroyTriplet(&T);
    printf("销毁 T 后，T=%ls\n", T);
    return 0;
}
/**
 * =========================================================
 *
 *  程序运行结果:
 *
 *  调用初始化函数后，i = 1(1:成功), T 的 3 个值为：5 7 9
    T 的第二个值为: 7
    将 T 的第二个值改为 6 以后, T 的 3 个值为: 5 6 9
    调用测试升序的函数后, i=1(0:否,1:是)
    调用测试降序的函数后, i=0(0:否,1:是)
    T 中的最大值为: 9
    T 中的最小值为: 5
    销毁 T 后，T=(null)

 * =========================================================
 */