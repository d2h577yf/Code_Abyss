#include <stdio.h>

int main(int argc, char const *argv[]) {
  int move[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
  int a[15][15];
  int n, x = 1, y = 1, d = 0;
  scanf("%d", &n);
  for (int i = 1; i <= n * n; i++) {
    a[x][y] = i;
    int nextX = x + move[d][0], nextY = y + move[d][1];
    if (nextX < 1 || nextX > n || nextY < 1 || nextY > n || a[nextX][nextY]) {
      d = (d + 1) % 4;
    }
    x += move[d][0];
    y += move[d][1];
  }

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      printf("%3d", a[i][j]);
    }
    printf("\n");
  }

  return 0;
}
