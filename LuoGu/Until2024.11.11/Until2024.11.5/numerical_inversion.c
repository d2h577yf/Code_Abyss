#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
  char a,b,c,d;
  scanf("%c%c%c%c",&a,&b,&c,&d);
  printf("%c%c%c%c\n",d,c,b,a);
  return EXIT_SUCCESS;
}
