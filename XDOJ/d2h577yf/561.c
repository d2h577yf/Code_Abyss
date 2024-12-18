#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
  char str[101];
  scanf("%s", str);
  int len = strlen(str);

  char newStr[2 * len];

  char *p = str, *q = newStr;

  for (int i = 0; i < len; i++) {
    *q++ = *p++;
    if (i != len - 1) {
      *q++ = ' ';
    }
  }

  *q = '\0';

  printf("%s\n", newStr);

  return EXIT_SUCCESS;
}
