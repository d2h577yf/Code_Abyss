#include <stdio.h>

int n, a[40][40], x, y;

int main() {
  scanf("%d", &n);
  x = 0;
  y = n / 2;

  for (int i = 1; i <= n * n; i++) {
    a[x][y] = i;

    if (!a[(x - 1 + n) % n + 1][y % n + 1]) {
      x = (x - 1 + n) % n + 1;
      y = y % n + 1;
    } else {
      x = x % n + 1;
    }
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      printf("%d ", a[i][j]);
    }
    printf("\n");
  }

  return 0;
}
