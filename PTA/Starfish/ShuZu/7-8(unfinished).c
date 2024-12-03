#include <stdio.h>
#include <string.h>
int main(){
    int n,t1 = 0,t2 = 0,check,judge;
    scanf("%d",&n);
    char num[2 * n][2 * n];
    char c1[n],c2[n];
    memset(c1,'0',sizeof(c1));
    memset(c2,'0',sizeof(c2));
    for(int i = 0;i < 2 * n;i++){
        for(int j = 0;j < 2 * n;j++){
            scanf(" %c",&num[i][j]);
            judge = 0;
            for(int k = 0;k < n;k++){
                if(c1[k] == num[i][j]){
                    judge = 1;
                    check = 0;
                    for(int l = 0;l < n;l++){
                        if(c2[l] == num[i][j]){
                            check = 1;
                            break;
                        }
                    }
                    if(check == 0){
                        c2[t2++] = num[i][j];
                    }
                }
            }
            if(judge == 0){
                c1[t1++] = num[i][j];
            }
        }
    }
    for(int i = 0;i < 2 * n;i++){
        for(int j = 0;j < 2 * n;j++){
            printf("%c ",num[i][j]);
        }
        printf("\n");
    }
    return 0;
}