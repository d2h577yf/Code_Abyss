#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

bool factori(int n) {
  if (n <= 1) {
    return false;
  } else if (n <= 3) {
    return true;
  }

  if (n % 2 == 0 || n % 3 == 0) {
    return false;
  }

  for (int i = 5; i * i <= n; i += 6) {
    if (n % i == 0 || n % (i + 2) == 0) {
      return false;
    }
  }

  return true;
}

void GC(int n, int *a, int *b) {
  for (int i = 2; i <= n / 2; i++) {
    if (factori(i) && factori(n - i)) {
      *a = i;
      *b = n - i;
      break;
    }
  }
}

int main(int argc, char *argv[]) {
  int N;
  scanf("%d", &N);

  for (int i = 4; i <= N; i++) {
    int a, b;
    if (i % 2 == 0) {
      GC(i, &a, &b);
      printf("%d=%d+%d\n", i, a, b);
    }
  }

  return EXIT_SUCCESS;
}
