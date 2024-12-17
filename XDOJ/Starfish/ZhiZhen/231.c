#include <stdio.h>
int main(){
    int t = 0,max = 0;
    char sentance[111];
    scanf("%[^\n]",sentance);
    for(int i = 0;;i++){
        if(sentance[i] == '\0'){
            break;
        }
        if(sentance[i] == ' '){
            if(max < t){
                max = t;
            }
            t = 0;
        }else{
            t++;
        }   
    }
    t--;
    if(max < t){
        max = t;
    }
    printf("%d",max);

    return 0;
}