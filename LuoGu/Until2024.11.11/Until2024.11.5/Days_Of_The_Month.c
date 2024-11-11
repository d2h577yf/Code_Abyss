#include <assert.h>
#include <errno.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int get_day_of_month(int year, int month) {
  struct tm timeinfo = {0};

  // 设置年份、月份和日期为当前月的第一天
  timeinfo.tm_year = year - 1900;
  timeinfo.tm_mon = month - 1; // 需要减1，因为tm_mon的范围是0-11
  timeinfo.tm_mday = 1;        // 设置为1号

  time_t current_month_time = mktime(&timeinfo);

  timeinfo.tm_mon += 1;

  time_t next_month_time = mktime(&timeinfo);

  return (next_month_time - current_month_time) / (60 * 60 * 24); // 以天为单位
}

int main(int argc, char *argv[]) {
  int year, month;
  scanf("%d %d", &year, &month);

  printf("%d", get_day_of_month(year, month));
  return EXIT_SUCCESS;
}
