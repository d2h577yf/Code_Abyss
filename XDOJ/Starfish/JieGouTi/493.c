#include <stdio.h>
struct student{
    char number[6];
    char name[50];
    int score1,score2,score3,sum;
};
int main(){
    int n,record,max = -1;
    scanf("%d",&n);
    struct student stu[n];
    for(int i = 0;i < n;i++){
        scanf("%s %s %d %d %d",stu[i].number,stu[i].name,&stu[i].score1,&stu[i].score2,&stu[i].score3);
        stu[i].sum = stu[i].score1 + stu[i].score2 + stu[i].score3;
        if(stu[i].sum > max){
            max = stu[i].sum;
            record = i;
        }
    }
    printf("%s %s %d",stu[record].name,stu[record].number,stu[record].sum);
    return 0;
}