#include <assert.h>
#include <errno.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct {
  char name[21];
  int score;
} Student;

int main(int argc, char *argv[]) {
  int n, num1 = 0, num2 = 0, num3 = 0;
  scanf("%d", &n);
  Student stu[n];
  for (int i = 0; i < n; i++) {
    scanf("%s %d", stu[i].name, &stu[i].score);
  }

  for (int i = 0; i < n; i++) {
    int t = stu[i].score;
    if (t <= 100 && t >= 80) {
      num1++;
    } else if (t <= 79 && t >= 60) {
      num2++;
    } else {
      num3++;
    }
  }

  printf("%d %d %d\n", num1, num2, num3);

  return EXIT_SUCCESS;
}
