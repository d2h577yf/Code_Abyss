#include <math.h>
#include <stdio.h>

char a, b = '0';
int n = 0, ans[1000001], zz = 1;

int main() {
  while (scanf("%c", &a) != EOF) {
    if (a == '\n')
      continue;

    n++;

    if (a == b) {
      ans[zz]++;
    } else {
      zz++;
      ans[zz]++;
      b = a;
    }
  }

  printf("%.0f ", sqrt(n));

  for (int i = 1; i <= zz; i++) {
    printf("%d ", ans[i]);
  }

  return 0;
}
