#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define DEBUG_PRINT 0

struct MetroStation
{
    char Name[21];
    int lDistance;
    int rDistance;
    int iTransFlag;
    int iTransToLine;
    int iTransToStaNo;
};
struct MetroLine
{
    struct MetroStation aStation[30];
    int iStationNo;
    int iTransStationNo;
    int iTransStation[2];
    int iTransStationLine[2];
    int iTransStationLineNo[2];
};

enum routeTrans{
    NO_TRANS, ONE_TRANS, TWO_TRANS
};

int routePlanNoTrans(struct MetroLine aML[], int iSStationLine, int iSStationLineNo, int iDestStationLine, int iDestStationLineNo);//待实现 

int routePlanTransOnce(struct MetroLine aML[], int iSStationLine, int iSStationLineNo, int iDestStationLine, int iDestStationLineNo);//待实现 

void readAndRecordLineInfo(struct MetroLine aML[], int iLineNo)
{
    int i,j,m,n;
    for(i=0; i<iLineNo; i++)
    {
        scanf("%d", &(aML[i].iStationNo));


        for(j=0; j<aML[i].iStationNo-1; j++)
        {
            scanf("%s",aML[i].aStation[j].Name);
            scanf("%d",&(aML[i].aStation[j].rDistance));

            aML[i].aStation[j+1].lDistance = aML[i].aStation[j].rDistance;
        }
        scanf("%s",aML[i].aStation[aML[i].iStationNo-1].Name);
    }
    for(i=1; i<iLineNo; i++)
    {
        for(j=0; j<aML[i].iStationNo; j++)
        {
            for(m=0; m<i; m++)
            {
                for(n=0; n<aML[m].iStationNo; n++)
                {
                    if(!strcmp(aML[i].aStation[j].Name, aML[m].aStation[n].Name))
                    {
                        aML[i].aStation[j].iTransFlag=aML[m].aStation[n].iTransFlag=1;
                        aML[i].aStation[j].iTransToLine=m;
                        aML[m].aStation[n].iTransToLine=i;
                        aML[i].aStation[j].iTransToStaNo=n;
                        aML[m].aStation[n].iTransToStaNo=j;
                        aML[i].iTransStation[aML[i].iTransStationNo] = j;
                        aML[i].iTransStationLine[aML[i].iTransStationNo] = m;
                        aML[i].iTransStationLineNo[aML[i].iTransStationNo] = n;
                        aML[i].iTransStationNo++;
                        aML[m].iTransStation[aML[m].iTransStationNo] = n;
                        aML[m].iTransStationLine[aML[m].iTransStationNo] = i;
                        aML[m].iTransStationLineNo[aML[m].iTransStationNo] = j;
                        aML[m].iTransStationNo++;
                    }
                }
            }
        }
    }
#if DEBUG_PRINT
    for(i=0; i<iLineNo; i++)
    {
        printf("\n%dth: %d Stations, %dtrans: \n", i+1,aML[i].iStationNo, aML[i].iTransStationNo);
        for(j=0; j<aML[i].iTransStationNo; j++)
        {
            printf("  %dth Station to Line%d %dthStation\n",aML[i].iTransStation[j], aML[i].iTransStationLine[j]+1, aML[i].iTransStationLineNo[j]);
        }
        for(j=0; j<aML[i].iStationNo; j++)
            printf("%s %d %d %d %d %d\n", aML[i].aStation[j].Name, aML[i].aStation[j].lDistance,aML[i].aStation[j].rDistance, aML[i].aStation[j].iTransFlag, aML[i].aStation[j].iTransToLine, aML[i].aStation[j].iTransToStaNo);
    }
#endif
    return;
}

