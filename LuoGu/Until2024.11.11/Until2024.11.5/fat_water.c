#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
  double t;
  int n;

  scanf("%lf %d",&t,&n);
  printf("%.3f\n%d",t/n,n*2);
  return EXIT_SUCCESS;
}
