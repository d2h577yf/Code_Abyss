#include <stdio.h>
#include <string.h>

struct medalCountry{
    int iPlace;
    char sName[3];
    int iMedalNum[3];
};

enum medalType{ GOLDMEDAL , SILVERMEDAL, BRONZEMEDAL};


void AdjustSortTable(int aSortTable[],struct medalCountry aMedalCountry[], int iCounter, int iNo, int iMedalType);

int main(void)
{
    int n,i,j,counter=0;
    struct medalCountry aMedalCountry[206]={0};
    struct medalCountry *pSMC;
    int aSortTable[206];
    char sNameTmp[3];
    scanf("%d",&n);
    for(i=0; i<n; i++)
    {
        //Gold Medal
        scanf("%s",sNameTmp);
        for(j=0; j<counter;j++)
        {
            if(!strcmp(aMedalCountry[j].sName, sNameTmp))
            {
                aMedalCountry[j].iMedalNum[GOLDMEDAL]++;
                AdjustSortTable(aSortTable, aMedalCountry, counter, j, GOLDMEDAL);
                break;
            }
        }
        if(j==counter)
        {
            strcpy(aMedalCountry[j].sName, sNameTmp);
            aMedalCountry[j].iMedalNum[GOLDMEDAL]++;
            aSortTable[j]=j;
            counter++;
            AdjustSortTable(aSortTable, aMedalCountry, counter, j, GOLDMEDAL);
        }

        //Silver Medal
        scanf("%s",sNameTmp);
        for(j=0; j<counter;j++)
        {
            if(!strcmp(aMedalCountry[j].sName, sNameTmp))
            {
                aMedalCountry[j].iMedalNum[SILVERMEDAL]++;
                AdjustSortTable(aSortTable, aMedalCountry, counter, j, SILVERMEDAL);
                break;
            }
        }
        if(j==counter)
        {
            strcpy(aMedalCountry[j].sName, sNameTmp);
            aMedalCountry[j].iMedalNum[SILVERMEDAL]++;
            aSortTable[j]=j;
            counter++;
            AdjustSortTable(aSortTable, aMedalCountry, counter, j, SILVERMEDAL);
        }

        //Bronze Medal
        scanf("%s",sNameTmp);
        for(j=0; j<counter;j++)
        {
            if(!strcmp(aMedalCountry[j].sName, sNameTmp))
            {
                aMedalCountry[j].iMedalNum[BRONZEMEDAL]++;
                AdjustSortTable(aSortTable, aMedalCountry, counter, j, BRONZEMEDAL);
                break;
            }
        }
        if(j==counter)
        {
            strcpy(aMedalCountry[j].sName, sNameTmp);
            aMedalCountry[j].iMedalNum[BRONZEMEDAL]++;
            aSortTable[j]=j;
            counter++;
            AdjustSortTable(aSortTable, aMedalCountry, counter, j, BRONZEMEDAL);
        }
    }

    for(i=0; i<counter; i++)
    {
        aMedalCountry[aSortTable[i]].iPlace = i;
        pSMC=aMedalCountry+aSortTable[i];
        printf("%3d %3s %3d %3d %3d\n", pSMC->iPlace+1, pSMC->sName, pSMC->iMedalNum[GOLDMEDAL], pSMC->iMedalNum[SILVERMEDAL], pSMC->iMedalNum[BRONZEMEDAL]);
    }

    return 0;
}
void AdjustSortTable(int aSortTable[],struct medalCountry aMedalCountry[], int iCounter, int iNo, int iMedalType){
    struct medalCountry temple;
    for(int i = 1;i < iCounter;i++){
        for(int j = 0;j < iCounter - i;j++){
            if(aMedalCountry[aSortTable[j]].iMedalNum[0] < aMedalCountry[aSortTable[j+1]].iMedalNum[0]){
                temple = aMedalCountry[j];
                aMedalCountry[j] = aMedalCountry[j+1];
                aMedalCountry[j+1] = temple;
            }else if (aMedalCountry[aSortTable[j]].iMedalNum[0] == aMedalCountry[aSortTable[j+1]].iMedalNum[0]){
                if(aMedalCountry[aSortTable[j]].iMedalNum[1] < aMedalCountry[aSortTable[j+1]].iMedalNum[1]){
                    temple = aMedalCountry[j];
                    aMedalCountry[j] = aMedalCountry[j+1];
                    aMedalCountry[j+1] = temple;
                }else if (aMedalCountry[aSortTable[j]].iMedalNum[1] == aMedalCountry[aSortTable[j+1]].iMedalNum[1]){
                    if(aMedalCountry[aSortTable[j]].iMedalNum[2] < aMedalCountry[aSortTable[j+1]].iMedalNum[2]){
                        temple = aMedalCountry[j];
                        aMedalCountry[j] = aMedalCountry[j+1];
                        aMedalCountry[j+1] = temple;
                    }else if (aMedalCountry[aSortTable[j]].iMedalNum[2] == aMedalCountry[aSortTable[j+1]].iMedalNum[2]){
                        if(aMedalCountry[aSortTable[j]].sName[0] > aMedalCountry[aSortTable[j+1]].sName[0]){
                            temple = aMedalCountry[j];
                            aMedalCountry[j] = aMedalCountry[j+1];
                            aMedalCountry[j+1] = temple;
                        }else if (aMedalCountry[aSortTable[j]].sName[0] == aMedalCountry[aSortTable[j+1]].sName[0]){
                            if(aMedalCountry[aSortTable[j]].sName[1] > aMedalCountry[aSortTable[j+1]].sName[0]){
                                temple = aMedalCountry[j];
                                aMedalCountry[j] = aMedalCountry[j+1];
                                aMedalCountry[j+1] = temple;
                            }else if(aMedalCountry[aSortTable[j]].sName[1] == aMedalCountry[aSortTable[j+1]].sName[1]){
                                if(aMedalCountry[aSortTable[j]].sName[2] > aMedalCountry[aSortTable[j+1]].sName[2]){
                                    temple = aMedalCountry[j];
                                    aMedalCountry[j] = aMedalCountry[j+1];
                                    aMedalCountry[j+1] = temple;
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}