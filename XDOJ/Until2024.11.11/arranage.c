#include <stdio.h>

int main() {
  int a[2000], n;
  scanf("%d %d %d", &a[0], &a[1], &n);

  int j = 2;
  for (int i = 0; j < n; i++) {
    int p = a[i] * a[i + 1];
    if (p < 10) {
      a[j++] = p;
    } else {
      a[j++] = p / 10;
      if (j < n)
        a[j++] = p % 10;
    }
  }

  for (int k = 0; k < n; k++) {
    printf("%d%c", a[k], k < n - 1 ? ' ' : '\n');
  }

  return 0;
}
