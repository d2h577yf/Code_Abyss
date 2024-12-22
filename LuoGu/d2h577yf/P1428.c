#include <stdio.h>
#include <stdlib.h>

int main() {
  int n;
  scanf("%d", &n);
  int a[n], result[n];

  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
    result[i] = 0;
  }

  for (int i = 1; i < n; i++) {
    for (int j = 0; j < i; j++) {
      if (a[j] < a[i]) {
        result[i]++;
      }
    }
  }

  for (int i = 0; i < n; i++) {
    printf("%d ", result[i]);
  }

  return 0;
}
