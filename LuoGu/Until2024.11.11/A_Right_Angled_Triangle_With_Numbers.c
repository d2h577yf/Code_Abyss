#include <assert.h>
#include <errno.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  int n, cnt = 1;
  scanf("%d", &n);

  for (int i = 1; i <= n; i++) {
    for (int x = 1; x <= n + 1 - i; x++) {
      printf("%02d", cnt);
      cnt++;
    }
    printf("\n");
  }

  return EXIT_SUCCESS;
}
