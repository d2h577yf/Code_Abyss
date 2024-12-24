#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
  int n;
  char Password[51];
  scanf("%d %s", &n, Password);
  int len = strlen(Password);

  for (int i = 0; i < len; i++) {
    int temp = ((int)Password[i] + n) % 123;
    if (temp < 97) {
      temp += 97;
    }
    Password[i] = (char)temp;
    printf("%c", Password[i]);
  }

  return EXIT_SUCCESS;
}
