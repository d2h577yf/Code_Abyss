#include <stdio.h>
int main() {
  int n, a[270][270] = {0}, i, j, number = 1, b[1000] = {0}, k, ti, tj,
         flag = 0;
  scanf("%d", &n);
  for (i = 0; i < n; i++) {
    scanf("%d", &a[i][0]);
    a[i][1] = a[i][0] * 8;
    b[i] = a[i][1];
    for (j = 2; j < a[i][1] + 2; j++) {
      a[i][j] = -1;
    }
  }
  for (i = n - 1; i > 0; i--) {
    if (b[i] > b[0]) {
      b[0] = b[i];
    }
  }
  for (j = 2; j < b[0] + 2; j++) {
    for (i = 0; i < n; i++) {
      if (a[i][j] == -1) {
        a[i][j] = number;
        number++;
        if (a[i][j - 1] == number - 2) {
          if (i == n - 1) {
            a[i][j] = number;
            number += 2;
            ti = i;
            tj = j;
            flag = 1;
            break;
          } else {
            a[i][j - 1]++;
            a[i][j] = number + 1;
            number += 3;
            ti = i;
            tj = j;
            flag = 1;
            break;
          }
        }
      }
    }
    if (flag == 1) {
      break;
    }
  }
  for (j = tj + 1; j < b[0] + 2; j++) {
    a[ti][j] = number;
    number += 2;
  }
  for (i = 0; i < n; i++) {
    printf("#%d\n", i + 1);
    k = 2;
    while (k <= a[i][1]) {
      for (j = k; j < k + 8; j++) {
        printf("%d ", a[i][j]);
      }
      printf("\n");
      k += 8;
    }
  }
  return 0;
}
