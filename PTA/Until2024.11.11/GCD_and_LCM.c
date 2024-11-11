#include <stdio.h>

int gcd(int a, int b) {
    while (b != 0) {
        int r = a % b;
        a = b;
        b = r;
    }
    return a;
}

int lcm(int a, int b) {
    return (a * b) / gcd(a, b);
}

int main() {
    int M, N;

    scanf("%d %d", &M, &N);

    int GCD = gcd(M, N);
    int LCM = lcm(M, N);

    printf("%d %d\n", GCD, LCM);

    return 0;
}
