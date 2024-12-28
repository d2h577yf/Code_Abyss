#include <ctype.h>
#include <stdio.h>
#include <string.h>

int main() {
  char a;
  int n, c, d;
  char s[100], b[13];

  scanf("%d", &n);
  getchar();
  for (int i = 0; i < n; i++) {
    fgets(b, 13, stdin);

    if (isalpha(b[0])) {
      sscanf(b, "%c %d %d", &a, &c, &d);
    } else {
      sscanf(b, "%d %d", &c, &d);
    }
    memset(s, 0, sizeof(s));

    if (a == 'a')
      sprintf(s, "%d+%d=%d", c, d, c + d);
    else if (a == 'b')
      sprintf(s, "%d-%d=%d", c, d, c - d);
    else if (a == 'c')
      sprintf(s, "%d*%d=%d", c, d, c * d);

    printf("%s\n%d\n", s, (int)strlen(s));
  }

  return 0;
}
