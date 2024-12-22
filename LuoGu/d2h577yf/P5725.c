#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  int n;
  scanf("%d", &n);

  int num1 = 1, num2 = 1, flag = 1;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      printf("%02d", num1);
      num1++;
    }
    printf("\n");
  }
  printf("\n");

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (j < n - flag) {
        printf("  ");
      } else {
        printf("%02d", num2);
        num2++;
      }
    }
    printf("\n");
    flag++;
  }

  return EXIT_SUCCESS;
}
