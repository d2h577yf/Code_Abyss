#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

const int PEN_COST = 1*10+9;

int main(int argc, char *argv[])
{
  int a,b,sum,num;
  scanf("%d %d",&a,&b);

  sum = a*10+b;
  num = sum/PEN_COST;

  printf("%d\n",num);

  return EXIT_SUCCESS;
}
