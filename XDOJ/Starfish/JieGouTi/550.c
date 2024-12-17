#include <stdio.h>
struct employer{
    char name[11];
    float wage,fwage,cost,last;
};

int main(){
    int n;
    scanf("%d",&n);
    struct employer emo[n];
    for(int i  = 0;i < n;i++){
        scanf("%s %f %f %f",emo[i].name,&emo[i].wage,&emo[i].fwage,&emo[i].cost);
        emo[i].last = emo[i].wage + emo[i].fwage - emo[i].cost;
    }
    for(int i = 0;i < n;i++){
        printf("%s %.2f\n",emo[i].name,emo[i].last);
    }
    return 0;
}