#include <assert.h>
#include <errno.h>
#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

bool isPrime(int x) {
  if (x < 2)
    return false;
  for (int i = 2; i <= sqrt(x); i++) {
    if (x % i == 0) {
      return false;
    }
  }
  return true;
}

int main(int argc, char *argv[]) {
  int n, minPrime = 0, maxPrime = 0;
  scanf("%d", &n);

  for (int i = 1; i <= sqrt(n); i++) {
    if (n % i == 0 && isPrime(i) && isPrime(n / i)) {
      minPrime = i;
      break;
    }
  }

  if (minPrime != 0) {
    maxPrime = n / minPrime;
    printf("%d\n", maxPrime);
  }
  return EXIT_SUCCESS;
}
