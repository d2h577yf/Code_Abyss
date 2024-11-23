
#include <ctype.h>
#include <stdio.h>
#include <string.h>

void toUpper(char *str) {
  for (int i = 0; str[i] != '\0'; i++) {
    str[i] = toupper((unsigned char)str[i]);
  }
}

void removeNewline(char *str) {
  int len = strlen(str);
  if (len > 0 && str[len - 1] == '\n') {
    str[len - 1] = '\0';
  }
}

int main() {
  char s1[120] = {0}, s2[120] = {0}, t[120] = {0};
  int slen, llen, a[105] = {0}, i, j, times = 0, k, lcs = 0;

  fgets(s1, sizeof(s1), stdin);
  fgets(s2, sizeof(s2), stdin);
  removeNewline(s1);
  removeNewline(s2);

  toUpper(s1);
  toUpper(s2);

  llen = (strlen(s1) >= strlen(s2) ? strlen(s1) : strlen(s2));
  slen = (strlen(s1) < strlen(s2) ? strlen(s1) : strlen(s2));
  if (strlen(s1) < strlen(s2)) {
    strcpy(t, s1);
    strcpy(s1, s2);
    strcpy(s2, t);
  }

  for (i = 0; i < slen; i++) {
    for (j = 0; j < llen; j++) {
      if (s2[i] == s1[j]) {
        for (k = j; k < llen; k++) {
          if (s1[k] == s2[i + times]) {
            times++;
            if (times + i == slen) {
              break;
            }
          } else {
            break;
          }
        }
        a[times]++;
        times = 0;
      }
    }
  }

  for (i = slen; i >= 0; i--) {
    if (a[i] != 0) {
      lcs = i;
      break;
    }
  }

  float xsd = 2.0 * lcs / (slen + llen);
  printf("%.3f\n", xsd);

  return 0;
}
