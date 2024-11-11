#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

void arrange(int arr[], int start, int end) {
    if (start >= end) {
        return;
    }

    int minIndex = start;
    
    for (int i = start + 1; i < end; i++) {
        if (arr[i] < arr[minIndex]) { 
            minIndex = i;
        }
    }
    
    if (minIndex != start) {
        int temp = arr[start];
        arr[start] = arr[minIndex];
        arr[minIndex] = temp;
    }

    arrange(arr, start + 1, end);
}

int main(int argc, char *argv[]) {
    int n,judge;
    scanf("%d", &n);
    int arr[n];

    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    arrange(arr, 0, n);
    
    for (int i = 0; i < n-3; i++) {
      if((arr[i]-arr[i+1])!=(arr[i+2]-arr[i+3]))
    {
      judge =0;
    }else {
      judge=1;
    }
    }

  if (judge) {
    printf("%d\n",arr[1]-arr[0]);
  }else {
    printf("no\n");
  }


    return EXIT_SUCCESS;
}

