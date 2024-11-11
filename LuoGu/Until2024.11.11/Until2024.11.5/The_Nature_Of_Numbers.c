#include <assert.h>
#include <errno.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  bool result1 = false;
  bool result2 = false;
  int a = 0, b = 0, c = 0, d = 0;
  int x;
  scanf("%d", &x);

  if (x % 2 == 0) {
    result1 = true;
  }

  if (x > 4 && x <= 12) {
    result2 = true;
  }

  if (result1 && result2) {
    a = 1;
  }
  if (result1 || result2) {
    b = 1;
  }
  if ((result1 && !result2) || (!result1 && result2)) {
    c = 1;
  }
  if (!result1 && !result2) {
    d = 1;
  }

  printf("%d %d %d %d", a, b, c, d);

  return EXIT_SUCCESS;
}
