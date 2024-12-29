#include <stdio.h>
#include <string.h>
#define MAXN 101
char str[MAXN], in[MAXN];
int main(void) {
  int q;
  scanf("%d\n%s", &q, str);
  for (int i = 1; i <= q; i++) {
    int opt;
    scanf("%d", &opt);
    if (opt == 1) {
      scanf("%s", in);
      strcat(str, in);
      printf("%s\n", str);
    } else if (opt == 2) {
      int a, b;
      scanf("%d %d", &a, &b);
      str[a + b] = '\0';
      strcpy(in, &str[a]);
      strcpy(str, in);
      printf("%s\n", str);
    } else if (opt == 3) {
      int a;
      scanf("%d %s", &a, in);
      strcat(in, &str[a]);
      str[a] = '\0';
      strcat(str, in);
      printf("%s\n", str);
    } else {
      scanf("%s", in);
      char *ans = strstr(str, in);
      printf("%d\n", ans != NULL ? (int)(ans - str) : -1);
    }
  }
  return 0;
}
