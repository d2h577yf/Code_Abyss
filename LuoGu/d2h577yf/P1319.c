#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    int total = n * n; // 矩阵总点数
    int count = 0; // 当前已经处理的点数
    int flag = 0; // 0 表示当前处理的是 0，1 表示当前处理的是 1
    int temp; // 当前压缩码

    while (count < total) {
        scanf("%d", &temp);
        for (int i = 0; i < temp; i++) {
            if (count > 0 && count % n == 0) {
                printf("\n"); // 到达行末换行
            }
            printf("%d", flag); // 打印当前点
            count++;
        }
        flag = 1 - flag; // 切换 0 和 1
    }

    return 0;
}


