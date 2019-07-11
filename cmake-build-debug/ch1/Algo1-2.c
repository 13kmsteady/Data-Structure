#include <stdio.h>
#include <sys/timeb.h>

int main() {
    struct timeb t1, t2;
    long t;
    double x, sum = 1, sum1;
    int i, n;
    printf("请输入 x n:");
    scanf("%lf%d", &x, &n);

    ftime(&t1); // 获取当前时间
    for (i = 1; i <= n; i++) {
        sum1 *= -1.0 / x;
        sum += sum1;
    }

    ftime(&t2); // 获取当前时间
    t = (t2.time - t1.time) * 1000 + (t2.millitm - t1.millitm);
    printf("sum=%lf 用时%ld毫秒\n", sum, t);
    return 0;
}