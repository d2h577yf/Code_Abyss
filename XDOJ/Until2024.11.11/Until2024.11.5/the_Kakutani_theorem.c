#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
  int n,cnt=0;
  scanf("%d",&n);
  while(n!=1){
    if(n%2==0){
      n = n/2;
    }else {
      n= 3*n+1;
    }

    cnt++;
  }


  printf("%d\n",cnt);
  return EXIT_SUCCESS;
}
