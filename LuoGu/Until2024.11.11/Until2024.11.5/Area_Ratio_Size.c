#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
  int a, b, c;
  long long int A_area, B_area; 
  scanf("%d %d %d", &a, &b, &c);

  A_area = (long long int)a * a; // 直接使用整数运算计算平方
  B_area = (long long int)b * c;

  if (A_area > B_area) {
    printf("Alice\n");
  } else {
    printf("Bob\n"); // 添加换行符
  }

  return EXIT_SUCCESS;
}
