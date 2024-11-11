#include <stdio.h>

int main(){
    int fm = 1;
    double eps, item = 0.0, sum = 0.0, sign = 1.0;
    
    scanf("%lf", &eps);
    
    do{
        item = 1.0 / fm * sign;
        sign = -sign;
        fm += 3;
        sum += item;
    } while ((item > 0 ? item : -item) > eps);
    
    printf("sum = %.6f\n", sum);
    
    return 0;
}

