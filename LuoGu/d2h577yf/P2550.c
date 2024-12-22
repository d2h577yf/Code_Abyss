#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  int n, target[7], award[7] = {0};
  scanf("%d", &n);
  for (int i = 0; i < 7; i++) {
    scanf("%d", &target[i]);
  }
  int arr[n][7];
  for (int i = 0; i < n; i++) {
    int cnt = 0;
    for (int j = 0; j < 7; j++) {
      scanf("%d", &arr[i][j]);
      for (int k = 0; k < 7; k++) {
        if (arr[i][j] == target[k]) {
          cnt++;
        }
      }
    }
    switch (cnt - 1) {
    case 0:
      award[0]++;
      break;
    case 1:
      award[1]++;
      break;
    case 2:
      award[2]++;
      break;
    case 3:
      award[3]++;
      break;
    case 4:
      award[4]++;
      break;
    case 5:
      award[5]++;
      break;
    case 6:
      award[6]++;
      break;
    }
  }

  for (int i = 6; i >= 0; i--) {
    printf("%d ", award[i]);
  }

  return EXIT_SUCCESS;
}
