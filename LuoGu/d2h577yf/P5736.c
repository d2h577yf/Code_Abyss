#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

bool isPrime(int num) {
  if (num <= 1) {
    return false;
  } else if (num <= 3) {
    return true;
  }
  if (num % 2 == 0 || num % 3 == 0) {
    return false;
  }

  for (int i = 5; i * i <= num; i++) {
    if (num % i == 0 || num % (i + 2) == 0) {
      return false;
    }
  }

  return true;
}

int main(int argc, char *argv[]) {
  int n;
  scanf("%d", &n);
  int arr[n];
  for (int i = 0; i < n; i++) {
    scanf("%d", &arr[i]);
    if (isPrime(arr[i])) {
      printf("%d ", arr[i]);
    }
  }
  return EXIT_SUCCESS;
}
