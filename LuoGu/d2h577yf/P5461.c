#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

void loop_relieve(int **arr, int beginX, int beginY, int n) {
  if (n <= 1) {
    return;
  }
  n /= 2;

  for (int i = beginX; i < beginX + n; i++) {
    for (int j = beginY; j < beginY + n; j++) {
      arr[i][j] = 0;
    }
  }

  loop_relieve(arr, beginX + n, beginY, n);
  loop_relieve(arr, beginX, beginY + n, n);
  loop_relieve(arr, beginX + n, beginY + n, n);
}

int main() {
  int n, count = 1;
  scanf("%d", &n);

  for (int i = 1; i <= n; i++) {
    count *= 2;
  }

  int **arr = malloc(count * sizeof(int *));
  for (int i = 0; i < count; i++) {
    arr[i] = malloc(count * sizeof(int));
  }

  for (int i = 0; i < count; i++) {
    for (int j = 0; j < count; j++) {
      arr[i][j] = 1;
    }
  }

  loop_relieve(arr, 0, 0, count);

  for (int i = 0; i < count; i++) {
    for (int j = 0; j < count - 1; j++) {
      printf("%d ", arr[i][j]);
    }
    printf("%d\n", arr[i][count - 1]);
  }

  for (int i = 0; i < count; i++) {
    free(arr[i]);
  }
  free(arr);

  return EXIT_SUCCESS;
}
