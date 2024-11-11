#include <assert.h>
#include <errno.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  int n, k, cnt_A = 0, cnt_B = 0;
  double sum_A = 0, sum_B = 0, aver_A, aver_B;
  scanf("%d %d", &n, &k);
  int arr[n];

  for (int i = 1; i <= n; i++) {
    arr[i - 1] = i;
  }

  for (int j = 0; j < n; j++) {
    if (arr[j] % k == 0) {
      sum_A += arr[j];
      cnt_A++;
    } else {
      sum_B += arr[j];
      cnt_B++;
    }
  }

  aver_A = sum_A / cnt_A;
  aver_B = sum_B / cnt_B;
  printf("%.1f %.1f\n", aver_A, aver_B);
  return EXIT_SUCCESS;
}
