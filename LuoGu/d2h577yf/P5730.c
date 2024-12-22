#include <stdio.h>

char c[10][5][4] = {"XXX", "X.X", "X.X", "X.X", "XXX",
                    "..X", // 1
                    "..X", "..X", "..X", "..X",
                    "XXX", // 2
                    "..X", "XXX", "X..", "XXX",
                    "XXX", // 3
                    "..X", "XXX", "..X", "XXX",
                    "X.X", // 4
                    "X.X", "XXX", "..X", "..X",
                    "XXX", // 5
                    "X..", "XXX", "..X", "XXX",
                    "XXX", // 6
                    "X..", "XXX", "X.X", "XXX",
                    "XXX", // 7
                    "..X", "..X", "..X", "..X",
                    "XXX", // 8
                    "X.X", "XXX", "X.X", "XXX",
                    "XXX", // 9
                    "X.X", "XXX", "..X", "XXX"};

char ans[10][1000];

int main() {
  int n, a, s = 0;
  scanf("%d", &n);
  while (n--) {
    scanf("%1d", &a);
    for (int i = 0; i < 5; i++)
      for (int j = 0; j < 3; j++)
        ans[i][s + j] = c[a][i][j];
    for (int i = 0; i < 5; i++)
      ans[i][s + 3] = '.';
    s += 4;
  }

  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < s - 1; j++)
      printf("%c", ans[i][j]);
    printf("\n");
  }

  return 0;
}
