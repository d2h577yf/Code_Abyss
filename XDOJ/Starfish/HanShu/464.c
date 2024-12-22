#include <stdio.h>

void printFactorial(int n){
    if(n < 0 || n > 1000){
        printf("Invalid input");
    }else{
        int num[6000] = {0};
        num[0] = 1;
        for(int i = 1;i <= n;i++){
            for(int j = 0;j < 6000;j++){
                if(num[j] >= 10){
                    num[j + 1] += num[j] / 10;
                    num[j] %= 10;
                }
            }
            for(int k = 0;k < 6000;k++){
                num[k] *= i;
            }
        }
        for(int i = 0;i < 6000;i++){
            if(num[i] >= 10){
                num[i + 1] += num[i] / 10;
                num[i] %= 10;
            }
        }
        for(int i = 5999;i >= 0;i--){
            if(num[i] != 0){
                for(int j = i;j >= 0;j--){
                    printf("%d",num[j]);
                }
                break;
            }
        }
    }
}

int main(){
    int n;
    scanf("%d",&n);
    printFactorial(n);

    return 0;
}