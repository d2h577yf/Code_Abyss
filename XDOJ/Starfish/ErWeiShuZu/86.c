#include <stdio.h>
#include <string.h>
int main(){
    int n,x1,x2,y1,y2,sum = 0,aera[101][101];
    memset(aera,0,sizeof(aera));
    scanf("%d",&n);
    for(int i = 0;i < n;i++){
        scanf("%d %d %d %d",&x1,&y1,&x2,&y2);
        for(int i = y1;i < y2;i++){
            for(int j = x1;j < x2;j++){
                aera[i][j] = 1;
            }
        }
    }
    for(int i = 0;i < 101;i++){
        for(int j = 0;j < 101;j++){
            sum += aera[i][j];
        }
    }
    printf("%d",sum);

    return 0;
}