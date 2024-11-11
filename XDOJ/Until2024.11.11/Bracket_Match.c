#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void remove_others(char arr[]) {
  int i = 0, j = 0;
  while (i < strlen(arr)) {
    if (arr[i] == '(' || arr[i] == ')' || arr[i] == '[' || arr[i] == ']' ||
        arr[i] == '{' || arr[i] == '}') {
      arr[j] = arr[i];
      j++;
    }
    i++;
  }
  arr[j] = '\0';
}

int main() {
  char arr[50] = {0};
  scanf("%s", arr);

  remove_others(arr);

  int length = strlen(arr);
  if (length % 2 != 0) {
    printf("no\n");
    return EXIT_SUCCESS;
  }

  int left[length];
  int right[length];
  memset(left, 0, sizeof(left));
  memset(right, 0, sizeof(right));

  for (int i = 0; i < length; i++) {
    if (arr[i] == '(') {
      left[i] = 1;
    } else if (arr[i] == '[') {
      left[i] = 2;
    } else if (arr[i] == '{') {
      left[i] = 3;
    } else if (arr[i] == ')') {
      right[i] = 1;
    } else if (arr[i] == ']') {
      right[i] = 2;
    } else if (arr[i] == '}') {
      right[i] = 3;
    }
  }

  int judge = 0;

  for (int i = length - 1; i >= 0; i--) {
    if (left[i] == 0) {
      continue;
    } else {
      int matched = 0;
      for (int j = i + 1; j < length; j++) {
        if (left[i] == right[j]) {
          right[j] = 0;
          matched = 1;
          break;
        } else if (right[j] != 0 && left[i] != right[j]) {
          judge = 1;
          printf("no\n");
          return EXIT_SUCCESS;
        }
      }
      if (!matched) {
        judge = 1;
        printf("no\n");
        return EXIT_SUCCESS;
      }
    }
  }

  if (judge == 0) {
    printf("yes\n");
  }

  return EXIT_SUCCESS;
}
