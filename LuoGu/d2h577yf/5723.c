#include <assert.h>
#include <errno.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

bool isPrimer(int n) {
  bool result = true;
  for (int i = 2; i * i <= n; i++) {
    if (n % i == 0) {
      result = false;
    }
  }
  return result;
}

int main(int argc, char *argv[]) {
  int L, sum = 0, cnt = 0;
  scanf("%d", &L);

  for (int i = 2; sum + i <= L; i++) {
    if (isPrimer(i)) {
      sum += i;
      cnt++;
      printf("%d\n", i);
    }
  }

  printf("%d", cnt);

  return EXIT_SUCCESS;
}
