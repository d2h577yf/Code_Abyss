
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

int find_prime_number(int i){
    if (i < 2) return 0;
    for (int j = 2; j * j <= i; j++) {
        if (i % j == 0) {
            return 0;
        }
    }
    return i;
}

int main(int argc, char *argv[])
{
    int M, N, sum = 0, cnt = 0;
    scanf("%d %d", &M, &N);

    if (M < 2) M = 2;
    
    for (int i = M; i <= N; i++) {
        int prime = find_prime_number(i);
        if (prime != 0) {
            sum += prime;
            cnt++;
        }
    }

    printf("%d %d\n", cnt, sum);

    return EXIT_SUCCESS;
}


