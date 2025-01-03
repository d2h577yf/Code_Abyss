#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct {
  char name[9];
  int number[3];
  int score;
} Student;

int main(int argc, char *argv[]) {
  int N, maxIndex = 0;
  scanf("%d", &N);
  Student stu[N];
  for (int i = 0; i < N; i++) {
    stu[i].score = 0;
    scanf("%s", stu[i].name);
    for (int j = 0; j < 3; j++) {
      scanf("%d", &stu[i].number[j]);
      stu[i].score += stu[i].number[j];
    }
    if (stu[maxIndex].score < stu[i].score) {
      maxIndex = i;
    }
  }

  printf("%s ", stu[maxIndex].name);

  for (int i = 0; i < 2; i++) {
    printf("%d ", stu[maxIndex].number[i]);
  }

  printf("%d", stu[maxIndex].number[2]);

  return EXIT_SUCCESS;
}
