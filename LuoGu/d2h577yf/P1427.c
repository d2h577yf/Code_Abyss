#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  int arr[101] = {1, 1, 1}, n = 0;
  for (int i = 1; i < 101; i++) {
    scanf("%d", &arr[i]);
    if (arr[i] == 0)
      break;
    n++;
  }

  for (int i = n; i > 0; i--) {
    printf("%d ", arr[i]);
  }

  return 0;
}
