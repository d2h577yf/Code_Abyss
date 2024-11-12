#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int judge_type(char arr[], int length) {
  int num[4] = {0};
  int sum = 0;

  for (int i = 0; i < length; i++) {
    if (isupper(arr[i])) {
      num[0] = 1;
    } else if (islower(arr[i])) {
      num[1] = 1;
    } else if (isdigit(arr[i])) {
      num[2] = 1;
    } else {
      num[3] = 1;
    }
  }

  for (int i = 0; i < 4; i++) {
    sum += num[i];
  }

  switch (sum) {
  case 2:
    return 1;
  case 3:
    return 2;
  case 4:
    return 3;
  default:
    return 0;
  }
}

int main() {
  char password[50] = {0};
  int cnt = 0;

  if (scanf("%49s", password) == EOF) {
    printf("0\n");
    return EXIT_SUCCESS;
  }

  int length = strlen(password);

  cnt = (length > 0) ? 1 : 0;

  if (length > 8) {
    cnt++;
  }

  cnt += judge_type(password, length);

  if (cnt > 5) {
    cnt = 5;
  }

  printf("%d\n", cnt);

  return EXIT_SUCCESS;
}
