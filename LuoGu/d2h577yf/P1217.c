#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

#define MAX_LIMIT 10000000

bool book[MAX_LIMIT + 1];

void prime(int b) {
  memset(book, true, sizeof(book));
  book[0] = book[1] = false;

  int n = sqrt(b);
  for (int i = 2; i <= n; i++) {
    if (book[i]) {
      for (int j = i * i; j <= b; j += i) {
        book[j] = false;
      }
    }
  }
}

bool isHWS(int num) {
  int temp = num, ans = 0;
  while (temp != 0) {
    ans = ans * 10 + temp % 10;
    temp /= 10;
  }
  return ans == num;
}

int main() {
  int a, b;
  scanf("%d %d", &a, &b);

  if (b > MAX_LIMIT) {
    b = MAX_LIMIT;
  }

  prime(b);

  if (a > b) {
    return 0;
  }

  if (a % 2 == 0)
    a++;

  for (int i = a; i <= b; i += 2) {
    if (book[i] && isHWS(i)) {
      printf("%d\n", i);
    }
  }

  return 0;
}
