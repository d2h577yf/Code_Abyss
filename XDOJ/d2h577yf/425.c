
#include <stdio.h>
#include <stdlib.h>

int arr[51] = {0};

int wayCount(int N) {
  arr[0] = 1;

  for (int i = 1; i <= N; i++) {
    if (i - 1 >= 0) {
      arr[i] += arr[i - 1];
    }
    if (i - 3 >= 0) {
      arr[i] += arr[i - 3];
    }
  }

  return arr[N];
}

int main(int argc, char *argv[]) {
  int N;
  scanf("%d", &N);

  int way = wayCount(N);
  printf("%d", way);
  return EXIT_SUCCESS;
}
