#include <stdio.h>
#include <string.h>
int main(){
    int n,cnt = 0,j = 1,k = 1;
    scanf("%d",&n);
    int num[n + 2][n + 2];
    memset(num,1,sizeof(num));
    for(int i = 1;i < n + 1;i++){
        for(int j = 1;j < n + 1;j++){
            num[i][j] = 0;
        }
    }
    for(int i = 1;i <= n * n;i++){
        num[j][k] = i;
        switch (cnt % 4){
            case 0:
                if(num[j][k + 1] == 0){
                    k++;
                }else{
                    j++;
                    cnt++;
                }
                break;
            case 1:
                if(num[j + 1][k] == 0){
                    j++;
                }else{
                    k--;
                    cnt++;
                }
                break;
            case 2:
                if(num[j][k - 1] == 0){
                    k--;
                }else{
                    j--;
                    cnt++;
                }
                break;
            case 3:
                if(num[j - 1][k] == 0){
                    j--;
                }else{
                    k++;
                    cnt++;
                }
                break;
            }
        }
    for(int i = 1;i < n + 1;i++){
        for(int j = 1;j < n + 1;j++){
            printf("%3d",num[i][j]);
        }
        printf("\n");
    }
    return 0;
}