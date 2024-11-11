#include <stdio.h>
#include <math.h>

int n;

int main() {
    scanf("%d", &n);
    switch(n) {
        case 1: {
            printf("I love Luogu!\n");
            break;
        }
        case 2: {
            printf("%d %d\n", 2 + 4, 10 - 2 - 4);
            break;
        }
        case 3: {
            int a = 14 / 4;
            printf("%d\n", a);
            printf("%d\n", a * 4);
            printf("%d\n", 14 - a * 4);
            break;
        }
        case 4: {
            printf("%.6lf\n", 500.0 / 3);
            break;
        }
        case 5: {
            printf("%d\n", (260 + 220) / (12 + 20));
            break;
        }
        case 6: {
            double a = 6, b = 9;
            double c = sqrt(a * a + b * b);
            printf("%.6lf\n", c);
            break;
        }
        case 7: {
            int a = 100;
            a += 10;
            printf("%d\n", a);
            a -= 20;
            printf("%d\n", a);
            a = 0;
            printf("%d\n", a);
            break;
        }
        case 8: {
            int r = 5;
            double pi = 3.141593;
            printf("%.6lf\n", 2 * pi * r);
            printf("%.6lf\n", r * r * pi);
            printf("%.6lf\n", 4.0 / 3 * pi * r * r * r);
            break;
        }
        case 9: {
            printf("%d\n", (((1 + 1) * 2 + 1) * 2 + 1) * 2);
            break;
        }
        case 10: {
            printf("%d\n", 9);
            break;
        }
        case 11: {
            printf("%.6lf\n", 100.0 / (8 - 5));
            break;
        }
        case 12: {
            printf("%d\n", 'M' - 'A' + 1);
            printf("%c\n", 'A' - 1 + 18);
            break;
        }
        case 13: {
            int r1 = 4, r2 = 10;
            double pi = 3.141593;
            double v = 4.0 / 3 * pi * r1 * r1 * r1 + 4.0 / 3 * pi * r2 * r2 * r2;
            v = pow(v, 1.0 / 3);
            printf("%.0lf\n", v);
            break;
        }
        case 14: {
            printf("%d\n", 50);
            break;
        }
    }
    return 0;
}
