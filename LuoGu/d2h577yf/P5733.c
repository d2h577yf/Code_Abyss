#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
  char small[101];
  scanf("%s", small);

  int len = strlen(small);

  for (int i = 0; i < len; i++) {
    if (isalpha(small[i])) {
      small[i] = toupper(small[i]);
    }
  }

  printf("%s", small);

  return EXIT_SUCCESS;
}
