#include <stdio.h>
#include <ctype.h>
int main(){
    char num[14];
    int sum = 0,t = 0,k = 0,n[10];
    scanf("%s",num);
    for(int i = 0;i < 14;i++){
        if(isdigit(num[i])){
            n[k++] = num[i] - '0';
        }
    }
    for(int i = 0;i < 9;i++){
        sum += n[i] * (i + 1);
    }
    if(sum % 11 == 10){
        if(num[12] == 'X'){
            printf("Right");
        }else{
            for(int i = 0;i < 12;i++){
                printf("%c",num[i]);
            }
            printf("X");
        }
    }else{
        if(n[9] == sum % 11){
            printf("Right\n");
        }else{
            for(int i = 0;i < 12;i++){
                printf("%c",num[i]);
            }
            printf("%d\n",sum % 11);
        }
    }

    return 0;
}