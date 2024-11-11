#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct Result {
  int max;
  int min;
} result;  

void find_max_min(int s[], int n) {
  int max = s[0];
  int min = s[0];

  for (int j = 1; j < n; j++) {
    if (max < s[j]) {
      max = s[j];
    }
    if (min > s[j]) {
      min = s[j];
    }
  }

  result.max = max;
  result.min = min;
}

int main() {
  int cnt = 0, n, m;

  scanf("%d", &n);
  
  if(n!=0){
  m = n;

  cnt = log10(m) + 1;

  int s[cnt];
  for (int i = cnt - 1; i >= 0; i--) {
    s[i] = m % 10;  
    m = m / 10; 
  }

  find_max_min(s, cnt);

  printf("%d %d %d\n", cnt, result.max, result.min);
  }else {
    printf("%d %d %d\n",1,0,0);
  }

  return EXIT_SUCCESS;
}
