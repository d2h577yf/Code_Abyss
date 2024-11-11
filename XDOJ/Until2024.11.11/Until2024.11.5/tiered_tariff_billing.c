#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
  double electronic,ele_rate1,ele_rate2,ele_rate3;
  scanf("%lf",&electronic);
  ele_rate1 = 0.5;
  ele_rate2 = 0.55;
  ele_rate3 = 0.7;

  if(electronic>=0&&electronic<=110){
    printf("%.2f\n",electronic*ele_rate1);
  }else if (electronic>110&&electronic<=210){
  printf("%.2f\n",110*ele_rate1+(electronic-110)*ele_rate2);
  }else{
    printf("%.2f\n",110*ele_rate1+100*ele_rate2+(electronic - 210)*ele_rate3);
  }

  return 0;
}
