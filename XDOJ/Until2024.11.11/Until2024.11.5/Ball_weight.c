#include <stdio.h>
#include <math.h>

const double PI = 3.1415926;

double final_w(int x){
  return (4.0/3.0)*PI*pow((x/20.0),3);
}


int main(int argc, char *argv[])
{
  int Fe_d , Au_d;
  scanf("%d %d",&Fe_d,&Au_d);

  printf("%.3f %.3f",(final_w(Fe_d)*7.86),(final_w(Au_d)*19.3));


  return 0;
}
