
#include <stdio.h>
#include <string.h>

int main() {
  int boy = 0, girl = 0;
  char st[1001];
  scanf("%s", st);
  int len = strlen(st);
  for (int i = 0; i <= len; i++) {
    if (st[i] == 'b' || st[i + 1] == 'o' || st[i + 2] == 'y')
      boy++;
    if (st[i] == 'g' || st[i + 1] == 'i' || st[i + 2] == 'r' ||
        st[i + 3] == 'l')
      girl++;
  }
  printf("%d\n", boy);
  printf("%d\n", girl);
  return 0;
}
