#include <assert.h>
#include <errno.h>
#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

bool contains_seven(int num) {
  while (num != 0) {
    if (num % 10 == 7) {
      return true;
    }
    num /= 10;
  }
  return false;
}

bool judge_seven(int a) {
  if (contains_seven(a)) {
    return false;
  }

  int limit = (int)sqrt(a);
  for (int i = 1; i <= limit; i++) {
    if (a % i == 0) {
      if (contains_seven(i) || contains_seven(a / i)) { // 检查因数对
        return false;
      }
    }
  }

  return true;
}

int main(int argc, char *argv[]) {
  int T;
  scanf("%d", &T);
  int arr[T], att[T];
  for (int i = 0; i < T; i++) {
    scanf("%d", &arr[i]);
  }

  for (int i = 0; i < T; i++) {
    if (!judge_seven(arr[i])) {
      att[i] = -1;
    } else {
      int j = arr[i] + 1;
      while (!judge_seven(j)) { // 找到第一个符合条件的j
        j++;
      }
      att[i] = j;
    }
  }

  for (int j = 0; j < T; j++) {
    printf("%d\n", att[j]);
  }

  return EXIT_SUCCESS;
}
