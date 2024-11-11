#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
  int N,cnt_odd=0,cnt_even=0;
  scanf("%d",&N);

  int s[N];
  
  for (int i= 0;i<N;i++) {
    scanf("%d",&s[i]);
  }

  for (int j=0;j<N;j++) {
    if (s[j]%2==1) {
      cnt_odd++;
    }else {
      cnt_even++;
    }
  }

  printf("%d %d\n",cnt_odd,cnt_even);

  return EXIT_SUCCESS;
}
