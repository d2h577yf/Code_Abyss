#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  int a, b;
  long long int squ = 1;
  scanf("%d %d", &a, &b);

  for (int i = 0; i < b; i++) {
    squ *= a;
    if (squ > 1E9) {
      squ = -1;
      break;
    }
  }

  printf("%lld\n", squ);

  return EXIT_SUCCESS;
}
