
#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_NUM 99999999
int minWay(int arr[], int target, int m) {

  if (target == 0) {
    return arr[target];
  }

  int up = minWay(arr, target - m, m);
  int left = minWay(arr, target - 1, m);

  int result = arr[target] + (up < left ? up : left);
  return result;
}

int main(int argc, char *argv[]) {
  char arr[300000];
  fgets(arr, sizeof(arr), stdin);
  int num[250000], m = 0, sum = 0, n, flag = 1;

  for (int i = 2; i < strlen(arr); i++) {
    if (isdigit(arr[i])) {
      num[sum] = arr[i] - '0';
      sum++;
      if (flag == 1) {
        m++;
      }
    } else if (arr[i] == ']') {
      flag = 0;
    }
  }

  printf("%d", minWay(num, sum - 1, m));

  return EXIT_SUCCESS;
}
