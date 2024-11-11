#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char *argv[])
{
  int a,n,sum=0,num=1,m;
  scanf("%d %d",&a,&n);
  m = num;

  for (int i =1 ;i<=n;i++) {
    sum += m;
    m += num*pow(10,i);
  }

  printf("s = %d\n", a*sum);
  return EXIT_SUCCESS;
}
