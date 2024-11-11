#include <stdio.h>

int height[20], H, s;

int main() {
  for (int i = 0; i < 10; i++) {
    scanf("%d", &height[i]);
  }
  scanf("%d", &H);
  H += 30;
  for (int i = 0; i < 10; i++) {
    s += !(H < height[i]);
  }
  printf("%d\n", s);
  return 0;
}
