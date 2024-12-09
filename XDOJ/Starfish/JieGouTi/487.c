#include <stdio.h>
int main(){
    char blablabla[21];
    int n,num,record[3] = {0};
    scanf("%d",&n);
    for(int i = 0;i < n;i++){
        scanf("%s %d",&blablabla,&num);
        if(num >= 80 && num <= 100){
            record[0]++;
        }else if(num < 60 && num >= 0){
            record[2]++;
        }else if(num >= 60 && num < 80){
            record[1]++;
        }
    }
    for(int i = 0;i < 3;i++){
        printf("%d ",record[i]);
    }
    return 0;
}