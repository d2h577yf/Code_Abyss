#include <stdio.h>
#include <string.h>
int main(){
    int n1,n2;
    char word[101],sentence[101],copy[101];
    scanf("%s\n%d\n%d",&word,&n1,&n2);
    if(n1 == 1){
        for(int i = 0;i < n2;i++){
            scanf(" %s",&sentence);
            if(strstr(sentence,word)){
                printf("%s\n",sentence);
            }
        }
    }else{
        for(int i = 0;i < n2;i++){
            scanf(" %s",&sentence);
            memset(copy,'\0',sizeof(copy));
            for(int i = 0;sentence [i] != 0;i++){
                copy[i] = sentence[i];
            }
            for(int i = 0;sentence[i] != 0;i++){
                if(sentence[i] >= 'a'){
                    sentence[i] -= 32;
                }
            }
            for(int i = 0;word[i] != 0;i++){
                if(word[i] >= 'a'){
                    word[i] -= 32;
                }
            }
            if(strstr(sentence,word)){
                printf("%s\n",copy);
            }
        }
    }

    return 0;
}