#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char *argv[])
{
  double a,b,c;
  double p,area;
  scanf("%lf %lf %lf",&a,&b,&c);

  p = (a+b+c)/2;
  
  area = sqrt(p*(p - a)*(p - b)*(p - c));

  printf("%.1f\n",area);

  return EXIT_SUCCESS;
}
