#include <stdio.h>
#include <ctype.h>
#include <string.h>
int main(){
    char n[30];
    int i,t = 0,k = 0,check,num[2] = {0,0};
    scanf("%[^\n]",n);
    for(i = 0;i < strlen(n);i++){
        if(isdigit(n[i])){
            t = t * 10 + n[i] - 48;
        }else{
            if(num[0] == 0){
                num[0] = t;
                t = 0;
            }
            if(num[0] != 0){
                num[1] = t;
            }
            if(n[i] != ' '){
                check = (int)n[i];
            }
        }
        
    }

    if(isdigit(n[i - 1])){
        num[1] = t;
    }

    switch (check){
        case '+':
            printf("%d",num[0] + num[1]);
            break;
        case '-':
            printf("%d",num[0] - num[1]);
            break;
        case '*':
            printf("%d",num[0] * num[1]);
            break;
        case '/':
            printf("%d",num[0] / num[1]);
            break;
        default:
            printf("%d",num[0] % num[1]);
    }

    return 0;    
}