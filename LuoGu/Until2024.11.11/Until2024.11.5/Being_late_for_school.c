
#include <stdio.h>

int main() {
    int S; // 家到学校的距离
    int V; // 行走的速度
    scanf("%d %d", &S, &V);

    // 计算所需时间（分钟），并确保向上取整
    int time_consume = (S + V - 1) / V; // 向上取整
    int total_time = time_consume + 10; // 加上垃圾分类时间

    // 从 08:00（480分钟）开始推算，减去总时间
    int departure_time = 8 * 60 - total_time; // 480 - total_time

    // 如果出发时间小于0，调整为前一天的时间
    if (departure_time < 0) {
        departure_time += 24 * 60; // 增加24小时的分钟数
    }

    // 转换为小时和分钟
    int hour = departure_time / 60;
    int min = departure_time % 60;

    // 输出结果，确保是两位数格式
    printf("%02d:%02d\n", hour, min);

    return 0;
}

