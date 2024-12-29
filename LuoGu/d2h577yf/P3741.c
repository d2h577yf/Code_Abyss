#include <stdio.h>
#include <string.h>

int main() {
  int n, ans = 0, x;
  char s[1001];
  scanf("%d", &n);
  scanf("%s", s);
  for (x = 0; x < n - 1; x++) {
    if (s[x] == 'V' && s[x + 1] == 'K') {
      ans++;
      s[x] = 'v';
      s[x + 1] = 'k';
    }
  }
  for (x = 0; x < n - 1; x++) {
    if (s[x + 1] == s[x]) {
      ans++;
      printf("%d\n", ans);
      return 0;
    }
  }
  printf("%d\n", ans);
  return 0;
}
