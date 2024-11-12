#include <stdio.h>
int main(){
    char n,cnt = 0;
    char sentence[101];
    int num;
    scanf("%c %d",&n,&num);
    getchar();
    scanf("%s",&sentence);

    if(num == 1){
        for(int i = 0;sentence[i] != '\0';i++){
            if(n == sentence[i]){
                cnt++;
            }
        }
    }else{
        if(n >= 'a'){
            n = n - 32;
        }

        for(int i = 0;sentence[i] != '\0';i++){
            if(n == sentence[i] || n == sentence[i] - 32){
                cnt++;
            }
        }
    }

    printf("%d",cnt);

    return 0;
}