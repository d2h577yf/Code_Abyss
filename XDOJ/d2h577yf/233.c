#include <stdio.h>
#include <stdlib.h>

void copystr(char *str, char *copyStr, int m) {
  int i, j = 0;
  for (i = m - 1; str[i] != '\n' && str[i] != '\0'; i++) {
    copyStr[j++] = str[i];
  }
  copyStr[j] = '\0';
}

int main(int argc, char *argv[]) {
  char str[51], copyStr[51];
  int m, cnt = 0;

  fgets(str, sizeof(str), stdin);
  scanf("%d", &m);

  for (int i = 0; str[i] != '\n' && str[i] != '\0'; i++) {
    cnt++;
  }

  if (m <= cnt) {
    copystr(str, copyStr, m);
    printf("%s\n", copyStr);
  } else {
    printf("error\n");
  }

  return EXIT_SUCCESS;
}
