#include <assert.h>
#include <errno.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  int n;
  scanf("%d", &n);
  int cnt = 0;
  for (int i = 1; i <= n; i++) {
    cnt += i;
  }

  printf("%d\n", cnt);
  return EXIT_SUCCESS;
}
