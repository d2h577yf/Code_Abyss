#include <stdio.h>
int main(){
    int n,m,cnt = 0;
    double r,amount,sum,t,ex;
    scanf("%d %d %lf",&n,&m,&r);
    amount = n * r;
    if(amount < 1.0){
        amount = 1.0;
    }
    struct student{
        char number[6];
        char name [15];
        int lesson[105];
        double score[105];
        double check;
    };
    struct student stu[n];
    struct student temple;
    for(int i = 0;i < n;i++){
        scanf("%s %s ",stu[i].number,stu[i].name);
        for(int j = 0;j < m;j++){
            scanf("%d %lf",&stu[i].lesson[j],&stu[i].score[j]);
        }
        scanf("%lf",&ex);
        sum = 0;
        t = 0;
        for(int j = 0;j < m;j++){
            sum = sum + stu[i].lesson[j] * stu[i].score[j];
            t += stu[i].score[j];
        }
        sum /= t;
        stu[i].check = sum + ex;
        for(int j = 0;j < m;j++){
            if(stu[i].lesson[j] < 60){
                stu[i].check = 0;
                cnt++;
                break;
            }
        }
    }
    for(int i = 1;i < n;i++){
        for(int j = 0;j < n - i;j++){
            if(stu[j].check < stu[j+1].check){
                temple = stu[j];
                stu[j] = stu[j+1];
                stu[j+1] = temple;
            }
        }
    }
    for(int i = 0;i < n - cnt && i < amount;i++){
        printf("%s %s %.3f\n",stu[i].number,stu[i].name,stu[i].check);
    }
    return 0; 
}