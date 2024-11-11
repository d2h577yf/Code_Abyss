#include <assert.h>
#include <errno.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  int x;
  scanf("%d", &x);

  if (x <= 1) {
    printf("Today, I ate %d apple.\n", x);
  } else {
    printf("Today, I ate %d apples.\n", x);
  }

  return EXIT_SUCCESS;
}
