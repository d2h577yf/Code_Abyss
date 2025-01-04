#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

int peach(int n) {
  if (n <= 1) {
    return 1;
  }
  int result = (peach(n - 1) + 1) * 2;
  return result;
}

int main(int argc, char *argv[]) {
  int n;
  scanf("%d", &n);
  printf("%d", peach(n));
  return EXIT_SUCCESS;
}
