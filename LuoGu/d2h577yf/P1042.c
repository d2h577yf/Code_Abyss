#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

const int MAX_LETTER = 62501;

void show_result(char arr[], int n) {
  int a = 0, b = 0;
  for (int i = 0; arr[i - 1] != 'E' && i < MAX_LETTER + 1; i++) {
    if (arr[i] == 'W') {
      a++;
    } else if (arr[i] == 'L') {
      b++;
    } else if (arr[i] == 'E') {
      printf("%d:%d\n", a, b);
    }
    if (abs(a - b) >= 2 && (a >= n || b >= n)) {
      printf("%d:%d\n", a, b);
      a = 0;
      b = 0;
    }
  }
}

int main(int argc, char *argv[]) {
  char arr[MAX_LETTER + 1];

  for (int i = 0; arr[i - 1] != 'E' && i < MAX_LETTER; i++) {
    scanf("%c", &arr[i]);
    if (arr[i] == '\n') {
      i -= 1;
    }
  }
  show_result(arr, 11);
  printf("\n");
  show_result(arr, 21);
  return EXIT_SUCCESS;
}
