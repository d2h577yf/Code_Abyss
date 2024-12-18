#include <assert.h>
#include <errno.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct {
  char name[13];
  int win;
  int score;
} Student;

int main(int argc, char *argv[]) {
  int n;
  scanf("%d", &n);
  Student stu[n];

  for (int i = 0; i < n; i++) {
    stu[i].win = 0;
    stu[i].score = 0;
  }

  for (int i = 0; i < n; i++) {
    scanf("%s", stu[i].name);
  }

  int result[n][n];
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      scanf("%d", &result[i][j]);
      switch (result[i][j]) {
      case 5:
        stu[i].win += 1;
        stu[i].score += 2;
        break;
      case 4:
        stu[i].win += 1;
        stu[i].score += 3;
        break;
      case 3:
        stu[i].win += 1;
        stu[i].score += 3;
        break;
      case -5:
        stu[i].win += 0;
        stu[i].score += 1;
        break;
      case -4:
        stu[i].win += 0;
        stu[i].score += 0;
        break;
      case -3:
        stu[i].win += 0;
        stu[i].score += 0;
        break;
      default:
        stu[i].win += 0;
        stu[i].score += 0;
      }
    }
  }

  for (int i = 1; i < n; i++) {
    for (int j = 0; j < n - i; j++) {
      if (stu[j].win < stu[j + 1].win) {
        Student temp = stu[j];
        stu[j] = stu[j + 1];
        stu[j + 1] = temp;
      } else if (stu[j].win == stu[j + 1].win) {
        if (stu[j].score < stu[j + 1].score) {
          Student temp = stu[j];
          stu[j] = stu[j + 1];
          stu[j + 1] = temp;
        } else if (stu[j].score == stu[j + 1].score) {
          if (stu[j].name[0] > stu[j + 1].name[0]) {
            Student temp = stu[j];
            stu[j] = stu[j + 1];
            stu[j + 1] = temp;
          }
        }
      }
    }
  }

  for (int i = 0; i < n; i++) {
    printf("%s %d %d\n", stu[i].name, stu[i].win, stu[i].score);
  }

  return EXIT_SUCCESS;
}
