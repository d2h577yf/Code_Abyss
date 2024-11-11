#include <stdio.h>

// 雾霾指数的限制值
const int fog_lim1 = 200; // 雾霾指数低于200时不进行限行
const int fog_lim2 = 400; // 雾霾指数在200到400之间时，每天限行两个尾号

// 这是一个二维数组，用来存储每周一至周五每天限行的两个车牌尾号
const int weekday_limits[5][2] = {
    {1, 6}, // 周一限行尾号1和6
    {2, 7}, // 周二限行尾号2和7
    {3, 8}, // 周三限行尾号3和8
    {4, 9}, // 周四限行尾号4和9
    {5, 0}  // 周五限行尾号5和0
};

// 这个函数根据输入的星期几、雾霾指数和车牌尾号判断是否限行
void check_restriction(int day, int fog_num, int car_numEnd) {
    // 首先判断是否为周末或者雾霾指数低于200
    if (day == 6 || day == 7 || fog_num < fog_lim1) {
        // 周六、周日不限行，或者雾霾指数小于200时直接输出 "no"
        printf("%d no\n", car_numEnd);
        return; // 退出函数，不再继续检查
    }

    // 如果雾霾指数在200到400之间，按照每周限行两个尾号的规则进行判断
    if (fog_num < fog_lim2) {
        // 从weekday_limits数组中取出对应日期的两个限行尾号
        int limit1 = weekday_limits[day - 1][0];
        int limit2 = weekday_limits[day - 1][1];
        // 判断车牌尾号是否为当天限行的两个尾号之一
        printf("%d %s\n", car_numEnd, (car_numEnd == limit1 || car_numEnd == limit2) ? "yes" : "no");
    } else {
        // 雾霾指数大于等于400时，限行规则变为奇偶号限行
        if ((day == 1 || day == 3 || day == 5) && car_numEnd % 2 == 1) {
            // 周一、周三、周五限行奇数尾号 (1, 3, 5, 7, 9)
            printf("%d yes\n", car_numEnd);
        } else if ((day == 2 || day == 4) && car_numEnd % 2 == 0) {
            // 周二、周四限行偶数尾号 (0, 2, 4, 6, 8)
            printf("%d yes\n", car_numEnd);
        } else {
            // 其他情况则不需要限行
            printf("%d no\n", car_numEnd);
        }
    }
}

// 主函数，负责读取输入和调用限行检查函数
int main() {
    int day, fog_num, car_num; // 定义变量：day表示星期几，fog_num表示雾霾指数，car_num表示车牌号
    // 通过标准输入读取三个整数，分别为星期几、雾霾指数和车牌号
    scanf("%d %d %d", &day, &fog_num, &car_num);
    // 调用限行检查函数，将星期几、雾霾指数和车牌号的最后一位数字传入
    check_restriction(day, fog_num, car_num % 10); // car_num % 10 表示取车牌号的最后一位数字
    return 0; // 程序正常结束
}
