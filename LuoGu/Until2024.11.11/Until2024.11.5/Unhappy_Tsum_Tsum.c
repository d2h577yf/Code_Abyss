#include <assert.h>
#include <errno.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  int day_arr[7][2], sum[7] = {0}, maxIndex = 0;
  bool valid = false; // 标记所有天数是否都不超过8

  for (int i = 0; i < 7; i++) {
    for (int j = 0; j < 2; j++) {
      scanf("%d", &day_arr[i][j]);
      sum[i] += day_arr[i][j];
    }

    // 检查是否有一天超过8小时
  }

  for (int i = 0; i < 7; i++) {

    if (sum[i] > 8) {

      valid = true;
    }

    // 记录当前最大和的天数索引
    if (sum[i] > sum[maxIndex]) {
      maxIndex = i;
    }
  }
  // 如果有任何一天超过8小时，则输出0；否则输出最大和的那天的索引
  if (!valid) {
    printf("0\n");
  } else {
    printf("%d\n", maxIndex + 1);
  }

  return EXIT_SUCCESS;
}
