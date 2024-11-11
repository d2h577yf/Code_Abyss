#include <assert.h>
#include <ctype.h>
#include <errno.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
  char input[50] = {0};
  char str[50] = {0};
  int num[50] = {0};

  scanf("%s", input);

  int strIndex = 0;
  int numIndex = 0;

  for (int i = 0; i < 50; i++) {
    if (input[i] == '\0') {
      break;
    }

    if (isalpha(input[i])) {
      str[strIndex++] = input[i];
      num[numIndex++] = 1;
    } else if (isdigit(input[i])) {
      int digit = input[i] - '0';

      if (isdigit(input[i + 1])) {
        digit = digit * 10 + (input[i + 1] - '0');
        i++;
      }

      num[numIndex - 1] = digit;
    }
  }

  for (int i = 0; i < strIndex; i++) {
    for (int j = 0; j < num[i]; j++) {
      printf("%c", str[i]);
    }
  }

  return EXIT_SUCCESS;
}
