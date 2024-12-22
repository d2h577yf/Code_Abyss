
#include <stdio.h>
#include <stdlib.h>

int a[110];
int n;
int num = 0;
int v[110];

int main() {
  scanf("%d", &n);

  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
  }

  int sum_counts[200010] = {0};
  for (int i = 1; i <= n; i++) {
    sum_counts[a[i]]++;
  }

  for (int i = 1; i < n; i++) {
    for (int j = i + 1; j <= n; j++) {
      int target = a[i] + a[j];
      if (sum_counts[target] > 0) {
        for (int k = 1; k <= n; k++) {
          if (k != i && k != j && a[k] == target && v[k] == 0) {
            num++;
            v[k] = 1;
            break;
          }
        }
      }
    }
  }

  printf("%d", num);
  return 0;
}
