#include <assert.h>
#include <errno.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

void sort(int arr[], int start, int end) {
  if (start >= end) {
    return;
  }

  int maxIndex = start;
  for (int i = start; i < end; i++) {
    if (arr[maxIndex] < arr[i]) {
      maxIndex = i;
    }
  }

  if (maxIndex != start) {
    int temp = arr[start];
    arr[start] = arr[maxIndex];
    arr[maxIndex] = temp;
  }

  sort(arr, start + 1, end);
}

int main(int argc, char *argv[]) {
  int n;
  scanf("%d", &n);
  int arr[n];

  for (int i = 0; i < n; i++) {
    scanf("%d", &arr[i]);
  }

  int start = 0;
  int end = n - 1;

  while (start < end) {
    while (arr[start] % 2 == 0 && start < end) {
      start++;
    }

    while (arr[end] % 2 != 0 && start < end) {
      end--;
    }

    if (start < end) {
      int temp = arr[start];
      arr[start] = arr[end];
      arr[end] = temp;
    }
  }

  if (start != 0 && start != n - 1) {
    sort(arr, 0, end);
    sort(arr, end, n);
  } else {
    sort(arr, 0, n);
  }
  for (int i = 0; i < n - 1; i++) {
    printf("%d ", arr[i]);
  }
  printf("%d", arr[n - 1]);

  return EXIT_SUCCESS;
}
