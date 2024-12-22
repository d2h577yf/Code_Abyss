#include <stdio.h>

int main(int argc, char *argv[]) {
  int n;
  scanf("%d", &n);

  int x, k, total;
  for (x = 100; x >= 1; x--) {
    for (k = 1; k <= 100; k++) {
      total = 0;
      for (int week = 0; week < 52; week++) {
        for (int day = 0; day < 7; day++) {
          total += x + day * k;
        }
      }
      if (total == n) {
        printf("%d\n", x);
        printf("%d\n", k);
        return 0;
      }
    }
  }

  return 0;
}
