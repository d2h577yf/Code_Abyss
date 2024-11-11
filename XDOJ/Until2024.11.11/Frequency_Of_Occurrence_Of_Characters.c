#include <assert.h>
#include <errno.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
  char c, str[100] = {0};
  int n, cnt = 0;
  int delta = 'A' - 'a';

  scanf("%c %d", &c, &n);
  scanf("%s", str);

  switch (n) {
  case 1:
    for (int i = 0; str[i] != '\0'; i++) {
      if (str[i] == c) {
        cnt++;
      }
    }
    break;

  case 0:
    for (int i = 0; str[i] != '\0'; i++) {
      if (str[i] == c || str[i] == (c + delta) || str[i] == (c - delta)) {
        cnt++;
      }
    }
    break;
  }

  printf("%d\n", cnt);

  return EXIT_SUCCESS;
}
