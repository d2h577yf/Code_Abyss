#include <assert.h>
#include <errno.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
  int *num1 = (int *)a;
  int *num2 = (int *)b;

  if (num1[1] == num2[1]) {
    return num1[0] - num2[0];
  }
  return num2[1] - num1[1];
}

int main(int argc, char *argv[]) {
  int n;
  scanf("%d", &n);

  int arr[n][2];

  for (int i = 0; i < n; i++) {
    scanf("%d", &arr[i][0]);
    arr[i][1] = 1;
  }

  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      if (arr[i][0] == arr[j][0]) {
        arr[i][1]++;
        arr[j][0] = -1;
      }
    }
  }

  int cnt = 0;
  for (int i = 0; i < n; i++) {
    if (arr[i][0] != -1) {
      arr[cnt][0] = arr[i][0];
      arr[cnt][1] = arr[i][1];
      cnt++;
    }
  }

  qsort(arr, cnt, sizeof(arr[0]), compare);

  for (int i = 0; i < cnt; i++) {
    printf("%d %d\n", arr[i][0], arr[i][1]);
  }

  return EXIT_SUCCESS;
}
