#include <stdio.h>
int main(){
    int n1,n2;
    scanf("%d %d",&n1,&n2);
    int num[n1][n2],copy[n1][n2];
    for(int i = 0;i < n1;i++){
        for(int j = 0;j < n2;j++){
            scanf("%d",&num[i][j]);
        }
    }
    for(int i = 0;i < n1;i++){
        for(int j = 0;j < n2;j++){
            copy[i][j] = num[i][j];
        }
    }
    for(int i = 0;i < n1;i++){
        for(int j = 0;j < n2 - 2;j++){
            if(copy[i][j] == copy[i][j + 2] && copy[i][j] == copy[i][j + 1]){
                num[i][j] = 0;
                num[i][j + 1] = 0;
                num[i][j + 2] = 0;
            }
        }
    }
    for(int j = 0;j < n2;j++){
        for(int i = 0;i < n1 - 2;i++){
            if(copy[i][j] == copy[i + 1][j] && copy[i][j] == copy[i + 2][j]){
                num[i][j] = 0;
                num[i + 1][j] = 0;
                num[i + 2][j] = 0;
            }
        }
    }
    for(int i = 0;i < n1;i++){
        for(int j = 0;j < n2;j++){
            printf("%d ",num[i][j]);
        }
        printf("\n");
    }

    return 0;
}