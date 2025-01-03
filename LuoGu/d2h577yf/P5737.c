#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  int x, y, cnt = 0;
  scanf("%d %d", &x, &y);
  int arr[(y - x) / 4];
  for (int i = x; i <= y; i++) {
    if (i % 4 == 0 && i % 100 != 0 || i % 400 == 0) {
      arr[cnt] = i;
      cnt++;
    }
  }

  printf("%d\n", cnt);

  for (int i = 0; i < cnt; i++) {
    printf("%d ", arr[i]);
  }

  return EXIT_SUCCESS;
}
