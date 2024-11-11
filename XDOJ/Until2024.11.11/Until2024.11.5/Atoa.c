#include <stdio.h>


char t(char i){
  int x;
  char y;
  x = 'A'-'a';
  y = i - x;
  return y;
}

int main(int argc, char *argv[])
{
  char a,b,c,d,e;
  scanf("%c|%c|%c|%c|%c",&a,&b,&c,&d,&e);

  printf("%c%c%c%c%c!",t(a),t(b),t(c),t(d),t(e));

  return 0;
}
