#include <assert.h>
#include <errno.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  int n, local, luogu;
  scanf("%d", &n);

  local = 5 * n;
  luogu = 11 + 3 * n;

  if (local < luogu) {
    printf("Local\n");
  } else {
    printf("Luogu\n");
  }

  return EXIT_SUCCESS;
}
