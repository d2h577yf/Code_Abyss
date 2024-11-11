#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
  int trans;
  char x;
  scanf("%c",&x);
  
  trans = 'A'-'a';
  printf("%c\n",(x+trans));

  return EXIT_SUCCESS;
}
