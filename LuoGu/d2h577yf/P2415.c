#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  int s[30] = {0};
  int maxIndex = 0;
  long long int count = 1;

  for (int i = 0; i < 30 && scanf("%d", &s[i]) != EOF; i++) {
    maxIndex++;
    count *= 2;
  }

  long long int sum = 0;
  for (int i = 0; i < maxIndex; i++) {
    sum += (s[i] * (count / 2));
  }

  printf("%lld\n", sum);

  return EXIT_SUCCESS;
}
