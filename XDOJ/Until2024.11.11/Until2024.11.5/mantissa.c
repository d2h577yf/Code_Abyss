#include <stdio.h>

int factor_sum(int x) {
    int sum = 0;
    for (int i = 1; i < x; i++)
        if (x % i == 0) sum += i;
    return sum;
}

int main() {
    int a, b;
    scanf("%d %d", &a, &b);
    for (int i = a; i <= b; i++)
        if (factor_sum(i) == i) printf("%d\n", i);
    return 0;
}
