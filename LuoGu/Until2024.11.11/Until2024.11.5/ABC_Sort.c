#include <assert.h>
#include <errno.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

void arrange(int arr[], int start, int end) {
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

  arrange(arr, start + 1, end);
}

int main(int argc, char *argv[]) {
  int num[3], letter[3];
  char x;
  for (int i = 0; i < 3; i++) {
    scanf("%d", &num[i]);
  }
  arrange(num, 0, 3);

  for (int i = 0; i < 3; i++) {
    scanf(" %c", &x);
    if (x == 'A') {
      letter[i] = 0;
    } else if (x == 'B') {
      letter[i] = 1;
    } else {
      letter[i] = 2;
    }
  }

  printf("%d %d %d\n", num[letter[0]], num[letter[1]], num[letter[2]]);
  return EXIT_SUCCESS;
}
