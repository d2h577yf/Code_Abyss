#include <assert.h>
#include <errno.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
  char n[200][100];
  int length[199];

  for (int i = 0; i < 200; i++) {
    fgets(n[i], sizeof(n[i]), stdin);
    n[i][strcspn(n[i], "\n")] = '\0';

    if (strcmp(n[i], "***end***") == 0) {
      break;
    }
  }

  for (int i = 0; i < 199; i++) {
    length[i] = strlen(n[i]);
  }

  int maxIndex = 0;

  for (int i = 0; i < 199; i++) {
    if (length[maxIndex] < length[i]) {
      maxIndex = i;
    }
  }

  printf("%d\n", length[maxIndex]);
  printf("%s\n", n[maxIndex]);

  return EXIT_SUCCESS;
}
