#include <stdio.h>
#include <string.h>
#include <ctype.h>
int main(){
    int strength = 0,cnt = -1,i;
    char lock[51];
    memset(lock,'\0',sizeof(lock));
    scanf("%s",&lock);

    for(i = 0;lock[i] != 0;i++){
    }
    if(i > 0){
        strength++;
        if(i > 8){
            strength++;
        }
    }
    for(int i = 0;lock[i] != 0;i++){
        if(lock[i] >= 'a' && lock[i] <= 'z'){
            cnt++;
            break;
        }
    }
    for(int i = 0;lock[i] != 0;i++){
        if(lock[i] >= '0' && lock[i] <= '9'){
            cnt++;
            break;
        }
    }
    for(int i = 0;lock[i] != 0;i++){
        if(lock[i] >= 'A' && lock[i] <= 'Z'){
            cnt++;
            break;
        }
    }
    for(int i = 0;lock[i] != 0;i++){
        if(isdigit(lock[i]) == 0 && isalpha(lock[i]) == 0){
            cnt++;
            break;
        }
    }
    if(cnt > 0){
        strength += cnt;
    }
    printf("%d",strength);

    return 0;
}
