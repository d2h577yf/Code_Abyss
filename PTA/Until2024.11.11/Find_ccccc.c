
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// 查找等差数列的起始位置
int find_start_position(int arr[], int size, int min_sum, int max_length) {
    int a1 = (double)min_sum/max_length - (max_length - 1) * (1.0 / 2);

    for (int i = 0; i < size; i++) {
        if (arr[i] == a1) {
            return i;
        }
    }

    return -1;
}

int main(int argc, char *argv[])
{
    int N, cnt = 0;
    
    // 读取输入
    scanf("%d", &N);

    if (N < 2) {
        printf("%d\n", 0);
        return 0; 
    }

    // 使用只遍历到 sqrt(N) 的优化方法来找因子
    int max_possible_factors = 2 * sqrt(N); // 预估最大因子数
    int s[max_possible_factors]; // 动态数组用于存储因子
    int index = 0;

    for (int i = 1; i <= sqrt(N); i++) {
        if (N % i == 0) {
            s[index++] = i;
            if (i != N / i) {
                s[index++] = N / i; // 添加互补因子
            }
        }
    }

    cnt = index; // 更新因子总数
    
    // 对因子数组进行排序（使因子按大小顺序排列）
    for (int i = 0; i < cnt - 1; i++) {
        for (int j = i + 1; j < cnt; j++) {
            if (s[i] > s[j]) {
                int temp = s[i];
                s[i] = s[j];
                s[j] = temp;
            }
        }
    }

    // 寻找最大连续长度和最小和
    int start = 0, max_length = 0, max_start = 0, sum = 0, min_sum = 0;

    for (int i = 1; i <= cnt; i++) {
        if (i == cnt || s[i] != s[i - 1] + 1) { // 当当前因子不连续时
            int length = i - start; 
            sum = 0;

            // 计算当前序列的和
            for (int j = start; j < i; j++) {
                sum += s[j];
            }

            // 判断是否为最大长度或最小和
            if (length > max_length) {
                max_length = length;
                max_start = start;
                min_sum = sum; 
            } else if (length == max_length && sum < min_sum) {
                min_sum = sum;
                max_start = start; 
            }

            start = i; // 更新新的起始位置
        }
    }

    // 找到最小和对应的起始位置
    int min_start = find_start_position(s, cnt, min_sum, max_length);

    // 输出最大长度
    printf("%d\n", max_length);
    
    // 输出连续因子序列
    for (int i = min_start; i < min_start + max_length - 1; i++) {
        printf("%d*", s[i]);
    }
    printf("%d\n", s[min_start + max_length - 1]);

    return EXIT_SUCCESS;
}
