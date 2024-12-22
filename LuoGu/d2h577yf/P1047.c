#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  int l, n, cnt = 0;
  scanf("%d %d", &l, &n);
  int tree[l + 1], area[n][2];
  for (int i = 0; i < l + 1; i++) {
    tree[i] = 1;
  }

  for (int i = 0; i < n; i++) {
    scanf("%d %d", &area[i][0], &area[i][1]);
  }

  for (int i = 0; i < n; i++) {
    for (int k = area[i][0]; k <= area[i][1]; k++) {
      tree[k] = 0;
    }
  }

  for (int i = 0; i < l + 1; i++) {
    if (tree[i] == 1) {
      cnt++;
    }
  }

  printf("%d", cnt);

  return EXIT_SUCCESS;
}
