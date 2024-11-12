
#include <assert.h>
#include <ctype.h>
#include <errno.h>
#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
  char s1[100] = {0}, s2[100] = {0};
  int len1, len2, lcs = 0;
  double same_rate = 0;

  if (fgets(s1, sizeof(s1), stdin) == NULL ||
      fgets(s2, sizeof(s2), stdin) == NULL) {
    return EXIT_FAILURE;
  }

  s1[strcspn(s1, "\n")] = '\0';
  s2[strcspn(s2, "\n")] = '\0';

  len1 = strlen(s1);
  len2 = strlen(s2);

  for (int i = 0; i < len1; i++) {
    s1[i] = tolower(s1[i]);
  }
  for (int i = 0; i < len2; i++) {
    s2[i] = tolower(s2[i]);
  }

  if (len1 < len2) {
    char temp[100];
    strcpy(temp, s1);
    strcpy(s1, s2);
    strcpy(s2, temp);

    int temp_len = len1;
    len1 = len2;
    len2 = temp_len;
  }

  int dp[101][101] = {0};
  for (int i = 1; i <= len1; i++) {
    for (int j = 1; j <= len2; j++) {
      if (s1[i - 1] == s2[j - 1]) {
        dp[i][j] = dp[i - 1][j - 1] + 1;
        if (dp[i][j] > lcs) {
          lcs = dp[i][j];
        }
      }
    }
  }

  same_rate = (double)(2 * lcs) / (len1 + len2);
  printf("%.3f\n", round(same_rate * 1000) / 1000);

  return EXIT_SUCCESS;
}
