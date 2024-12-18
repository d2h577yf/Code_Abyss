#include <stdio.h>
#include <stdlib.h>

int checkHorSym(char **pA, int n) {
  for (int i = 0; i < n / 2; i++) {
    for (int j = 0; j < n; j++) {
      if (pA[i][j] != pA[n - i - 1][j]) {
        return 0;
      }
    }
  }
  return 1;
}

int checkVerSym(char **pA, int n) {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n / 2; j++) {
      if (pA[i][j] != pA[i][n - j - 1]) {
        return 0;
      }
    }
  }
  return 1;
}

int checkDiaSym(char **pA, int n) {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (i != j && pA[i][j] != pA[j][i]) {
        return 0;
      }
    }
  }
  return 1;
}

int checkAntiDiaSym(char **pA, int n) {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (i + j != n - 1 && pA[i][j] != pA[n - j - 1][n - i - 1]) {
        return 0;
      }
    }
  }
  return 1;
}

int checkRotSym(char **pA, int n) {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (pA[i][j] != pA[n - i - 1][n - j - 1]) {
        return 0;
      }
    }
  }
  return 1;
}

int main(void) {
  int n, i, j;
  int iHorSymFlag = 1, iVerSymFlag = 1, iDiaSymFlag = 1, iAntiDiaSymFlag = 1,
      iRotSymFlag = 1;
  char **pA, *pTmp1, *pTmp2;

  scanf("%d", &n);

  pA = (char **)malloc(sizeof(char *) * n);
  for (i = 0; i < n; i++) {
    pA[i] = (char *)malloc(sizeof(char) * n);
  }

  for (i = 0; i < n; i++) {
    pTmp1 = pA[i];
    for (j = 0; j < n; j++) {
      scanf("%c", pTmp1);

      while (*pTmp1 == ' ' || *pTmp1 == '\n') {
        scanf("%c", pTmp1);
      }
      pTmp1++;
    }
  }

  iHorSymFlag = checkHorSym(pA, n);
  iVerSymFlag = checkVerSym(pA, n);
  iDiaSymFlag = checkDiaSym(pA, n);
  iAntiDiaSymFlag = checkAntiDiaSym(pA, n);
  iRotSymFlag = checkRotSym(pA, n);

  if (iHorSymFlag)
    printf("1 ");
  if (iVerSymFlag)
    printf("2 ");
  if (iDiaSymFlag)
    printf("3 ");
  if (iAntiDiaSymFlag)
    printf("4 ");
  if (iRotSymFlag)
    printf("5 ");
  printf("\n");

  return 0;
}
