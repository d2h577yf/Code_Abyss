#include <stdio.h>

void yanghui(int beforeArr[],int begin,int n){
    if (begin>n)
    {
        return;
    }
    
    
    int arr[begin];
    arr[0]=1;
    arr[begin-1]=1;
    for (int  i = 0; i < begin-2; i++)
    {
        arr[i+1]= beforeArr[i]+beforeArr[i+1];
    }
    for (int i = 0; i < begin; i++)
    {
        printf("%d ",arr[i]);
    }
    printf("\n");
    yanghui(arr,begin+1,n);
}

int main(int argc, char const *argv[])
{
    int n;
    scanf("%d",&n);
    int arr[1]={1};
    yanghui(arr,1,n);
    return 0;
}
