#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
  char input[100];
  int num[2] = {0, 0}, index = 0;
  char op = 0;

  fgets(input, sizeof(input), stdin);

  for (char *p = input; *p; p++) {
    if (*p == '+' || *p == '-' || *p == '*' || *p == '/' || *p == '%') {
      op = *p;
    } else if (isdigit(*p)) {
      num[index] = num[index] * 10 + (*p - '0');
      if (!isdigit(*(p + 1)))
        index++;
    }
  }

  int result = 0;
  switch (op) {
  case '+':
    result = num[0] + num[1];
    break;
  case '-':
    result = num[0] - num[1];
    break;
  case '*':
    result = num[0] * num[1];
    break;
  case '/':
    result = num[0] / num[1];
    break;
  case '%':
    result = num[0] % num[1];
    break;
  }

  printf("%d\n", result);
  return 0;
}
