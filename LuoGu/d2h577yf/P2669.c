#include <assert.h>
#include <errno.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  int k;
  scanf("%d", &k);

  int sum = 0, sum2 = 0, i = 0, count = 0;

  while (sum2 + i < k) {
    sum += i;
    i++;
    sum2 += i;
    count += i * (sum2 - sum);
  }

  count += (i + 1) * (k - sum2);

  printf("%d\n", count);

  return EXIT_SUCCESS;
}
