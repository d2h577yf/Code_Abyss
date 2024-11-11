#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

double Find_the_best_hight(char sex,double x){
  double best_hight = 1;
  if (sex=='F') {
    best_hight = x*1.09;
  }else {
    best_hight = x/1.09;
  }
    return best_hight;
}

int main(int argc, char *argv[])
{
  int N;
  char sex;
  double H;
  scanf("%d",&N);
  double s[N];

  for (int i =0;i<N;i++) {
    scanf(" %c %lf",&sex,&H);
    s[i]=Find_the_best_hight(sex,H);
  }
  
  for (int j = 0;j<N;j++) {
    printf("%.2f\n",s[j]);
  }

  return EXIT_SUCCESS;
}
