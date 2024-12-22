#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  int n, m, minNum;
  scanf("%d %d", &n, &m);
  int hurtLevel[n];
  for (int i = 0; i < n; i++) {
    scanf("%d", &hurtLevel[i]);
  }

  for (int i = 0; i <= n - m; i++) {
    int temp = 0;
    for (int j = i; j < i + m; j++) {
      temp += hurtLevel[j];
    }
    if (i == 0) {
      minNum = temp;
    }
    if (minNum > temp) {
      minNum = temp;
    }
  }

  printf("%d", minNum);

  return EXIT_SUCCESS;
}
