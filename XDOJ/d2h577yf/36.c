#include <assert.h>
#include <errno.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int compare(int a, int b, int ascending) {
  return ascending ? (a - b) : (b - a);
}

void quickSort(int arr[], int low, int high, int ascending) {
  if (low < high) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
      if (compare(arr[j], pivot, ascending) <= 0) {
        i++;
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
      }
    }

    int temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;

    int pi = i + 1;

    quickSort(arr, low, pi - 1, ascending);
    quickSort(arr, pi + 1, high, ascending);
  }
}

int main(int argc, char *argv[]) {
  int m;
  scanf("%d", &m);

  int arr[m][m];
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < m; j++) {
      scanf("%d", &arr[i][j]);
    }
  }

  int sum[2 * m + 2];

  memset(sum, 0, sizeof(sum));

  for (int i = 0; i < m; i++) {
    for (int j = 0; j < m; j++) {
      sum[i] += arr[i][j];
      sum[i + m] += arr[j][i];
    }
  }

  for (int i = 0, j = 0; i < m; i++, j++) {
    sum[2 * m] += arr[i][j];
    sum[2 * m + 1] += arr[i][m - j - 1];
  }

  quickSort(sum, 0, 2 * m + 1, 0);

  for (int i = 0; i < 2 * m + 2; i++) {
    printf("%d ", sum[i]);
  }

  return EXIT_SUCCESS;
}
