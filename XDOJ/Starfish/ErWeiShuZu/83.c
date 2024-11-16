#include <stdio.h>
int main(){
    int n,m;
    scanf("%d %d",&n,&m);
    int num[n][m];
    for(int i = 0;i < n;i++){
        for(int j = 0;j < m;j++){
            scanf("%d",&num[i][j]);
        }
    }
    for(int j = 0;j < m;j++){
        for(int i = n - 1;i >= 0;i--){
            printf("%d ",num[i][j]);
        }
        printf("\n");
    }
    return 0;
}