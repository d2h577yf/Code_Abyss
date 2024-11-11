
#include <assert.h>
#include <errno.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

int find_gdc(int a, int b) {
  int r;
  do {
    r = a % b;
    a = b;
    b = r;

  } while (r != 0);

  return a;
}

void arrange(int arr[], int start, int end) {
  int minIndex = start;

  if (start >= end) {
    return;
  }

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

  arrange(arr, start + 1, end);
}

int main(int argc, char *argv[]) {
  int arr[3], gcd_1, gcd_2;
  for (int i = 0; i < 3; i++) {
    scanf("%d", &arr[i]);
  }

  arrange(arr, 0, 3);
  gcd_1 = find_gdc(arr[0], arr[2]);
  gcd_2 = find_gdc(arr[1], arr[2]);

  if ((double)arr[0] / arr[2] >= (double)arr[1] / arr[2]) {
    printf("%d/%d\n", arr[1] / gcd_2, arr[2] / gcd_2);
  } else {
    printf("%d/%d\n", arr[0] / gcd_1, arr[2] / gcd_1);
  }

  return EXIT_SUCCESS;
}
