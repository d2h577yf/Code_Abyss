#include <stdio.h>

int main() {
  int n, h, b[101] = {0}, i, j, m;

  scanf("%d", &n);

  for (i = 0; i < n; i++) {
    scanf("%d", &h);
    for (j = 0; j < h; j++) {
      scanf("%d", &m);
      b[m]++;
    }
  }

  int max_count = 0, max_tag = 0;
  for (i = 1; i <= 100; i++) {
    if (b[i] > max_count || (b[i] == max_count && i > max_tag)) {
      max_count = b[i];
      max_tag = i;
    }
  }

  printf("%d %d\n", max_tag, max_count);

  return 0;
}
