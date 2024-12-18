#include <stdio.h>

typedef struct 
{
    char ID[6];
    char name[11];
    int score1;
    int score2;
    int score3;
    int total;
} Student;

int main(int argc, char const *argv[])
{
    int n, flag = 0, num = -1;
    scanf("%d", &n);

    Student stu[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%s %s %d %d %d", stu[i].ID, stu[i].name, &stu[i].score1, &stu[i].score2, &stu[i].score3);
        stu[i].total = stu[i].score1 + stu[i].score2 + stu[i].score3;
        if (stu[i].total > num)
        {
            flag = i;
            num = stu[i].total;
        }
    }
    
    printf("%s %s %d\n", stu[flag].name, stu[flag].ID, stu[flag].total);

    return 0;
}
