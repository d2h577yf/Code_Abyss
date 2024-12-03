#include <stdio.h>
int main(){
    int m,n,sum;
    scanf("%d %d",&m,&n);
    int num[m][n];
    for(int i = 0;i < m;i++){
        for(int j = 0;j < n;j++){
            scanf("%d",&num[i][j]);
        }
    }
    for(int i = 0;i < m;i++){
        sum = 0;
        for(int j = 0;j < n;j++){
            sum += num[i][j];
        }
        printf("%d\n",sum);
    }
    return 0;
}