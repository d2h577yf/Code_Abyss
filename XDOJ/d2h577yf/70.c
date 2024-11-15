
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  int n;
  scanf("%d", &n);

  int arr[n][n];
  int num[n * n];

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      scanf("%d", &arr[i][j]);
    }
  }

  int cnt = 0;

  for (int x = 0; x < 2 * n - 1; x++) {
    if (x >= n) {
      for (int i = x - n + 1, j = n - 1; i < n; i++, j--) {
        if (x % 2 == 0) {
          num[cnt++] = arr[j][i];
        } else {
          num[cnt++] = arr[i][j];
        }
      }
    } else {
      for (int i = x, j = 0; i >= 0; i--, j++) {
        if (x % 2 == 0) {
          num[cnt++] = arr[i][j];
        } else {
          num[cnt++] = arr[j][i];
        }
      }
    }
  }

  for (int i = 0; i < n * n; i++) {
    printf("%d ", num[i]);
  }

  return EXIT_SUCCESS;
}
