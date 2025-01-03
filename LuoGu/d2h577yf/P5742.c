#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct {
  int ID;
  int Learning;
  int perform;
} Student;

int main(int argc, char *argv[]) {
  int n;
  scanf("%d", &n);
  Student stu[n];
  for (int i = 0; i < n; i++) {
    scanf("%d %d %d", &stu[i].ID, &stu[i].Learning, &stu[i].perform);
    int sum = stu[i].Learning + stu[i].perform;
    int total = stu[i].Learning * 7 + stu[i].perform * 3;
    if (sum > 140 && total >= 800) {
      printf("Excellent\n");
    } else {
      printf("Not excellent\n");
    }
  }
  return EXIT_SUCCESS;
}
