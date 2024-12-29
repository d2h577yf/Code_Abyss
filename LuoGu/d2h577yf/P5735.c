#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  double arr[3][2], temp = 0, result = 0;
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 2; j++) {
      scanf("%lf", &arr[i][j]);
    }
  }

  for (int i = 0; i < 2; i++) {
    for (int j = i + 1; j < 3; j++) {
      temp = 0;
      for (int k = 0; k < 2; k++) {
        temp += (arr[i][k] - arr[j][k]) * (arr[i][k] - arr[j][k]);
      }
      result += sqrt(temp);
    }
  }

  printf("%.2f", result);

  return EXIT_SUCCESS;
}
