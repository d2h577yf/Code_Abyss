#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    scanf("%d", &n);
    
    int day[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &day[i]);
    }

    int max_fluctuation = 0;
    for (int i = 1; i < n; i++) {
        int fluctuation = abs(day[i] - day[i - 1]);
        if (fluctuation > max_fluctuation) {
            max_fluctuation = fluctuation;
        }
    }

    printf("%d\n", max_fluctuation);
    return 0;
}
