#include <assert.h>
#include <errno.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  int n, k, sum = 0;
  scanf("%d %d", &n, &k);
  int arr[n], right[n];
  for (int i = 0; i < n; i++) {
    scanf("%d", &arr[i]);
  }

  for (int i = 0; i < n; i++) {
    if (arr[i] == k) {
      right[i] = 1;
    } else {
      right[i] = 0;
    }
  }

  for (int i = 0; i < n; i++) {
    sum += right[i];
  }

  if (sum != 0) {
    for (int i = 0; i < n; i++) {
      if (right[i] == 1) {
        printf("%d ", i);
      }
    }
  } else {
    printf("-1");
  }

  return EXIT_SUCCESS;
}
