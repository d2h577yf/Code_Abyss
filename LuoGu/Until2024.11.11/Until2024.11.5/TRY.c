#include <assert.h>
#include <errno.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

bool judge_seven(int x) {
  bool result = true;

  while (x != 0) {
    if (x % 10 == 7) {
      result = false;
      break;
    } else {
      x /= 10;
    }
  }

  return result;
}

int Find_the_factor(int x) {
  for (int i = 1; i < x; i++) {
    if (x % i == 0) {
      return i;
    }
  }
}

int main(int argc, char *argv[]) {
  int T;
  scanf("%d", &T);
  bool x = judge_seven(Find_the_factor(T));
  printf("%d\n", x);
  return EXIT_SUCCESS;
}
