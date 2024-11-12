#include <stdio.h>
#include <ctype.h>
void swap(int *a,int *b){
    float t;
    t = *a;
    *a = *b;
    *b = t;
}

void sort(int *num1,int length){
    for (int i = 1;i < length; i++){
        for (int j = 0;j < length - 1; j++){
            if(num1[j] < num1[j + 1]){
                swap(&num1[j],&num1[j + 1]);
            }
        }
    }
}

int main(){
    int i,t = 0,k = 0,check = 1,num[100] = {-1};
    char chaos[101];
    scanf("%s",chaos);

    for(i = 0;chaos[i] != 0;i++){
        if(isdigit(chaos[i])){
            t = t * 10 + chaos[i] - '0';
            check = 0;
        }else{
            if(check == 0){
                num[k++] = t;
                check = 1;
                t = 0;
            }
        }
    }
    if(isdigit(chaos[i - 1])){
        num[k++] = t;
    }

    num[k] = 0;

    sort(num,k);
    for(int i = 0;i < k;i++){
        printf("%d ",num[i]);
    }

    return 0;
}