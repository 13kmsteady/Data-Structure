/**
 * =========================================================
 *
 * 汉诺塔
 *
 * =========================================================
 */

#include "../../ch1/C1.h"

int c = 0;

void move(char x, int n, char z) {
    printf("第 %i 步,  将编号 %i 盘,从 %c 移动到 %c\n", ++c, n, x, z);
}

void hanoi(int n, char x, char y, char z) {
    if (n == 1) {
        move(x, 1, z);
    } else {
        hanoi(n - 1, x, z, y); // 将 x 上编号为 1 ~ n-1 的圆盘移动到 y, z 作为辅助塔
        move(x, n, z); // 将编号为 n 的圆盘从 x 上移动到 z
        hanoi(n - 1, y, x, z); // 将 y 上编号为 1 ~ n-1 的圆盘移动到 z, x 作为辅助塔
    }
}

int main() {
    int n = 0;
    printf("3 个塔座为 x、y、z，圆盘最初在 x 座，借助 y 座移到 z 座。请输入圆盘数：");
    scanf("%d", &n);
    hanoi(n, 'x', 'y', 'z');
    return 0;
}

