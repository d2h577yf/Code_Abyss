#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int main(int argc, char *argv[])
{
  int N, cnt = 0;
  scanf("%d", &N);
  
  int arr[N][3];
  int sum[N];
  memset(sum, 0, sizeof(sum));
  
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < 3; j++) {
      scanf("%d", &arr[i][j]);
    }
  }

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < 3; j++) {
      sum[i] += arr[i][j];
    }
  }

  for (int i = 0; i < N; i++) {      // 修正循环
    for (int j = i + 1; j < N; j++) { // 避免重复比较和对角线比较
      if (abs(sum[i] - sum[j]) <= 10) {
        int temp = 0;
        for (int x = 0; x < 3; x++) { // 修正变量 `x` 的声明
          if (abs(arr[i][x] - arr[j][x]) <= 5) {
            temp++;
          } 
        }
        if (temp == 3) {
          cnt++;
        }
      }
    }
  }

  printf("%d\n", cnt);
  
  return EXIT_SUCCESS;
}
