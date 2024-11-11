#include <assert.h>
#include <errno.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  int a, b, c;
  scanf("%d %d %d", &a, &b, &c);

  if (a + b > c && a + c > b && b + c > a) {
    if (a * a + b * b == c * c || a * a + c * c == b * b ||
        b * b + c * c == a * a) {
      printf("Right triangle\n");
    }
    if (a * a + b * b > c * c && a * a + c * c > b * b &&
        b * b + c * c > a * a) {
      printf("Acute triangle\n");
    }
    if (a * a + b * b < c * c || a * a + c * c < b * b ||
        b * b + c * c < a * a) {
      printf("Obtuse triangle\n");
    }
    if (a == b || a == c || c == b) {
      printf("Isosceles triangle\n");
    }
    if (a == b && b == c) {
      printf("Equilateral triangle\n");
    }
  } else {
    printf("Not triangle\n");
  }
  return EXIT_SUCCESS;
}
