#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

void compera(int arr[],int start,int end){
  if(start>=end){
    return;
  }

  int minIndex = start;
  for (int i = start;i<end;i++) {
    if(arr[minIndex]>=arr[i]){
      minIndex = i; 
    }
  }

  if (minIndex != start) {
    int temp = arr[start];
    arr[start] = arr[minIndex];
    arr[minIndex]=temp;
  }

  compera(arr,start+1,end);
}

int main(int argc, char *argv[])
{
  int arr[3];
  for (int i = 0 ;i<3;i++) {
    scanf("%d",&arr[i]);
  }

  compera(arr,0,3);
  
  for (int i =0 ;i<2;i++) {
    printf("%d ",arr[i]);
  }
  printf("%d\n",arr[2]);

  return EXIT_SUCCESS;
}
