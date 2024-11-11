#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
  int N,U,D,sum=0,cnt=0;
  scanf("%d %d %d",&N,&U,&D);

  for (int i =1;sum<N;i++) {
    if(i%2==1){
      sum += U;
      cnt++;
    }else {
      sum -= D;
      cnt++;
    }
  }

  printf("%d\n",cnt);

  return EXIT_SUCCESS;
}
