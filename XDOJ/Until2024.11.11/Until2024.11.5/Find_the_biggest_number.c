#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  int s[4];
  for (int j = 0; j < 4; j++) {
    scanf("%d", &s[j]);
  }

  int r = s[0];
  for (int i = 0; i < 4; i++) {
    if (r < s[i]) {
      r = s[i];
    }
  }
  printf("%d\n", r);
  return 0;
}
