#include <assert.h>
#include <errno.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int count_unique(int *arr, int size) {
  bool visited[101] = {0};
  int count = 0;

  for (int i = 0; i < size; i++) {
    if (arr[i] != -1 && !visited[arr[i]]) {
      visited[arr[i]] = true;
      count++;
    }
  }

  return count;
}

int main(int argc, char *argv[]) {
  int n, m, t, k;
  scanf("%d %d %d %d", &n, &m, &t, &k);
  int arr[n + 2][m + 2];

  memset(arr, -1, sizeof(arr));

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      scanf("%d", &arr[i][j]);
    }
  }

  int num[4 * (n + m)];
  int idx = 0;

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (arr[i][j] == k) {
        if (arr[i - 1][j] != k)
          num[idx++] = arr[i - 1][j];
        if (arr[i + 1][j] != k)
          num[idx++] = arr[i + 1][j];
        if (arr[i][j - 1] != k)
          num[idx++] = arr[i][j - 1];
        if (arr[i][j + 1] != k)
          num[idx++] = arr[i][j + 1];
      }
    }
  }

  printf("%d\n", count_unique(num, idx));

  return EXIT_SUCCESS;
}
