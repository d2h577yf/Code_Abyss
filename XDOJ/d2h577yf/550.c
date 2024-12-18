#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DEBUG_PRINT 0

struct MetroStation {
  char Name[21];
  int lDistance;
  int rDistance;
  int iTransFlag;
  int iTransToLine;
  int iTransToStaNo;
};

struct MetroLine {
  struct MetroStation aStation[30];
  int iStationNo;
  int iTransStationNo;
  int iTransStation[2];
  int iTransStationLine[2];
  int iTransStationLineNo[2];
};

enum routeTrans { NO_TRANS, ONE_TRANS, TWO_TRANS };

int routePlanNoTrans(struct MetroLine aML[], int iSStationLine,
                     int iSStationLineNo, int iDestStationLine,
                     int iDestStationLineNo) {

}; // Forward declaration

int routePlanTransOnce(struct MetroLine aML[], int iSStationLine,
                       int iSStationLineNo, int iDestStationLine,
                       int iDestStationLineNo); // Forward declaration

void readAndRecordLineInfo(struct MetroLine aML[], int iLineNo) {
  int i, j, m, n;
  for (i = 0; i < iLineNo; i++) {
    scanf("%d", &(aML[i].iStationNo));

    for (j = 0; j < aML[i].iStationNo - 1; j++) {
      scanf("%s", aML[i].aStation[j].Name);
      scanf("%d", &(aML[i].aStation[j].rDistance));

      aML[i].aStation[j + 1].lDistance = aML[i].aStation[j].rDistance;
    }
    scanf("%s", aML[i].aStation[aML[i].iStationNo - 1].Name);
  }

  for (i = 1; i < iLineNo; i++) {
    for (j = 0; j < aML[i].iStationNo; j++) {
      for (m = 0; m < i; m++) {
        for (n = 0; n < aML[m].iStationNo; n++) {
          if (!strcmp(aML[i].aStation[j].Name, aML[m].aStation[n].Name)) {
            aML[i].aStation[j].iTransFlag = aML[m].aStation[n].iTransFlag = 1;
            aML[i].aStation[j].iTransToLine = m;
            aML[m].aStation[n].iTransToLine = i;
            aML[i].aStation[j].iTransToStaNo = n;
            aML[m].aStation[n].iTransToStaNo = j;
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
  for (i = 0; i < iLineNo; i++) {
    printf("\n%dth: %d Stations, %dtrans: \n", i + 1, aML[i].iStationNo,
           aML[i].iTransStationNo);
    for (j = 0; j < aML[i].iTransStationNo; j++) {
      printf("  %dth Station to Line%d %dthStation\n", aML[i].iTransStation[j],
             aML[i].iTransStationLine[j] + 1, aML[i].iTransStationLineNo[j]);
    }
    for (j = 0; j < aML[i].iStationNo; j++) {
      printf("%s %d %d %d %d %d\n", aML[i].aStation[j].Name,
             aML[i].aStation[j].lDistance, aML[i].aStation[j].rDistance,
             aML[i].aStation[j].iTransFlag, aML[i].aStation[j].iTransToLine,
             aML[i].aStation[j].iTransToStaNo);
    }
  }
#endif
}

int distanceCalc(struct MetroLine aML[], int iLine, int iSStation,
                 int iDStation) {
  int i, iDistance = 0;

#if DEBUG_PRINT
  printf("\nLine%d: %d to %d:\n", iLine + 1, iSStation, iDStation);
  printf("\n%dth: -->%s %d / %dmeters\n", 0,
         aML[iLine].aStation[iSStation].Name, 0, iDistance);
#endif

  if (iSStation < iDStation) {
    for (i = iSStation; i < iDStation; i++) {
      iDistance += aML[iLine].aStation[i].rDistance;

#if DEBUG_PRINT
      printf("\n%dth: -->%s %d / %dmeters\n", i,
             aML[iLine].aStation[i + 1].Name, aML[iLine].aStation[i].rDistance,
             iDistance);
#endif
    }
  } else if (iSStation > iDStation) {
    for (i = iSStation; i > iDStation; i--) {
      iDistance += aML[iLine].aStation[i].lDistance;

#if DEBUG_PRINT
      printf("\n%dth: -->%s %d / %dmeters\n", i,
             aML[iLine].aStation[i - 1].Name, aML[iLine].aStation[i].lDistance,
             iDistance);
#endif
    }
  } else {
    iDistance = 0;
  }

  return iDistance;
}

int priceCalc(int iDistance) {
  if (iDistance < 0) {
    printf("Error!\n");
    return -1;
  }
  if (iDistance == 0)
    return 0;
  if (iDistance <= 6000)
    return 2;
  if (iDistance > 6000 && iDistance <= 10000)
    return 3;
  if (iDistance > 10000 && iDistance <= 14000)
    return 4;
  if (iDistance > 14000 && iDistance <= 20000)
    return 5;
  if (iDistance > 20000 && iDistance <= 26000)
    return 6;
  return (7 + (iDistance - 26000) / 8000);
}

int routePlanTransTwice(struct MetroLine aML[], int iSStationLine,
                        int iSStationLineNo, int iDestStationLine,
                        int iDestStationLineNo) {
  int i, j, iSStationLine1, iSStationLineNo1, t, iLineFirst, iLineSecond,
      iLineThird, iTranStation[2],
      iCost = -2,
      iDistance = -1; // there should have zero or one plan by transfer twice.

  for (i = 0; i < aML[iSStationLine].iTransStationNo;
       i++) // traverse transfer stations
  {
    t = aML[iSStationLine].iTransStationLine[i];
    for (j = 0; j < aML[t].iTransStationNo; j++) {
      if (aML[t].iTransStationLine[j] == iDestStationLine) {
        if (aML[iSStationLine].iTransStation[i] == iSStationLineNo ||
            aML[iSStationLine].iTransStationLineNo[i] ==
                aML[t].iTransStation[j] ||
            aML[t].iTransStationLineNo[j] == iDestStationLineNo)
          continue;
        iLineFirst = iSStationLine;
        iLineSecond = t;
        iLineThird = iDestStationLine;
        iTranStation[0] = aML[iSStationLine].iTransStation[i];
        iTranStation[1] = aML[t].iTransStation[j];

#if DEBUG_PRINT
        printf("\na Find transfer twice plan: Line%d-Line%d-Line%d\n",
               iLineFirst + 1, iLineSecond + 1, iLineThird + 1);
#endif

        // first interval
        iDistance =
            distanceCalc(aML, iLineFirst, iSStationLineNo, iTranStation[0]);
        // second interval
        iDistance += distanceCalc(aML, iLineSecond,
                                  aML[iLineFirst].iTransStationLineNo[i],
                                  aML[iLineSecond].iTransStation[j]);
        // third interval
        iDistance += distanceCalc(aML, iLineThird,
                                  aML[iLineSecond].iTransStationLineNo[j],
                                  iDestStationLineNo);
        iCost = priceCalc(iDistance);
        return iCost;
      } else if (aML[iDestStationLine]
                     .aStation[iDestStationLineNo]
                     .iTransFlag == 0) {
        continue;
      }
    }
  }

  return iCost;
}

int routePlan(struct MetroLine aML[], int iSStationLine, int iSStationLineNo,
              int iDestStationLine, int iDestStationLineNo) {
  int i, iCost = -1;
  iCost = routePlanNoTrans(aML, iSStationLine, iSStationLineNo,
                           iDestStationLine, iDestStationLineNo);
  if (iCost == -1) {
    iCost = routePlanTransOnce(aML, iSStationLine, iSStationLineNo,
                               iDestStationLine, iDestStationLineNo);
    if (iCost == -1) {
      iCost = routePlanTransTwice(aML, iSStationLine, iSStationLineNo,
                                  iDestStationLine, iDestStationLineNo);
    }
  }
  return iCost;
}

int main() {
  struct MetroLine aML[5];
  int iLineNo, iSStationLine, iSStationLineNo, iDestStationLine,
      iDestStationLineNo, iCost;

  scanf("%d", &iLineNo);
  readAndRecordLineInfo(aML, iLineNo);
  scanf("%d %d", &iSStationLine, &iSStationLineNo);
  scanf("%d %d", &iDestStationLine, &iDestStationLineNo);

  iCost = routePlan(aML, iSStationLine - 1, iSStationLineNo - 1,
                    iDestStationLine - 1, iDestStationLineNo - 1);

  if (iCost == -1) {
    printf("No route available\n");
  } else {
    printf("The minimum cost is: %d\n", iCost);
  }

  return 0;
}
