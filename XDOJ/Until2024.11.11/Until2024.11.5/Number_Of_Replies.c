#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

bool judge(int s[],int length){
  bool truth = 1;
  for (int i = 0; i < length ; i++) {
    if (s[i] != s[length -i -1]) {
      truth = 0;
    }
  }
  return truth;
}

int main(int argc, char *argv[])
{
  int n,cnt=0,sum=0,m;
  scanf("%d",&n);
  m=n;
  while (m!=0) {
    m /=10;
    cnt++;
  }
  
  int s[cnt];

  for (int i =0;i<cnt;i++) {
    s[i]=n%10;
    n /=10;
  }

  if (judge(s,cnt)) {
    for (int i = 0; i < cnt; i++) {
      sum +=s[i];
    }
    printf("%d\n",sum);
  }else {
    printf("no\n");
  }


  return EXIT_SUCCESS;
}
