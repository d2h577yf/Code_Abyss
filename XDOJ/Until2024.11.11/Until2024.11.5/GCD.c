#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  int a, b, r, m, n;
  scanf("%d %d", &a, &b);

  if (a != 0 && b != 0) {
    while (r != 0) {
      r = a % b;
      a = b;
      b = r;
    }

    printf("%d\n", a);
  } else {
    printf("%d\n", a == 0 ? b : a);
  }
  return EXIT_SUCCESS;
}
