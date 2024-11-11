#include <stdio.h>
#include <stdlib.h>

int find_start_position(int arr[], int size, int min_sum, int max_length) {
    int a1 = (double)min_sum/max_length-(max_length-1)*(1.0/2);

    for (int i = 0; i < size; i++) {
        if (arr[i] == a1) {
            return i;
        }
    }

    return -1;
}


int main(int argc, char *argv[])
{
    int N, cnt = 0;
    
    scanf("%d", &N);

    if (N < 2) {
        printf("%d\n", 0);
        return 0; 
    }

    for (int i = 2; i <= N; i++) {
        if (N % i == 0) { 
            cnt++;
        }
    }

    int s[cnt];
    int index = 0; 

    for (int i = 2; i <= N; i++) {
        if (N % i == 0) { 
            s[index++] = i; 
        }
    }
    
    
    int start=0,max_length=0,max_start=0,sum,min_sum=0;

    for (int i = 1; i <= cnt; i++) {
        if (i == cnt || s[i] != s[i - 1] + 1) {
            int length = i - start; 
            sum = 0;

            for (int j = start; j < i; j++) {
                sum += s[j];
            }

            if (length > max_length) {
                max_length = length;
                max_start = start;
                min_sum = sum; 
            } else if (length == max_length && sum < min_sum) {
                min_sum = sum;
                max_start = start; 
            }

            start = i;
        }
    }

    int min_start = find_start_position(s,cnt,min_sum,max_length);

    printf("%d\n", max_length);
    
    for (int i = min_start; i < min_start + max_length - 1; i++) {
        printf("%d*", s[i]);
    }
    printf("%d\n", s[min_start+ max_length - 1]);
    
  
    return EXIT_SUCCESS;
}
