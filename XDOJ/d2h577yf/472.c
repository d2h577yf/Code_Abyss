#include <stdio.h>
#include <string.h>

struct medalCountry {
  int iPlace;
  char sName[3];
  int iMedalNum[3];
};

enum medalType { GOLDMEDAL, SILVERMEDAL, BRONZEMEDAL };

void AdjustSortTable(int aSortTable[], struct medalCountry aMedalCountry[],
                     int iCounter, int iNo, int iMedalType) {
  int i, j, temp;

  // 调整奖牌榜的索引数组aSortTable
  // 使用冒泡排序
  for (j = 0; j < iCounter - 1; j++)
    for (i = 0; i < iCounter - j - 1; i++) {
      if (aMedalCountry[aSortTable[i + 1]].iMedalNum[GOLDMEDAL] >
              aMedalCountry[aSortTable[i]].iMedalNum[GOLDMEDAL] ||
          (aMedalCountry[aSortTable[i + 1]].iMedalNum[GOLDMEDAL] ==
               aMedalCountry[aSortTable[i]].iMedalNum[GOLDMEDAL] &&
           (aMedalCountry[aSortTable[i + 1]].iMedalNum[SILVERMEDAL] >
                aMedalCountry[aSortTable[i]].iMedalNum[SILVERMEDAL] ||
            (aMedalCountry[aSortTable[i + 1]].iMedalNum[SILVERMEDAL] ==
                 aMedalCountry[aSortTable[i]].iMedalNum[SILVERMEDAL] &&
             (aMedalCountry[aSortTable[i + 1]].iMedalNum[BRONZEMEDAL] >
                  aMedalCountry[aSortTable[i]].iMedalNum[BRONZEMEDAL] ||
              (aMedalCountry[aSortTable[i + 1]].iMedalNum[BRONZEMEDAL] ==
                   aMedalCountry[aSortTable[i]].iMedalNum[BRONZEMEDAL] &&
               strcmp(aMedalCountry[aSortTable[i + 1]].sName,
                      aMedalCountry[aSortTable[i]].sName) <
                   0)))))) // 又臭又长的判断
      {
        temp = aSortTable[i + 1];
        aSortTable[i + 1] = aSortTable[i];
        aSortTable[i] = temp;
      }
    }
}

int main(void) {
  int n, i, j, counter = 0;
  struct medalCountry aMedalCountry[206] = {0};
  struct medalCountry *pSMC;
  int aSortTable[206];
  char sNameTmp[3];

  scanf("%d", &n);
  for (i = 0; i < n; i++) {
    // Gold Medal
    scanf("%s", sNameTmp);
    for (j = 0; j < counter; j++) {
      if (!strcmp(aMedalCountry[j].sName, sNameTmp)) {
        aMedalCountry[j].iMedalNum[GOLDMEDAL]++;
        AdjustSortTable(aSortTable, aMedalCountry, counter, j, GOLDMEDAL);
        break;
      }
    }
    if (j == counter) {
      strcpy(aMedalCountry[j].sName, sNameTmp);
      aMedalCountry[j].iMedalNum[GOLDMEDAL]++;
      aSortTable[j] = j;
      counter++;
      AdjustSortTable(aSortTable, aMedalCountry, counter, j, GOLDMEDAL);
    }

    // Silver Medal
    scanf("%s", sNameTmp);
    for (j = 0; j < counter; j++) {
      if (!strcmp(aMedalCountry[j].sName, sNameTmp)) {
        aMedalCountry[j].iMedalNum[SILVERMEDAL]++;
        AdjustSortTable(aSortTable, aMedalCountry, counter, j, SILVERMEDAL);
        break;
      }
    }
    if (j == counter) {
      strcpy(aMedalCountry[j].sName, sNameTmp);
      aMedalCountry[j].iMedalNum[SILVERMEDAL]++;
      aSortTable[j] = j;
      counter++;
      AdjustSortTable(aSortTable, aMedalCountry, counter, j, SILVERMEDAL);
    }

    // Bronze Medal
    scanf("%s", sNameTmp);
    for (j = 0; j < counter; j++) {
      if (!strcmp(aMedalCountry[j].sName, sNameTmp)) {
        aMedalCountry[j].iMedalNum[BRONZEMEDAL]++;
        AdjustSortTable(aSortTable, aMedalCountry, counter, j, BRONZEMEDAL);
        break;
      }
    }
    if (j == counter) {
      strcpy(aMedalCountry[j].sName, sNameTmp);
      aMedalCountry[j].iMedalNum[BRONZEMEDAL]++;
      aSortTable[j] = j;
      counter++;
      AdjustSortTable(aSortTable, aMedalCountry, counter, j, BRONZEMEDAL);
    }
  }

  for (i = 0; i < counter; i++) {
    aMedalCountry[aSortTable[i]].iPlace = i;
    pSMC = aMedalCountry + aSortTable[i];
    printf("%3d %3s %3d %3d %3d\n", pSMC->iPlace + 1, pSMC->sName,
           pSMC->iMedalNum[GOLDMEDAL], pSMC->iMedalNum[SILVERMEDAL],
           pSMC->iMedalNum[BRONZEMEDAL]);
  }

  return 0;
}
