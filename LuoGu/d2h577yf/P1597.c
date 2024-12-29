#include <stdio.h>

int a[3];
char s1, s2;

int main() {
  while (scanf("%c:=%c;", &s1, &s2) == 2) {
    if (s2 >= '0' && s2 <= '9') {
      a[s1 - 'a'] = s2 - '0';
    } else {
      a[s1 - 'a'] = a[s2 - 'a'];
    }
  }
  printf("%d %d %d", a[0], a[1], a[2]);
  return 0;
}
