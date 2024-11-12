#include <ctype.h>
#include <stdio.h>
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

int main() {
  char str[100] = {0};
  int num[100] = {0};
  scanf("%s", str);
  memset(num, -1, sizeof(num));

  int length = strlen(str);

  int sum[100] = {0};

  for (int i = 0; i < length; i++) {
    if (isdigit(str[i])) {
      num[i] = (int)(str[i] - '0');
    }
  }

  int start = -1;
  int j = 0;
  for (int i = 0; i < length; i++) {
    if (num[i] != -1) {
      if (start == -1) {
        start = i;
      }
    } else {
      if (start != -1) {
        int number = 0;
        for (int k = start; k < i; k++) {
          number = number * 10 + num[k];
        }
        sum[j++] = number;
        start = -1;
      }
    }
  }

  if (start != -1) {
    int number = 0;
    for (int k = start; k < length; k++) {
      number = number * 10 + num[k];
    }
    sum[j++] = number;
  }

  quickSort(sum, 0, j - 1, 0);

  for (int i = 0; i < j; i++) {
    printf("%d ", sum[i]);
  }

  return 0;
}
