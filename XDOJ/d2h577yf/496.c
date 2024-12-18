#include <stdio.h>

int main() {
  int a[15][15], angle, w, h;
  scanf("%d %d", &w, &h);
  for (int i = 1; i <= h; i++) {
    for (int j = 1; j <= w; j++) {
      scanf("%d", &a[i][j]);
    }
  }
  scanf("%d", &angle);

  switch (angle) {
  case 0:
    printf("%d %d\n", w, h);
    for (int i = 1; i <= h; i++) {
      for (int j = 1; j <= w; j++) {
        printf("%d ", a[i][j]);
      }
      printf("\n");
    }
    break;
  case 90:
    printf("%d %d\n", h, w);
    for (int j = 1; j <= w; j++) {
      for (int i = h; i >= 1; i--) {
        printf("%d ", a[i][j]);
      }
      printf("\n");
    }
    break;
  case 180:
    printf("%d %d\n", w, h);
    for (int i = h; i >= 1; i--) {
      for (int j = w; j >= 1; j--) {
        printf("%d ", a[i][j]);
      }
      printf("\n");
    }
    break;
  case 270:
    printf("%d %d\n", h, w);
    for (int j = w; j >= 1; j--) {
      for (int i = 1; i <= h; i++) {
        printf("%d ", a[i][j]);
      }
      printf("\n");
    }
    break;
  default:
    break;
  }

  return 0;
}
