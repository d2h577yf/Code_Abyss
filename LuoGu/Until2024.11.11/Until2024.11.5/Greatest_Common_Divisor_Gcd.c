#include <assert.h>
#include <errno.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  int a, b, gcd = 1;
  scanf("%d %d", &a, &b);

  while (gcd != 0) {
    gcd = a % b;
    a = b;
    b = gcd;
  }

  printf("%d\n", a);

  return EXIT_SUCCESS;
}
