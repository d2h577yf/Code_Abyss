#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_NUM 500

int main(int argc, char *argv[]) {
  char a[MAX_NUM + 1];
  char b[MAX_NUM + 1];
  char c[MAX_NUM + 3];
  memset(c, 0, sizeof(c));

  scanf("%s", a);
  scanf("%s", b);

  int lena = strlen(a);
  int lenb = strlen(b);

  long int temp = 0;
  int flag = 0;

  for (int i = 0; i < (lena > lenb ? lena : lenb) + 2; i++) {
    int first = (i >= lena) ? 0 : a[lena - 1 - i] - '0';
    int second = (i >= lenb) ? 0 : b[lenb - 1 - i] - '0';

    long int sum = first + second + temp;
    c[i] = (sum % 10) + '0';
    temp = sum / 10;

    if (c[i] != '0') {
      flag = i;
    }
  }

  for (int i = flag; i >= 0; i--) {
    printf("%c", c[i]);
  }
  printf("\n");

  return EXIT_SUCCESS;
}