int distanceCalc(struct MetroLine aML[],int iLine, int iSStation, int iDStation)
{
    int i, iDistance=0;
#if DEBUG_PRINT
        printf("\nLine%d: %d to %d:\n", iLine+1, iSStation, iDStation);
        printf("\n%dth: -->%s %d / %dmeters\n", 0,aML[iLine].aStation[iSStation].Name, 0, iDistance);
#endif
    if(iSStation < iDStation)
    {
        for(i=iSStation; i<iDStation; i++)
        {
            iDistance += aML[iLine].aStation[i].rDistance;

#if DEBUG_PRINT
        printf("\n%dth: -->%s %d / %dmeters\n", i,aML[iLine].aStation[i+1].Name, aML[iLine].aStation[i].rDistance, iDistance);
#endif
        }
    }
    else if(iSStation > iDStation)
    {
        for(i=iSStation; i>iDStation; i--)
        {
            iDistance += aML[iLine].aStation[i].lDistance;

#if DEBUG_PRINT
        printf("\n%dth: -->%s %d / %dmeters\n", i,aML[iLine].aStation[i-1].Name, aML[iLine].aStation[i].lDistance, iDistance);
#endif
        }
    }else
    {
        iDistance = 0;
    }

    return iDistance;
}
int priceCalc(int iDistance)
{
    if(iDistance<0){
        printf("Error!\n");
        return -1;
    }
    if(iDistance==0)
        return 0;
    if(iDistance<=6000)
        return 2;
    if(iDistance>6000 && iDistance<=10000)
        return 3;
    if(iDistance>10000 && iDistance<=14000)
        return 4;
    if(iDistance>14000 && iDistance<=20000)
        return 5;
    if(iDistance>20000 && iDistance<=26000)
        return 6;
    return (7+(iDistance-26000)/8000);
}




