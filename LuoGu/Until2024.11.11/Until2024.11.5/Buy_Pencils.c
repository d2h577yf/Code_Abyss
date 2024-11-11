#include <assert.h>
#include <errno.h>
#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  int arr[3][2], cnt[3], sum[3], minIndex = 0;
  double n;
  scanf("%lf", &n);
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 2; j++) {
      scanf("%d", &arr[i][j]);
    }
  }
  for (int i = 0; i < 3; i++) {
    cnt[i] = ceil(n / arr[i][0]);
    sum[i] = arr[i][1] * cnt[i];
  }

  for (int j = 0; j < 3; j++) {
    if (sum[minIndex] >= sum[j]) {
      minIndex = j;
    }
  }

  printf("%d\n", sum[minIndex]);

  return EXIT_SUCCESS;
}
