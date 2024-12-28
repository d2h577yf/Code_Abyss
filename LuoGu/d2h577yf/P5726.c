#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  int n, flagMax = -1, flagMin = 11;
  scanf("%d", &n);
  int arr[n], sum = 0;
  double score;

  for (int i = 0; i < n; i++) {
    scanf("%d", &arr[i]);
    if (arr[i] > flagMax) {
      flagMax = arr[i];
    }
    if (arr[i] < flagMin) {
      flagMin = arr[i];
    }
    sum += arr[i];
  }

  score = (sum - flagMax - flagMin) / ((n - 2) * 1.0);

  printf("%.2f", score);

  return EXIT_SUCCESS;
}
