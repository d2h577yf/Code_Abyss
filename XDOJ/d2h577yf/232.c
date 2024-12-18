#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  char str[51];
  fgets(str, sizeof(str), stdin);
  int cnt = 0, flag = 1;

  for (int i = 0; str[i] != '\0' && str[i] != '\n'; i++) {
    cnt++;
  }

  for (int i = 0; i < cnt / 2; i++) {
    if (str[i] != str[cnt - i - 1]) {
      flag = 0;
      break;
    }
  }

  if (flag == 1) {
    printf("yes\n");
  } else {
    printf("no\n");
  }

  return EXIT_SUCCESS;
}
