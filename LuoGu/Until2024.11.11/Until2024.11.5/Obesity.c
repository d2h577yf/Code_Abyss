#include <assert.h>
#include <errno.h>
#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  double m, h, bmi;
  scanf("%lf %lf", &m, &h);

  bmi = m / pow(h, 2);

  if (bmi < 18.5) {
    printf("Underweight\n");
  } else if (bmi < 24) {
    printf("Normal\n");
  } else {
    printf("%.6g\nOverweight", bmi);
  }

  return EXIT_SUCCESS;
}
