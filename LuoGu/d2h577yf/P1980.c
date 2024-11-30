#include <assert.h>
#include <errno.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  int n, x, cnt = 0;

  scanf("%d %d", &n, &x);

  for (int i = 1; i <= n; i++) {
    int temp = i;

    while (temp != 0) {
      int j = temp % 10;
      if (j == x) {
        cnt++;
      }
      temp /= 10;
    }
  }

  printf("%d\n", cnt);

  return EXIT_SUCCESS;
}
