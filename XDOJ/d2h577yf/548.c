#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  char ID[6];
  char name[11];
  int score[5];
  double credits[5];
  double extre_score;
  double credits_total;
  double total;
  int flag;
} Student;

void bubbleSort(Student arr[], int n) {
  for (int i = 0; i < n - 1; i++) {
    for (int j = 0; j < n - i - 1; j++) {
      if (arr[j].total < arr[j + 1].total || 
         (arr[j].total == arr[j + 1].total && strcmp(arr[j].ID, arr[j + 1].ID) > 0)) {
        Student temp = arr[j];
        arr[j] = arr[j + 1];
        arr[j + 1] = temp;
      }
    }
  }
}

int main() {
  int N, M;
  double R;
  scanf("%d %d %lf", &N, &M, &R);

  Student stu[N];
  int validCount = 0;

  for (int i = 0; i < N; i++) {
    Student temp;
    temp.total = 0;
    temp.credits_total = 0;
    temp.flag = 0;

    scanf("%s %s", temp.ID, temp.name);
    for (int j = 0; j < M; j++) {
      scanf("%d %lf", &temp.score[j], &temp.credits[j]);
      temp.total += (temp.score[j] * temp.credits[j]);
      temp.credits_total += temp.credits[j];
      if (temp.score[j] < 60) {
        temp.flag = -1;
      }
    }
    scanf("%lf", &temp.extre_score);

    if (temp.flag == -1) {
      continue; 
    }
    temp.total = (temp.total / temp.credits_total) + temp.extre_score;
    stu[validCount++] = temp;
  }

  bubbleSort(stu, validCount);

  int num = (int)(N * R);
  if (num < 1) {
    num = 1;
  }

  for (int i = 0; i < num && i < validCount; i++) {
    printf("%s %s %.3f\n", stu[i].ID, stu[i].name, stu[i].total);
  }

  return 0;
}
