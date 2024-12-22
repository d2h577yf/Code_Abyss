#include <stdio.h>
#include <string.h>

int main() {
  int judge[30][30][30] = {0};
  int w, x, h, q, a, b, c, d, e, f, ans = 0;
  scanf("%d %d %d %d", &w, &x, &h, &q);
  for (int i = 1; i <= q; ++i) {
    scanf("%d %d %d %d %d %d", &a, &b, &c, &d, &e, &f);
    for (int j = a; j <= d; ++j)
      for (int k = b; k <= e; ++k)
        for (int l = c; l <= f; ++l)
          judge[j][k][l] = 1;
  }
  for (int i = 1; i <= w; ++i)
    for (int j = 1; j <= x; ++j)
      for (int k = 1; k <= h; ++k)
        if (judge[i][j][k] == 0)
          ans++;
  printf("%d\n", ans);
  return 0;
}
