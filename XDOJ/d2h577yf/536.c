#include <stdio.h>

void paint(int, int (*)[4], int *);

int main() {
  int n, l[100][4];
  int result[300];
  int i;

  scanf("%d", &n);

  for (i = 0; i < n; i++) {
    scanf("%d%d%d%d", &l[i][0], &l[i][1], &l[i][2], &l[i][3]);
  }

  paint(n, l, result);

  for (i = 0; i <= result[0]; i++) {
    printf("%d %d\n", result[i * 2], result[i * 2 + 1]);
  }

  return 0;
}
