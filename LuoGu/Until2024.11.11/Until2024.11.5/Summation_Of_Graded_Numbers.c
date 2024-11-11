#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
  int k,n=0;
  double S=0;
  scanf("%d",&k);
  
  while (S<=k) { 
    n++;
    S += 1.0/n;
  }

  printf("%d\n",n);

  return EXIT_SUCCESS;
}
