#include <stdio.h>
#include <math.h>


int main(int argc, char *argv[])
{
  int h,m;
  scanf("%d %d",&h,&m);
  
  double t = h + m/60.0;
  
  double T = (4*pow(t,2))/(t+2)-20;
  
  printf("%.2f\n",T);
  return 0;
}
