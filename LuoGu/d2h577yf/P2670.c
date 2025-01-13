
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
  int n, m;
  scanf("%d %d", &n, &m);
  char in[n][m];
  char out[n + 2][m + 2];
  memset(out, '0', sizeof(out));

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      do {
        scanf("%c", &in[i][j]);
      } while (in[i][j] == '\n');
      if (in[i][j] == '*') {
        for (int z = -1; z <= 1; z++) {
          for (int x = -1; x <= 1; x++) {
            if (i + 1 + z >= 0 && i + 1 + z < n + 2 && j + 1 + x >= 0 &&
                j + 1 + x < m + 2) {
              if (out[i + 1 + z][j + 1 + x] != '*') {
                out[i + 1 + z][j + 1 + x]++;
              }
            }
          }
        }
        out[i + 1][j + 1] = '*';
      }
    }
  }

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      printf("%c", out[i][j]);
    }
    printf("\n");
  }

  return EXIT_SUCCESS;
}