int routePlanTransTwice(struct MetroLine aML[], int iSStationLine, int iSStationLineNo, int iDestStationLine, int iDestStationLineNo)
{
    int i,j,iSStationLine1, iSStationLineNo1, t, iLineFirst, iLineSecond, iLineThird, iTranStation[2], iCost=-2,iDistance=-1;//there should have zero or one plan by transfer twice.
    for(i=0; i<aML[iSStationLine].iTransStationNo; i++)//traverse transfer stations
    {
        t=aML[iSStationLine].iTransStationLine[i];
        for(j=0; j<aML[t].iTransStationNo; j++)
        {
             if(aML[t].iTransStationLine[j] == iDestStationLine)
            {
                if(aML[iSStationLine].iTransStation[i] == iSStationLineNo || aML[iSStationLine].iTransStationLineNo[i] == aML[t].iTransStation[j] || aML[t].iTransStationLineNo[j] == iDestStationLineNo)
                    continue;
                iLineFirst = iSStationLine;
                iLineSecond = t;
                iLineThird = iDestStationLine;
                iTranStation[0] = aML[iSStationLine].iTransStation[i];
                iTranStation[1] = aML[t].iTransStation[j];
#if DEBUG_PRINT
        printf("\na Find transfer twice plan: Line%d-Line%d-Line%d\n", iLineFirst+1, iLineSecond+1, iLineThird+1);
#endif
                //first interval
                iDistance = distanceCalc(aML, iLineFirst, iSStationLineNo, iTranStation[0]);
                //second interval
                iDistance += distanceCalc(aML, iLineSecond, aML[iLineFirst].iTransStationLineNo[i], aML[iLineSecond].iTransStation[j]);
                //third interval
                iDistance +=  distanceCalc(aML,iLineThird, aML[iLineSecond].iTransStationLineNo[j], iDestStationLineNo);
                iCost = priceCalc(iDistance);
                return iCost;
            }else if(aML[iDestStationLine].aStation[iDestStationLineNo].iTransFlag && aML[t].iTransStationLine[j]  == aML[iDestStationLine].aStation[iDestStationLineNo].iTransToLine)
            {
                if(aML[iSStationLine].iTransStation[i] == iSStationLineNo|| aML[iSStationLine].iTransStationLineNo[i] == aML[t].iTransStation[j]|| aML[t].iTransStationLineNo[j] == aML[iDestStationLine].aStation[iDestStationLineNo].iTransToStaNo)
                    continue;
                iLineFirst= iSStationLine;
                iLineSecond = t;
                iLineThird = aML[iDestStationLine].aStation[iDestStationLineNo].iTransToLine;
                iDestStationLine = iLineThird;
                iDestStationLineNo = aML[iDestStationLine].aStation[iDestStationLineNo].iTransToStaNo;
                iTranStation[0]= aML[iSStationLine].iTransStation[i];
                iTranStation[1] = aML[t].iTransStation[j];
#if DEBUG_PRINT
        printf("\b nFind transfer twice plan: Line%d-Line%d-Line%d\n", iLineFirst+1, iLineSecond+1, iLineThird+1);
#endif
                //first interval
                iDistance = distanceCalc(aML, iLineFirst, iSStationLineNo, iTranStation[0]);
                //second interval
                iDistance += distanceCalc(aML, iLineSecond, aML[iLineFirst].iTransStationLineNo[i], aML[iLineSecond].iTransStation[j]);
                //third interval
                iDistance +=  distanceCalc(aML,iLineThird, aML[iLineSecond].iTransStationLineNo[j], iDestStationLineNo);
                iCost = priceCalc(iDistance);
                return iCost;
            }
        }
    }
    if(aML[iSStationLine].aStation[iSStationLineNo].iTransFlag)//traverse the transfer stations on the other line
    {
        iSStationLine1 = aML[iSStationLine].aStation[iSStationLineNo].iTransToLine;
        iSStationLineNo1 = aML[iSStationLine].aStation[iSStationLineNo].iTransToStaNo;
        for(i=0; i<aML[iSStationLine1].iTransStationNo; i++)//traverse transfer stations
        {
            t=aML[iSStationLine1].iTransStationLine[i];
            for(j=0; j<aML[t].iTransStationNo; j++)
            {
                 if(aML[t].iTransStationLine[j] == iDestStationLine)
                {
                    if(aML[t].iTransStationLineNo[i] == iSStationLineNo|| aML[iSStationLine1].iTransStationLineNo[i] == aML[t].iTransStation[j]|| aML[t].iTransStationLineNo[j] == iDestStationLineNo)
                        continue;
                    iLineFirst = iSStationLine1;
                    iLineSecond = t;
                    iLineThird = iDestStationLine;
                    iTranStation[0] = aML[iSStationLine1].iTransStation[i];
                    iTranStation[1] = aML[t].iTransStation[j];
#if DEBUG_PRINT
        printf("\nc Find transfer twice plan: Line%d-Line%d-Line%d\n", iLineFirst+1, iLineSecond+1, iLineThird+1);
#endif
                    //first interval
                    iDistance = distanceCalc(aML, iLineFirst, iSStationLineNo1, iTranStation[0]);
                    //second interval
                    iDistance += distanceCalc(aML, iLineSecond, aML[iLineFirst].iTransStationLineNo[i], aML[iLineSecond].iTransStation[j]);
                    //third interval
                    iDistance +=  distanceCalc(aML,iLineThird, aML[iLineSecond].iTransStationLineNo[j], iDestStationLineNo);
                    iCost = priceCalc(iDistance);
                    return iCost;
                }else if(aML[iDestStationLine].aStation[iDestStationLineNo].iTransFlag && aML[t].iTransStationLine[j]  == aML[iDestStationLine].aStation[iDestStationLineNo].iTransToLine)
                {
                    if(aML[t].iTransStationLineNo[i] == iSStationLineNo|| aML[iSStationLine1].iTransStationLineNo[i] == aML[t].iTransStation[j]|| aML[t].iTransStationLineNo[j] == aML[iDestStationLine].aStation[iDestStationLineNo].iTransToStaNo)
                        continue;
                    iLineFirst= iSStationLine1;
                    iLineSecond = t;
                    iLineThird = aML[iDestStationLine].aStation[iDestStationLineNo].iTransToLine;
                    iDestStationLine = iLineThird;
                    iDestStationLineNo = aML[iDestStationLine].aStation[iDestStationLineNo].iTransToStaNo;
                    iTranStation[0]= aML[iSStationLine1].iTransStation[i];
                    iTranStation[1] = aML[t].iTransStation[j];
#if DEBUG_PRINT
        printf("\nd Find transfer twice plan: Line%d-Line%d-Line%d\n", iLineFirst+1, iLineSecond+1, iLineThird+1);
#endif
                    //first interval
                    iDistance = distanceCalc(aML, iLineFirst, iSStationLineNo1, iTranStation[0]);
                    //second interval
                    iDistance += distanceCalc(aML, iLineSecond, aML[iLineFirst].iTransStationLineNo[i], aML[iLineSecond].iTransStation[j]);
                    //third interval
                    iDistance +=  distanceCalc(aML,iLineThird, aML[iLineSecond].iTransStationLineNo[j], iDestStationLineNo);
                    iCost = priceCalc(iDistance);
                    return iCost;
                }
            }
        }
    }
    return -1;
}

