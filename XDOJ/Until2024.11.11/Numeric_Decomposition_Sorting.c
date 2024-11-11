#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) { return (*(int *)b - *(int *)a); }

int main() {
  int n;
  scanf("%d", &n);

  int digits[10];
  int cnt = 0;

  while (n > 0) {
    digits[cnt] = n % 10;
    cnt++;
    n /= 10;
  }

  qsort(digits, cnt, sizeof(int), compare);

  for (int i = 0; i < cnt; i++) {
    printf("%d", digits[i]);
    if (i < cnt - 1) {
      printf(" ");
    }
  }

  return 0;
}
