#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

int Find_The_Factorial_Of_A_Number(int i){
  int num=1; 
  for (int j =1;j<=i;j++) {
    num *= j;
  }
  return num;
}

int main(int argc, char *argv[])
{
  int N,sum=0;
  scanf("%d",&N);
  for (int i = 1;i<=N;i++) {
    sum += Find_The_Factorial_Of_A_Number(i);
  }
  
  printf("%d\n", sum);

  return EXIT_SUCCESS;
}
