#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
  int N,cnt=1,m;
  scanf("%d",&N);
  m=N;

  while(m!=0){
    m /=10;
    cnt++;
  }
  

  char str[cnt-1];

  sprintf(str, "%d",N);

  for (int i=0;i<cnt-1;i++) {
    printf("%c ",str[i]);
  }
  return EXIT_SUCCESS;
}
