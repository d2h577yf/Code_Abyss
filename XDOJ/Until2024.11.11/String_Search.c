#include <assert.h>
#include <ctype.h>
#include <errno.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void find_out(char strlist[][100], char str[], char index[], int length,
              int n) {
  char other[length + 1];
  for (int i = 0; i < n; i++) {
    index[i] = 0;
    for (int j = 0; j <= strlen(strlist[i]) - length; j++) {
      strncpy(other, strlist[i] + j, length);
      other[length] = '\0';

      if (strcmp(other, str) == 0) {
        index[i] = 1;
        break;
      }
    }
  }
}

int main(int argc, char *argv[]) {
  int state, n;
  char str[100] = {0};

  scanf("%s", str);
  scanf("%d", &state);
  scanf("%d", &n);

  int length = strlen(str);

  char strlist[n][100], find_out_list[n][100];

  for (int i = 0; i < n; i++) {
    scanf("%s", strlist[i]);
  }

  memcpy(find_out_list, strlist, sizeof(strlist));

  char index[n];

  switch (state) {
  case 1:
    find_out(strlist, str, index, length, n);
    break;

  case 0:
    for (int i = 0; i < length; i++) {
      str[i] = tolower(str[i]);
    }

    for (int i = 0; i < n; i++) {
      for (int j = 0; strlist[i][j] != '\0'; j++) {
        strlist[i][j] = tolower(strlist[i][j]);
      }
    }

    find_out(strlist, str, index, length, n);
    break;
  }

  for (int i = 0; i < n; i++) {
    if (index[i] == 0) {
      continue;
    } else {
      printf("%s\n", find_out_list[i]);
    }
  }

  return EXIT_SUCCESS;
}
