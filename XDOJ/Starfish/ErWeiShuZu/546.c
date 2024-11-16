#include <stdio.h>
int main(){
    int cnt = 0;
    double a,b,c,d,answer[9];
    scanf("%lf,%lf,%lf,%lf",&a,&b,&c,&d);
    answer[0] = a*a + b*b - c*c - d*d;
    answer[1] = 2.0 * (b*c - a*d);
    answer[2] = 2.0 * (b*d + a*c);
    answer[3] = 2.0 * (b*c + a*d);
    answer[4] = a*a - b*b + c*c - d*d;
    answer[5] = 2.0 * (b*d - a*b);
    answer[6] = 2.0 * (b*d - a*c);
    answer[7] = 2.0 * (c*d + a*b);
    answer[8] = a*a - b*b - c*c + d*d;
    for(int i = 0;i < 9;i++){
        printf("%f ",answer[i]);
        if((i + 1) % 3 == 0){
            printf("\n");
        }
    }
}