#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

const float PERFORMANCE_ON_HOMEWORK = 0.2;
const float QUIZ_SCORE = 0.3;
const float FINAL_EXAM_RESULT = 0.5;


int main(int argc, char *argv[])
{
  int a,b,c,sum;
  scanf("%d %d %d",&a,&b,&c);
  
  sum = a*PERFORMANCE_ON_HOMEWORK+b*QUIZ_SCORE+c*FINAL_EXAM_RESULT;
  printf("%d\n",sum);

  return EXIT_SUCCESS;
}
