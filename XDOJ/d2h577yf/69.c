#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  int m, n;
  scanf("%d %d", &m, &n);

  int arr[m][n], sum[m][n];

  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      scanf("%d", &arr[i][j]);
    }
  }

  for (int i = 0; i < m; i++) {
    sum[i][0] = arr[i][0] == 1 ? 1 : 0;
    for (int j = 1; j < n; j++) {
      if (arr[i][j] == 1) {
        sum[i][j] = sum[i][j - 1] + 1;
      } else {
        sum[i][j] = 0;
      }
    }
  }

  for (int i = 0; i < m; i++) {
    int maxLen = 0, endIndex = -1;

    for (int j = 0; j < n; j++) {
      if (sum[i][j] > maxLen) {
        maxLen = sum[i][j];
        endIndex = j;
      }
    }

    if (maxLen > 0) {
      int startIndex = endIndex - maxLen + 1;
      printf("%d %d\n", startIndex, endIndex);
    } else {
      printf("-1 -1\n");
    }
  }

  return EXIT_SUCCESS;
}
