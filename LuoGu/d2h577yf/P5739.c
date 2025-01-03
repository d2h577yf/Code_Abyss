#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
long long int loop(int n) {
  if (n < 1) {
    return 1;
  }

  long long int result = n * loop(n - 1);

  return result;
}

int main(int argc, char *argv[]) {
  int n;
  scanf("%d", &n);
  printf("%lld", loop(n));

  return EXIT_SUCCESS;
}
