#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct {
  int state;
  char name[11];
} people;

int main(int argc, char *argv[]) {
  int n, m;
  scanf("%d %d", &n, &m);
  people peo[n];
  for (int i = 0; i < n; i++) {
    scanf("%d %s", &peo[i].state, peo[i].name);
    if (peo[i].state == 0) {
      peo[i].state = -1;
    }
  }

  int instruction[m][2];
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < 2; j++) {
      scanf("%d", &instruction[i][j]);
    }
    if (instruction[i][0] == 0) {
      instruction[i][0] = -1;
    }
  }

  int flag = 0;

  for (int i = 0; i < m; i++) {
    int dirction = -1 * instruction[i][0] * peo[flag].state;
    flag += dirction * instruction[i][1];
    if (flag >= n) {
      flag = flag % n;
    } else if (flag < 0) {
      flag = (flag % n + n) % n;
    }
  }
  printf("%s", peo[flag].name);

  return EXIT_SUCCESS;
}
