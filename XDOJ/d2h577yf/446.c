
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

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
  int N;
  scanf("%d", &N);

  int M[N];
  int totalMembers[N], cnt = 0;

  for (int i = 0; i < N; i++) {
    scanf("%d", &M[i]);
    totalMembers[i] = M[i] * 8;
    cnt += totalMembers[i];
  }

  int maxIndex = 0;
  int maxMembers = totalMembers[0];
  for (int i = 1; i < N; i++) {
    if (totalMembers[i] > maxMembers) {
      maxMembers = totalMembers[i];
      maxIndex = i;
    }
  }

  int seats[N][maxMembers];

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < maxMembers; j++) {
      seats[i][j] = -1;
    }
    for (int j = 0; j < totalMembers[i]; j++) {
      seats[i][j] = 0;
    }
  }

  int seatNumber = 1;

  for (int i = 0; i < maxMembers; i++) {
    for (int j = 0; j < N; j++) {
      if (seats[j][i] == 0) {
        seats[j][i] = seatNumber;
        seatNumber++;
      }
    }
  }

  quickSort(M, 0, N - 1, 1);

  if (M[N - 1] != M[N - 2]) {

    for (int i = maxMembers - 8, j = 1; i < maxMembers; i++, j++) {
      seats[maxIndex][i] = cnt - 8 + 2 * j;
    }
  }

  for (int i = 0; i < N; i++) {
    printf("#%d\n", i + 1);
    for (int j = 0; j < totalMembers[i]; j++) {
      printf("%d ", seats[i][j]);
      if ((j + 1) % 8 == 0) {
        printf("\n");
      }
    }
  }

  return EXIT_SUCCESS;
}