int main(void)
{
    int iLineNo, i,j,iCost[3], iTransTimes=-1, iCostMin=10000,iPlanCnt=0;
    int iSStationLine, iSStationLineNo, iDestStationLine, iDestStationLineNo;
    char sSStation[21],sDestStation[21];
    struct MetroLine aML[3]={0};
    scanf("%d", &iLineNo);

    readAndRecordLineInfo(aML, iLineNo);

    scanf("%s",sSStation);
    scanf("%s",sDestStation);

    //Locate the stations
    for(i=0; i<iLineNo; i++)
    {
        for(j=0; j<aML[i].iStationNo; j++)
        {
            if(!strcmp(aML[i].aStation[j].Name, sSStation))
            {
                iSStationLine = i;
                iSStationLineNo = j;
#if DEBUG_PRINT
        printf("\nFind start station: Line%d %dth\n", iSStationLine, iSStationLineNo);
#endif
            }
            if(!strcmp(aML[i].aStation[j].Name, sDestStation))
            {
                iDestStationLine = i;
                iDestStationLineNo = j;
#if DEBUG_PRINT
        printf("\nFind destinate station: Line%d %dth\n", iDestStationLine, iDestStationLineNo);
#endif
            }
        }
    }

    //No Transfer?
    if(-1!=(iCost[0]=routePlanNoTrans(aML, iSStationLine, iSStationLineNo, iDestStationLine, iDestStationLineNo)))
    {
        iCostMin = iCost[0];
        iPlanCnt++;
        iTransTimes = NO_TRANS;
    }
    //Transfer once?
    if(-1!=(iCost[1]=routePlanTransOnce(aML, iSStationLine, iSStationLineNo, iDestStationLine, iDestStationLineNo)))
    {
        if(iPlanCnt)
        {
            if(iCostMin>iCost[1])
            {
                iCostMin = iCost[1];
                iTransTimes = ONE_TRANS;
            }
        }else
        {
            iCostMin = iCost[1];
            iTransTimes = ONE_TRANS;
        }
        iPlanCnt++;
    }
    //Transfer twice?
    if(-1!=(iCost[2]=routePlanTransTwice(aML, iSStationLine, iSStationLineNo, iDestStationLine, iDestStationLineNo)))
    {
        if(iPlanCnt)
        {
            if(iCostMin>iCost[2])
            {
                iCostMin = iCost[2];
                iTransTimes = TWO_TRANS;
            }
        }else
        {
            iCostMin = iCost[2];
            iTransTimes = TWO_TRANS;
        }
        iPlanCnt++;
    }

#if DEBUG_PRINT
    printf("%s --> %s %d transfers\n", sSStation, sDestStation, iTransTimes);
#endif


    printf("%d\n", iCostMin);

    return 0;
}

int routePlanNoTrans(struct MetroLine aML[], int iSStationLine, int iSStationLineNo, int iDestStationLine, int iDestStationLineNo){
    
}
int routePlanTransOnce(struct MetroLine aML[], int iSStationLine, int iSStationLineNo, int iDestStationLine, int iDestStationLineNo){

}