#include <stdio.h>
void swap(int *a,int *b){
    float t;
    t = *a;
    *a = *b;
    *b = t;
}

void sort(int *num1,int length){
    for (int i = 1;i < length; i++){
        for (int j = 0;j < length - i; j++){
            if(num1[j] < num1[j + 1]){
                swap(&num1[j],&num1[j + 1]);
            }
        }
    }
}
int main(){
    int m,save;
    scanf("%d",&m);
    int num[m][m],sum[m + m + 2];
    for(int i = 0;i < m;i++){
        for(int j = 0;j < m;j++){
            scanf("%d",&num[i][j]);
        }
    }
    for(int i = 0;i < m;i++){
        save = 0;
        for(int j = 0;j < m;j++){
            save += num[i][j];
        }
        sum[i] = save;
    }
    for(int i = m;i < m + m;i++){
        save = 0;
        for(int j = 0;j < m;j++){
            save += num[j][i - m];
        }
        sum[i] = save;
    }
    save = 0;
    for(int i = 0;i < m;i++){
        save += num[i][i];
    }
    sum[m + m] = save;
    save = 0;
    for(int i = 0;i < m;i++){
        save += num[i][m-i-1];
    }
    sum[m + m + 1] = save;

    sort(sum,m + m + 2);
    for(int i = 0;i < m + m + 2;i++){
        printf("%d ",sum[i]);
    }

    return 0;
}