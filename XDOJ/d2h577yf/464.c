#include <stdio.h>
void printFactorial(int n);
int main() {
  int n;
  scanf("%d", &n);
  printFactorial(n);
  return 0;
}

void printFactorial(int n) {
  if (n < 0 || n > 1000) {
    printf("Invalid input");
    return;
  } else if (n == 0) {
    printf("1");
    return;
  }

  int arr[5176];
  for (int i = 0; i < 5176; i++) {
    arr[i] = 0;
  }
  arr[0] = 1;

  for (int i = 1; i <= n; i++) {
    for (int j = 0; j < 5176; j++) {
      arr[j] *= i;
    }

    for (int k = 0; k < 5176; k++) {
      if (arr[k] >= 10) {
        int carry = arr[k] / 10;
        arr[k] %= 10;
        if (k + 1 < 5176) {
          arr[k + 1] += carry;
        }
      }
    }
  }

  int start = 5175;
  while (arr[start] == 0) {
    start--;
  }

  for (int i = start; i >= 0; i--) {
    printf("%d", arr[i]);
  }
}
