#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

double Calculate_The_Factorial(int i){
  double factorial = 1;
  if (i!=0){ 
  for (int j = 1;j<=i;j++) {
    factorial *= j;
  }
  }
  return factorial;
}

double Compute_Odd_Products(int i){
  double odd_products = 1;
  for (int j = 1;j<=i;j++) {
    odd_products *= (2*j-1);
  }
  return odd_products;
}

int main(int argc, char *argv[])
{
  double thresholds,Half_Pi = 0,each = 1;
  scanf("%lf",&thresholds);
  for (int i=1;each>=thresholds;i++) {
    each = Calculate_The_Factorial(i-1)/Compute_Odd_Products(i);
   Half_Pi += each;
  }

  printf("%.6f",Half_Pi*2);

  return EXIT_SUCCESS;
}
