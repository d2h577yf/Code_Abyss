#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct eee {
  int yuwen, shuxue, yingyu, zf;
  char s[101];
};

int n;
struct eee a[1001];

int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) {
    scanf("%s %d %d %d", a[i].s, &a[i].yuwen, &a[i].shuxue, &a[i].yingyu);
    a[i].zf = a[i].yuwen + a[i].shuxue + a[i].yingyu;
  }

  for (int i = 1; i < n; ++i) {
    for (int j = i + 1; j <= n; ++j) {
      if (strcmp(a[i].s, a[j].s) > 0) {
        struct eee temp = a[i];
        a[i] = a[j];
        a[j] = temp;
      }
    }
  }

  for (int i = 1; i < n; ++i) {
    for (int j = i + 1; j <= n; ++j) {
      if (abs(a[i].yuwen - a[j].yuwen) <= 5 &&
          abs(a[i].shuxue - a[j].shuxue) <= 5 &&
          abs(a[i].yingyu - a[j].yingyu) <= 5 && abs(a[i].zf - a[j].zf) <= 10) {
        printf("%s %s\n", a[i].s, a[j].s);
      }
    }
  }

  return 0;
}
