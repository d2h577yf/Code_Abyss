
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
  char s[100];
  int cnt = 0;
  fgets(s, sizeof(s), stdin);

  int len = strlen(s);
  for (int i = 0; i < len; i++) {
    if (s[i] != ' ' && s[i] != '\n') {
      cnt++;
    }
  }

  printf("%d\n", cnt);
  return EXIT_SUCCESS;
}
