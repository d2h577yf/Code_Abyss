#include <stdio.h>
int main(){
    int num,n,win,score;
    struct team{
        char name[50];
        int win;
        int score;
        int sum;
    };
    scanf("%d",&n);

    struct team tm[n];
    struct team temple;
    for(int i = 0;i < n;i++){
        scanf("%s",&tm[i].name);
    }
    for(int i = 0;i < n;i++){
        win = 0;
        score = 0;
        for(int j = 0;j < n;j++){
            scanf("%d",&num);
            if(num > 0){
                win++;
            }
            if(num == 3 || num == 4){
                score += 3;
            }else if(num == 5){
                score += 2;
            }else if(num == -5){
                score++;
            }
        }
        tm[i].win = win;
        tm[i].score = score;
        tm[i].sum = win*100+score;
    }

    for(int i = 1;i < n;i++){
        for(int j = 0;j < n - i;j++){
            if(tm[j].sum < tm[j+1].sum){
                temple = tm[j+1];
                tm[j+1] = tm[j];
                tm[j] = temple;
            }else if (tm[j].sum == tm[j+1].sum){
                if(tm[j].name[0] > tm[j+1].name[0]){
                    temple = tm[j+1];
                    tm[j+1] = tm[j];
                    tm[j] = temple;
                }
            }
            
        }
    }

    for(int i = 0;i < n;i++){
        for(int j = 0;tm[i].name[j] != '\0';j++){
            printf("%c",tm[i].name[j]);
        }
        printf(" %d %d\n",tm[i].win,tm[i].score);
    }

    return 0;
}