#include <stdio.h>
int main(){
    int n,m,t;
    scanf("%d %d",&m,&n);
    int num[n][n];
    int copy[n][n];
    for(int i = 0;i < n;i++){
        for(int j = 0;j < n;j++){
            scanf("%d",&num[i][j]);
            copy[i][j] = num[i][j];
        }
    }
    for(int i = 0;i < n;i++){
        for(int j = 0;j < n;j++){
            t = j + m;
            while (t >= n){
                t -= n;
            }
            num[i][t] = copy[i][j];
        }
    }
    for(int i = 0;i < n;i++){
        for(int j = 0;j < n;j++){
            printf("%d ",num[i][j]);
        }
        printf("\n");
    }
    return 0;
}