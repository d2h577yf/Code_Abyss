#include <stdio.h>
#include <stdlib.h>

int checkHorSym(char **pA, int n);
int checkVerSym(char **pA, int n);
int checkDiaSym(char **pA, int n);
int checkAntiDiaSym(char **pA, int n);
int checkRotSym(char **pA, int n);

int main(void)
{
    int n,i,j,iHorSymFlag=1, iVerSymFlag=1, iDiaSymFlag=1, iAntiDiaSymFlag=1, iRotSymFlag=1;
    char **pA,*pTmp1,*pTmp2;
    scanf("%d", &n);

    pA=(char**) malloc(sizeof(char*)*n);
    for(i=0; i<n; i++)
    {
        pA[i]=(char*) malloc(sizeof(char)*n);
    }
    for(i=0; i<n; i++)
    {
        pTmp1=pA[i];
        for(j=0;j<n;j++)
        {
            scanf("%c", pTmp1);

            while(*pTmp1==' '|| *pTmp1=='\n')//skip spacing or line break
            {
                scanf("%c", pTmp1);
            }
            pTmp1++;
        }
    }



    //horizental symmetry
    iHorSymFlag = checkHorSym(pA, n);

    //vertical symmetry
    iVerSymFlag = checkVerSym(pA, n);

    //diagonal symmetry
    iDiaSymFlag = checkDiaSym(pA, n);


    //antidiagonal symmetry
    iAntiDiaSymFlag = checkAntiDiaSym(pA, n);

    //rotationally symmetry
    iRotSymFlag = checkRotSym(pA, n);

    if(iHorSymFlag)
        printf("1 ");
    if(iVerSymFlag)
        printf("2 ");
    if(iDiaSymFlag)
        printf("3 ");
    if(iAntiDiaSymFlag)
        printf("4 ");
    if(iRotSymFlag)
        printf("5 ");
    printf("\n");

    return 0;
}

int checkHorSym(char **pA, int n){
    int t,check = 1;
    t = n/2;
    for(int i = 0;i < n;i++){
        for(int j = 0;j < t;j++){
            if(pA[i][j] != pA[i][n - j - 1]){
                check = 0;
            }
        }
    } 
    return check; 
}
int checkVerSym(char **pA, int n){
    int t,check = 1;
    t = n/2;
    for(int i = 0;i < n;i++){
        for(int j = 0;j < t;j++){
            if(pA[i][j] != pA[n - i - 1][j]){
                check = 0;
            }
        }
    } 
    return check; 
}
int checkDiaSym(char **pA, int n){
    int check = 1;
    for(int i = 0;i < n;i++){
        for(int j = 0;j < n;j++){
            if(j > i){
                if(pA[i][j] != pA[j][i]){
                    check = 0;
                }
            }
        }
    }
    return check;
}
int checkAntiDiaSym(char **pA, int n){
    int check = 1;
    for(int i = 0;i <n;i++){
        for(int j = 0;j < n;j++){
            if(j < n - i - 1){
                if(pA[i][j] != pA[n-1-j][n-1-i]){
                    check = 0;
                }
            }
        }
    }
    return check;
}
int checkRotSym(char **pA, int n){
    int check = 1;
    for(int i = 0;i < n;i++){
        for(int j = 0;j < n;j++){
            if(pA[i][j] != pA[n-1-i][n-1-j]){
                check = 0;
            }
        }
    }
    return check;
}