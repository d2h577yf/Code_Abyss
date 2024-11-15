#include <assert.h>
#include <errno.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
  int n, m;
  scanf("%d %d", &n, &m);

  int arr[n][m];
  int columns[n][m];
  int line[n][m];

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      columns[i][j] = 1;
      line[i][j] = 1;
    }
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      scanf("%d", &arr[i][j]);
    }
  }

  for (int i = 0; i < n; i++) {
    for (int j = 1; j < m; j++) {
      if (arr[i][j - 1] == arr[i][j]) {
        line[i][j] = line[i][j - 1] + 1;
      }
    }
  }

  for (int i = 0; i < m; i++) {
    for (int j = 1; j < n; j++) {
      if (arr[j][i] == arr[j - 1][i]) {
        columns[j][i] = columns[j - 1][i] + 1;
      }
    }
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (line[i][j] >= 3) {
        for (int x = line[i][j]; x > 0; x--) {
          arr[i][j - x + 1] = 0;
        }
      }
    }
  }

  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      if (columns[j][i] >= 3) {
        for (int x = columns[j][i]; x > 0; x--) {
          arr[j - x + 1][i] = 0;
        }
      }
    }
  }

  printf("\n");
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      printf("%d ", arr[i][j]);
    }
    printf("\n");
  }

  return EXIT_SUCCESS;
}
