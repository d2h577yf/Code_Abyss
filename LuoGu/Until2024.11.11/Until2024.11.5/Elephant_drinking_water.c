#include <stdbool.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

const double PI = 3.14;
const int TARGET = 20000;

int main(int argc, char *argv[])
{
  int h,r;
  double v;
  scanf("%d %d",&h,&r);

  v = h*PI*pow(r,2);

  double need = ceil(TARGET/v);

  printf("%.0f\n",need);

  return EXIT_SUCCESS;
}
