#include <math.h>
#include <stdio.h>

int isprime(int n) {
  for (int i = 2, I = sqrt(n); i <= I; i++) {
    if (n % i)
      continue;
    return 0;
  }
  return 1;
}

int main() {
  int n, min = 0, max = 0;
  scanf("%d", &n);
  for (int i = 2; i <= n; i++) {
    if (isprime(i) && isprime(n - i)) {
      min = i;
      max = n - i;
      break;
    }
  }

  printf("%d %d\n", min, max);
}
