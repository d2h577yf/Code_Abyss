#include <stdio.h>
#include <string.h>
int main(){
    int cnt = 0,ret;
    char blablabla[60],copy[60];
    scanf("%[^\n]",blablabla);
    for(int i = 0;blablabla[i] != '\0';i++){
        cnt++;
    }
    copy[cnt] = '\0';
    for(int i = 0;cnt > 0;i++){
        copy[i] = blablabla[cnt - 1];
        cnt--;
    }
    if(strcmp(blablabla,copy) == 0){
        printf("yes");
    }else{
        printf("no");
    }

    return 0;
}