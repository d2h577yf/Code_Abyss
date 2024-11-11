#include <assert.h>
#include <errno.h>
#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  int a, days = 1;
  scanf("%d", &a);

  while (a != 1) {
    a = floor(a / 2);
    days++;
  }

  printf("%d\n", days);

  return EXIT_SUCCESS;
}
