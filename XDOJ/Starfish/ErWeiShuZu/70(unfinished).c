#include <stdio.h>
int main(){
    int n,i = 0,j = 0;
    scanf("%d",&n);
    int num[n][n];
    for(int i = 0;i < n;i++){
        for(int j = 0;j < n;j++){
            scanf("%d",&num[i][j]);
        }
    }
    
    if(n % 2 == 0){
        printf("%d ",num[0][0]);
        j = 1;
        for(int cnt = 2;cnt <= n - 2;cnt += 2){
            for(int k = 0;k < cnt;k++){
                printf("%d ",num[i++][j--]);
            }
            j++;
            for(int k = 0;k < cnt + 1;k++){
                printf("%d ",num[i--][j++]);
            }
            i++;
        }
        for(int k = 0;k < n;k++){
            printf("%d ",num[i++][j--]);
        }
        i--;
        j += 2;
        for(int cnt = n - 2;cnt >= 2;cnt -= 2){
            for(int k = 0;k <cnt + 1;k++){
                printf("%d ",num[i--][j++]);
            }
            j--;
            i += 2;
            for(int k = 0;k < cnt;k++){
                printf("%d ",num[i++][j--]);
            }
            i--;
            j += 2;
        }
        printf("%d",num[n - 1][n - 1]);
    }

    return 0;
}