#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main(int argc, char *argv[])
{
  int m,t,s,cnt;
  scanf("%d %d %d",&m,&t,&s);

  if (t!=0) {

  cnt = ceil((double)s/t); 
    if (m - cnt >=0) {
    printf("%d\n",m-cnt );
    }else {
      printf("%d\n",0);
    }
  }else {
    printf("0\n");
  }
  return EXIT_SUCCESS;
}
