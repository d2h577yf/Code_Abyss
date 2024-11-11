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

  int minIndex = start;
  for (int i = start; i < end; i++) {
    if (arr[minIndex] > arr[i]) {
      minIndex = i;
    }
  }

  if (minIndex != start) {
    int temp = arr[start];
    arr[start] = arr[minIndex];
    arr[minIndex] = temp;
  }

  sort(arr, start + 1, end);
}

int main(int argc, char *argv[]) {
  int n;
  scanf("%d", &n);
  int arr[n], delta[n - 1];
  for (int i = 0; i < n; i++) {
    scanf("%d", &arr[i]);
  }

  sort(arr, 0, n);

  for (int i = 0; i < n - 1; i++) {
    delta[i] = arr[i + 1] - arr[i];
  }

  sort(delta, 0, n - 1);

  printf("%d\n", delta[0]);

  return EXIT_SUCCESS;
}
