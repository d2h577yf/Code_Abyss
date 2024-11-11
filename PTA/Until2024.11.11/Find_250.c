#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
  int n=0,cnt=0;
  
  while (n!=250) {
    scanf("%d",&n);
    cnt++;
  }
  
  printf("%d\n",cnt);

  return EXIT_SUCCESS;
}
