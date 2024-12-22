#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  int n, maxNum = 1;
  scanf("%d", &n);
  int arr[n], cnt[n];
  for (int i = 0; i < n; i++) {
    scanf("%d", &arr[i]);
    cnt[i] = 1;
  }

  for (int i = 1; i < n; i++) {
    if (arr[i] == arr[i - 1] + 1) {
      cnt[i] = cnt[i - 1] + 1;
    }
    if (cnt[i] > maxNum) {
      maxNum = cnt[i];
    }
  }

  printf("%d", maxNum);

  return EXIT_SUCCESS;
}
