#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 1000002

void to_lowercase(char *str) {
  for (int i = 0; str[i] != '\0'; ++i) {
    str[i] = tolower(str[i]);
  }
}

void read_string(char *str) {
  int i = 0;
  char c;
  while ((c = getchar()) != '\n' && c != EOF) {
    str[i++] = c;
  }
  str[i] = '\0';
  to_lowercase(str);
}

int main() {
  char target[11];
  scanf("%s", target);
  to_lowercase(target);

  char article[MAX_LEN];
  getchar();
  read_string(article);

  int cnt = 0, first = -1;
  char *p = article;
  int target_len = strlen(target);

  while ((p = strstr(p, target)) != NULL) {
    if ((p == article || !isalpha(p[-1])) &&
        (p[target_len] == '\0' || !isalpha(p[target_len]))) {
      cnt++;
      if (first == -1) {
        first = p - article;
      }
    }
    p++;
  }

  if (cnt == 0) {
    printf("-1\n");
  } else {
    printf("%d %d\n", cnt, first);
  }

  return EXIT_SUCCESS;
}
