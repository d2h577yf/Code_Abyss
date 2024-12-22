
#include <stdio.h>

int main() {
  int n, a[1002] = {0}, i = 1;
  scanf("%d", &n);

  while (n != 1) {
    a[i] = n;
    i++;
    if (n % 2 == 0) {
      n /= 2;
    } else {
      n = 3 * n + 1;
    }
  }
  a[i] = 1;

  for (int j = i; j >= 1; j--) {
    printf("%d ", a[j]);
  }

  return 0;
}
