#include <stdio.h>
int main(){
    int n,m,check,grey_level[16] = {0};
    scanf("%d %d",&n, &m);
    for(int i = 0;i < n * m;i++){
        scanf("%d",&check);
        grey_level[check]++;
    }

    for(int i = 0;i < 16;i++){
        if(grey_level[i] != 0){
            printf("%d %d\n",i,grey_level[i]);
        }
    }

    return 0;
}