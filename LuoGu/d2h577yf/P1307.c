#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  int number, rebmun = 0;
  scanf("%d", &number);

  while (number != 0) {
    int temp = number % 10;
    number /= 10;
    rebmun = rebmun * 10 + temp;
  }

  printf("%d", rebmun);

  return EXIT_SUCCESS;
}
