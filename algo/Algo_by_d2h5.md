# This is the ALGO collected by d2h5

## 快速排序算法

```
int compare(int a, int b, int ascending) {
  return ascending ? (a - b) : (b - a);
}

void quickSort(int arr[], int low, int high, int ascending) {
  if (low < high) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
      if (compare(arr[j], pivot, ascending) <= 0) {
        i++;
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
      }
    }

    int temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;

    int pi = i + 1;

    quickSort(arr, low, pi - 1, ascending);
    quickSort(arr, pi + 1, high, ascending);
  }
}
```

> arr:要排序的数组
>
> low:最小索引
>
> high:最大索引
>
> ascending:升序降序,1:升序,0:降序
>
> compare()为了简化,而设置的可以控制升序降序的函数
>
> 时间复杂度:O(nlong n)
>
> 空间复杂度:O(log n)
