
#include <stdio.h>
#include <string.h>

int main() {
  char s[1000], p = 0;
  int cnt = 0, x;

  scanf("%s", s);

  for (int i = 0; i < strlen(s); i++) {
    if (s[i] >= '0' && s[i] <= '9') {
      cnt++;
    } else {
      p = s[i];
      break;
    }
  }

  x = cnt;
  cnt--;

  while (s[cnt] == '0' && cnt > 0) {
    cnt--;
  }

  for (int i = cnt; i >= 0; i--) {
    printf("%c", s[i]);
  }

  if (p == 0) {
    return 0;
  } else {
    if (p == '%') {
      printf("%c", p);
      return 0;
    } else {
      printf("%c", p);
    }
  }

  int m = strlen(s) - 1;
  while (s[x + 1] == '0' && x < m - 1) {
    x++;
  }

  while (s[m] == '0' && m > x + 1) {
    m--;
  }

  for (int i = m; i > x; i--) {
    printf("%c", s[i]);
  }

  return 0;
}
