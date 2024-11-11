#include <stdio.h>
#include <ctype.h>
#include <string.h>
int main(){
    char n[30];
    int i,t = 0,k = 0,check,num[2];
    scanf("%[^\n]",n);
    for(i = 0;i < strlen(n);i++){
        if(isdigit(n[i])){
            t = t * 10 + n[i] - 48;
        }else{
            num[k++] = t;
        }
        if(n[i] != ' '){
            check = n[i];
        }
    }

    if(isdigit(n[i - 1])){
        num[k] = t;
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