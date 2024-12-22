
#include <stdio.h>

double Fibonacci(int n) {
  double f[50];
  f[0] = 0;
  f[1] = 1;
  f[2] = 1;

  for (int i = 3; i <= n; i++) {
    f[i] = f[i - 1] + f[i - 2];
  }

  return f[n];
}

int main() {
  int n;
  scanf("%d", &n);

  printf("%.2lf\n", Fibonacci(n));
  return 0;
}
