
#include <assert.h>
#include <errno.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  double q1, q2, q3, q4, R[3][3];

  scanf("%lf,%lf,%lf,%lf", &q1, &q2, &q3, &q4);

  double q1_sq = q1 * q1;
  double q2_sq = q2 * q2;
  double q3_sq = q3 * q3;
  double q4_sq = q4 * q4;

  R[0][0] = q1_sq + q2_sq - q3_sq - q4_sq;
  R[0][1] = 2 * (q2 * q3 - q1 * q4);
  R[0][2] = 2 * (q2 * q4 + q1 * q3);
  R[1][0] = 2 * (q2 * q3 + q1 * q4);
  R[1][1] = q1_sq - q2_sq + q3_sq - q4_sq;
  R[1][2] = 2 * (q3 * q4 - q1 * q2);
  R[2][0] = 2 * (q2 * q4 - q1 * q3);
  R[2][1] = 2 * (q3 * q4 + q1 * q2);
  R[2][2] = q1_sq - q2_sq - q3_sq + q4_sq;

  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      printf("%f ", R[i][j]);
    }
    printf("\n");
  }

  return EXIT_SUCCESS;
}
