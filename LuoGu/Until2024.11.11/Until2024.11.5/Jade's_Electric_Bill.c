#include <stdio.h>

int main() {
  int a = 0;
  double b = 0; // 双精度浮点数

  scanf("%d", &a); // 输入整数a

  if (a <= 150) { // 判断小于等于150
    b = a * 0.4463;
  } else if (a >= 151 && a <= 400) { // 判断大于150且小于等于400
    b += 150 * 0.4463;
    b += (a - 150) * 0.4663;
  } else { // 大于400的情况
    b += 150 * 0.4463;
    b += (400 - 150) * 0.4663;
    b += (a - 400) * 0.5663;
  }

  // 四舍五入保留1位小数
  b = ((int)(b * 10 + 0.5)) / 10.0;

  printf("%.1f\n", b); // 输出结果，保留1位小数

  return 0;
}