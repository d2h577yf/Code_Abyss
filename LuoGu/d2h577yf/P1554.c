#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  int M, N;
  scanf("%d %d", &M, &N);
  int arr[N - M + 1], cnt[10] = {0};
  for (int i = 0; i < N - M + 1; i++) {
    arr[i] = i + M;
    while (arr[i] != 0) {
      cnt[arr[i] % 10]++;
      arr[i] /= 10;
    }
  }

  for (int i = 0; i < 10; i++) {
    printf("%d ", cnt[i]);
  }

  return EXIT_SUCCESS;
}
