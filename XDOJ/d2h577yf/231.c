#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  char sentence[101];
  fgets(sentence, sizeof(sentence), stdin);
  int sum[101] = {0}, maxNum = -1;

  sum[0] = 1;

  for (int i = 1; sentence[i] != '\0'; i++) {
    if (isalpha(sentence[i])) {
      sum[i] = sum[i - 1] + 1;
    }
    if (sum[i] > maxNum) {
      maxNum = sum[i];
    }
  }

  printf("%d", maxNum);

  return EXIT_SUCCESS;
}
