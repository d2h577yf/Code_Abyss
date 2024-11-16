#include <stdio.h>
#include <string.h>
int main(){
    int n,m,t,k,cnt = 0,check_num = 0,h = 0,save;
    scanf("%d %d %d %d",&n,&m,&t,&k);
    int num[n + 2][m + 2],check[t];
    memset(check,0,sizeof(check));

    for(int i = 0;i < n + 2;i++){
        for(int j = 0;j < m + 2;j++){
            num[i][j] = k;
        }
    }

    for(int i = 1;i < n + 1;i++){
        for(int j = 1;j < m + 1;j++){
            scanf("%d",&num[i][j]);
        }
    }

    for(int i = 1;i < n + 1;i++){
        for(int j = 1;j < m + 1;j++){
            if(num[i][j] == k){
                check_num = 1;

                if(num[i - 1][j] != k){
                    check_num = 0;
                    save = num[i - 1][j];
                    for(int l = 0;l < t;l++){
                        if(check[l] == save){
                            check_num = 1;
                            break;
                        }
                    }
                    if(check_num == 0){
                        cnt++;
                        check[h++] = save;
                    }
                }
                if(num[i + 1][j] != k){
                    check_num = 0;
                    save = num[i + 1][j];
                    for(int l = 0;l < t;l++){
                        if(check[l] == save){
                            check_num = 1;
                            break;
                        }
                    }
                    if(check_num == 0){
                        cnt++;
                        check[h++] = save;
                    }
                }
                if(num[i][j + 1] != k){
                    check_num = 0;
                    save = num[i][j + 1];
                    for(int l = 0;l < t;l++){
                        if(check[l] == save){
                            check_num = 1;
                            break;
                        }
                    }
                    if(check_num == 0){
                        cnt++;
                        check[h++] = save;
                    }
                }
                if(num[i][j - 1] != k){
                    check_num = 0;
                    save = num[i][j - 1];
                    for(int l = 0;l < t;l++){
                        if(check[l] == save){
                            check_num = 1;
                            break;
                        }
                    }
                    if(check_num == 0){
                        cnt++;
                        check[h++] = save;
                    }
                }

            }
        }
    }

    /*for(int i = 0;i < t;i++){
        printf("%d ",check[i]);
    }

    printf("\n");

    for(int i = 0;i < n + 2;i++){
        for(int j = 0;j < m + 2;j++){
            printf("%d ",num[i][j]);
        }
        printf("\n");
    }*/
    printf("%d",cnt);

    return 0;
}