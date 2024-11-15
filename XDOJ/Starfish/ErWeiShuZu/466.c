#include <stdio.h>
int main(){
    int n,cnt = 0,num = 1,check = 0;
    scanf("%d",&n);
    int teamnum[n],distance = n;
    for(int i = 0;i < n;i++){
        scanf("%d",&teamnum[i]);
    }
    for(int i = 0;i < n;i++){
        distance = n;
        check = 0;
        num = 1 + i;
        printf("#%d\n",i + 1);
        for(int j = 0;j < 8 * teamnum[i];j++){
            printf("%d ",num);
            cnt++;
            num += distance;
            //printf("cnt:%d ",cnt);
            if(cnt == 8){
                printf("\n");
                cnt = 0;
                check++;
                //printf("check = %d\n",check);
                for(int l = 0;l < n;l++){
                    if(check == teamnum[l]){
                        if(i < l){
                            num++;
                        }
                        distance--;
                        num--;
                        if(distance < 2){
                            num++;
                            distance = 2;
                            break;
                        }
                    }
                }
            }
        }
    }

    return 0;

}