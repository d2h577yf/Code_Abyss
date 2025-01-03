#include <stdio.h>

int main(int argc, char const *argv[]) {
  int n, m;
  scanf("%d %d", &n, &m);
  int Student[n][m];
  double score[n];
  int flag = 0;

  for (int i = 0; i < n; i++) {
    int max = -1, min = 11;
    score[i] = 0;
    for (int j = 0; j < m; j++) {
      scanf("%d", &Student[i][j]);
      if (Student[i][j] > max) {
        max = Student[i][j];
      }
      if (Student[i][j] < min) {
        min = Student[i][j];
      }
      score[i] += Student[i][j];
    }
    score[i] -= (max + min);
    score[i] /= (1.0 * (m - 2));
    if (score[flag] < score[i]) {
      flag = i;
    }
  }

  printf("%.2f", score[flag]);
  return 0;
}
