#include <stdio.h>
#include <string.h>

int main() {
  int s = 0;
  char a[1001];
  fgets(a, sizeof(a), stdin);

  for (int i = 0; i < strlen(a); i++) {
    if (a[i] == 'a' || a[i] == 'd' || a[i] == 'g' || a[i] == 'j' ||
        a[i] == 'm' || a[i] == 'p' || a[i] == 't' || a[i] == 'w' ||
        a[i] == ' ') {
      s += 1;
    }
    if (a[i] == 'b' || a[i] == 'e' || a[i] == 'h' || a[i] == 'k' ||
        a[i] == 'n' || a[i] == 'q' || a[i] == 'u' || a[i] == 'x') {
      s += 2;
    }
    if (a[i] == 'c' || a[i] == 'f' || a[i] == 'i' || a[i] == 'l' ||
        a[i] == 'o' || a[i] == 'r' || a[i] == 'v' || a[i] == 'y') {
      s += 3;
    }
    if (a[i] == 's' || a[i] == 'z') {
      s += 4;
    }
  }

  printf("%d\n", s);
  return 0;
}
