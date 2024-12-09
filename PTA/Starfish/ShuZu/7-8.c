#include <stdio.h>
#include <string.h>
int main(){
    int n,t1 = 0,t2 = 0,check,judge,cnt = 0;
    int x1,x2,y1,y2;
    scanf("%d",&n);
    char num[2 * n][2 * n];
    char c1[2*n*n],c2[2*n*n];
    memset(c1,'0',sizeof(c1));
    memset(c2,'0',sizeof(c2));
    for(int i = 0;i < 2 * n;i++){
        for(int j = 0;j < 2 * n;j++){
            scanf(" %c",&num[i][j]);
            judge = 0;
            for(int k = 0;k < 2*n*n;k++){
                if(c1[k] == num[i][j]){
                    judge = 1;
                    check = 0;
                    for(int l = 0;l < 2*n*n;l++){
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
    int q;
    scanf("%d",&q);
    for(int p = 0;p < q;p++){
        if(cnt == 3){
            printf("Game Over");
            break;
        }
        scanf("%d %d %d %d",&x1,&y1,&x2,&y2);
        if(num[x1-1][y1-1] == num[x2-1][y2-1] && num[x1-1][y1-1] != '*'){
            num[x1-1][y1-1] = '*';
            num[x2-1][y2-1] = '*';
            check = 1;
            for(int i = 0;i <2*n*n;i++){
                for(int j = 0;j < 2*n;j++){
                    for(int k = 0;k < 2*n;k++){
                        if(c2[i] == num[j][k]){
                            check = 0;
                            break;
                        }
                    }
                }
            }
            if(check == 1){
                printf("Congratulations!");
                break;
            }
            for(int i = 0;i < 2 * n;i++){
                for(int j = 0;j < 2 * n;j++){
                    printf("%c",num[i][j]);
                    if(j < 2 * n - 1){
                        printf(" ");
                    }
                }
                printf("\n");
            }
        }else{
            printf("Uh-oh\n");
            cnt++;
        }
    }
    return 0;
}