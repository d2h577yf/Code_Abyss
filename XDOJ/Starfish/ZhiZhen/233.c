#include <stdio.h>
void copystr(char* a,char* b,int t){
    int check = 0;
    for(int i = 0;a[t - 1] != '\0';i++){
        b[i] = a[t - 1];
        t++;
        check++;
    }
    b[check] = '\0';
    printf("%s",b);
}

int main(){
    int cnt = 0,m;
    char starfish[60],copy[60];
    scanf("%[^\n]",starfish);
    scanf("%d",&m);
    for(int i = 0;starfish[i] != '\0';i++){
        cnt++;
    }
    if(m > cnt){
        printf("error");
    }else{
        copystr(starfish,copy,m);
    }
    return 0;
}