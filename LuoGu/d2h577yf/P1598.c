#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NUMBER_OF_LETTERS 26

int main(int argc, char *argv[]) {
  int count[NUMBER_OF_LETTERS] = {0}, max = 0;
  char temp;
  while (scanf("%c", &temp) != EOF) {
    temp = toupper(temp);
    if (isalpha(temp)) {
      count[temp - 'A']++;
      if (count[temp - 'A'] > max) {
        max = count[temp - 'A'];
      }
    }
  }

  char arr[max + 1][NUMBER_OF_LETTERS];

  for (int i = 0; i < NUMBER_OF_LETTERS; i++) {
    arr[max][i] = 'A' + i;
    for (int j = max - 1; j >= 0; j--) {
      if (count[i] > 0) {
        arr[j][i] = '*';
        count[i]--;
      } else {
        arr[j][i] = ' ';
      }
    }
  }

  for (int i = 0; i < max + 1; i++) {
    for (int j = 0; j < NUMBER_OF_LETTERS; j++) {
      printf("%c ", arr[i][j]);
    }
    printf("\n");
  }

  return EXIT_SUCCESS;
}
