#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  int s1, s2, s3;
  scanf("%d %d %d", &s1, &s2, &s3);
  int arr[81] = {0}, maxNum = -1, maxIndex;
  for (int i = 1; i <= s1; i++) {
    for (int j = 1; j <= s2; j++) {
      for (int k = 1; k <= s3; k++) {
        int temp = i + j + k;
        arr[temp]++;
      }
    }
  }

  for (int i = 3; i <= s1 + s2 + s3; i++) {
    if (arr[i] > maxNum) {
      maxNum = arr[i];
      maxIndex = i;
    }
  }

  printf("%d", maxIndex);

  return EXIT_SUCCESS;
}
