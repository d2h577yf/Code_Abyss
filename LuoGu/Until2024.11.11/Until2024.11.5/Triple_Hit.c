#include <assert.h>
#include <errno.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

bool check_unique_digits(int a, int b, int c) {
  int digits[10] = {0};

  for (int i = 0; i < 3; i++) {
    digits[a % 10]++;
    digits[b % 10]++;
    digits[c % 10]++;
    a /= 10;
    b /= 10;
    c /= 10;
  }

  for (int i = 1; i < 10; i++) {
    if (digits[i] > 1)
      return false;
  }
  return digits[0] == 0;
}

int main(int argc, char *argv[]) {
  double A, B, C;
  int i, j, k;
  bool found = false;

  scanf("%lf %lf %lf", &A, &B, &C);

  for (i = 123; i <= 333; i++) {
    j = i * B / A;
    k = i * C / A;

    if (j >= 100 && j < 1000 && k >= 100 && k < 1000 &&
        check_unique_digits(i, j, k)) {
      printf("%d %d %d\n", i, j, k);
      found = true;
    }
  }

  if (!found) {
    printf("No!!!\n");
  }

  return EXIT_SUCCESS;
}
