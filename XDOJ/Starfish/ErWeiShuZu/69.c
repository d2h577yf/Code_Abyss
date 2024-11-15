#include <stdio.h>
int main(){
    int m,n,start,end,max,check;
    scanf("%d %d",&m,&n);
    int num[m][n];
    for(int i = 0;i < m;i++){
        for(int j = 0;j < n;j++){
            scanf("%d",&num[i][j]);
        }
    }
    for(int i = 0;i < m;i++){
        start = -1;
        end = -1;
        max = 0;
        check = 0;
        for(int j = 0;j < n;j++){
            if(num[i][j] == 1){
                check++;
            }else{
                if(max < check){
                    max = check;
                    start = j - check;
                    end = j - 1;
                }
                check = 0;
            }
        }
        if(max < check){
                max = check;
                start = n - check;
                end = n - 1;
        }
        printf("%d %d\n",start,end);
    }

    return 0;
}