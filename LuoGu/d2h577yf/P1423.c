#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  double target, strengh = 2.0, sum = 0;
  int step = 0;
  scanf("%lf", &target);

  while (sum <= target) {
    sum += strengh;
    strengh *= 0.98;
    step++;
  }

  printf("%d", step);

  return EXIT_SUCCESS;
}
