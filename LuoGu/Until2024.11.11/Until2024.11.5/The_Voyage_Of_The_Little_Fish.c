#include <assert.h>
#include <errno.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  int x, n;
  long long int length = 0;
  scanf("%d %d", &x, &n);
  for (int i = 0; i < n; i++) {
    if (x <= 5) {
      length += 250;
    } else if (x == 7) {
      x = 0;
    }
    x++;
  }

  printf("%lld\n", length);

  return EXIT_SUCCESS;
}
