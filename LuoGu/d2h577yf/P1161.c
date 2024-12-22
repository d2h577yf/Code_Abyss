#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {

  int n;
  scanf("%d", &n);
  int light[2000001] = {0};

  for (int i = 0; i < n; i++) {
    double a;
    int t, Index;
    scanf("%lf %d", &a, &t);
    for (int j = 1; j <= t; j++) {
      Index = a * j;
      if (!light[Index]) {
        light[Index] = 1;
      } else {
        light[Index] = 0;
      }
    }
  }

  for (int i = 0; i < 2000001; i++) {
    if (light[i]) {
      printf("%d", i);
    }
  }

  return EXIT_SUCCESS;
}
