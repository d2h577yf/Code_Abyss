#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
  int a,b,c,d,start,end,delat,hour,min;
  scanf("%d %d %d %d",&a,&b,&c,&d);
  
  start = a*60+b;
  end = c*60+d;

  delat = end - start;
  
  hour = delat/60;
  min = delat%60;

  printf("%d %d\n",hour,min);
  


  return EXIT_SUCCESS;
}
