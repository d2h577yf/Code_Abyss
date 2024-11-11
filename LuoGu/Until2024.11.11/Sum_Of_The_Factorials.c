#include <assert.h>
#include <errno.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void putin(int arr[], int x) {
  for (int j = 1; j <= x; j++) {
    for (int i = 0; i < 1005; i++) {
      arr[i] *= j;
    }
    for (int i = 0; i < 1005; i++) {
      if (arr[i] >= 10 && arr[i] <= 99) {
        arr[i + 1] += arr[i] / 10;
        arr[i] = arr[i] % 10;
      } else if (arr[i] >= 100) {
        arr[i + 2] += arr[i] / 100;
        arr[i + 1] += (arr[i] % 100) / 10;
        arr[i] = arr[i] % 10;
      }
    }
  }
}

int main(int argc, char *argv[]) {
  int n;
  scanf("%d", &n);

  int arr[1005] = {1}, sum[1005] = {0};

  for (int i = 1; i <= n; i++) {
    memset(arr, 0, sizeof(arr));
    arr[0] = 1;

    putin(arr, i);
    for (int j = 0; j < 1005; j++) {
      sum[j] += arr[j];
      if (sum[j] >= 10) {
        sum[j + 1] += sum[j] / 10;
        sum[j] = sum[j] % 10;
      }
    }
  }

  int start = 1004;

  while (sum[start] == 0) {
    start--;
  }

  for (int i = start; i >= 0; i--) {
    printf("%d", sum[i]);
  }
  return EXIT_SUCCESS;
}
