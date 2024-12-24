#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

bool isf(int x) {
  bool result = true;

  if (x == 0 || x == 1) {
    result = false;
  }

  for (int i = 2; i * i <= x; i++) {
    if (x % i == 0) {
      result = false;
      break;
    }
  }
  return result;
}

int main(int argc, char *argv[]) {
  char str[101];
  int aphla[26] = {0}, maxn = -1, minn = 1000;
  scanf("%s", str);
  int len = strlen(str);
  for (int i = 0; i < len; i++) {
    aphla[(int)(str[i] - 'a')]++;
  }

  for (int i = 0; i < 26; i++) {
    if (aphla[i] > maxn) {
      maxn = aphla[i];
    }
    if (aphla[i] < minn && aphla[i] != 0) {
      minn = aphla[i];
    }
  }

  if (isf(maxn - minn)) {
    printf("Lucky Word\n%d", maxn - minn);
  } else {
    printf("No Answer\n0");
  }

  return EXIT_SUCCESS;
}
