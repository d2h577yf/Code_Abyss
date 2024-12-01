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

- arr:要排序的数组
- low:最小索引
- high:最大索引
- ascending:升序降序,1:升序,0:降序
- compare()为了简化,而设置的可以控制升序降序的函数
- 时间复杂度:O(nlong n)
- 空间复杂度:O(log n)

## 埃拉托斯特尼筛法（Sieve of Eratosthenes）

```
#define MAX_LIMIT XXXXXXXX

bool book[MAX_LIMIT + 1];

void prime(int limit,bool *book) {
    memset(book, true, sizeof(book));
    book[0] = book[1] = false;

    int n = sqrt(b);

    for (int i = 2; i <= n; i++) {
        if (book[i]) {
            for (int j = i * i; j <= b; j += i) {
                book[j] = false;
            }
        }
    }
}
```

- limit:需要遍历到到最大数字
- book[]:可以容纳下所有数字到数组，而且数字和下标是一一对应（所以为了不越界可能要+1），这里建议直接把他设置成一个极大到数组
- 时间复杂度:O(b \log \log b)，其中 b 是输入的最大范围。
- 空间复杂度：O(b)，需要一个大小为 b + 1的布尔数组来存储素数标记。

> 思路:
>
> 我先有个数字和下标一一对应的数组，用来记录每个数字是不是素数，判断逻辑是：我假设除了0，1以外所有数字是素数，然后从2开始把每个素数及其倍数标为合数
>
> Q:
>
> for (int j = i *i; j <= b; j += i),为什么是从j=i*i开始
>
> A:
>
>- 从 i *i 开始能避免重复标记合数：
>
> 当 i 是素数时，它的倍数会被标记为合数。
>
> 对于 i = 2，倍数为 4, 6, 8, 10, ...，从 4 开始标记已经足够，因为 2 的倍数（4）早已被标记过了。
> 对于 i = 3，倍数为 6, 9, 12, 15, ...，从 9 开始标记，因为 3 的倍数 6 已经在处理 i = 2 时被标记了。
>
>- 从 i* i 开始，标记的倍数是 i 或更大的倍数：
>
> 假设 i = 5，从 i *i = 25 开始标记倍数，因为之前的倍数（5* 2 = 10, 5 *3 = 15, 5* 4 = 20）已经在之前处理的 i = 2 和 i = 3 中被标记过了。
> 换句话说，i 的倍数 j 小于 i *i 时，j 已经在)小于 i 的素数中被标记过了。所以从 i* i 开始标记是合理的，避免了冗余操作。
>
>- 减少不必要的标记操作：
>
> 从 i * i 开始，减少了对已经被标记的倍数的处理。这样不仅节省了时间，而且避免了重复工作，提高了算法效率。

## 欧几里得算法 (Euclidean Algorithm)

```
int gcd(int a, int b) {
    while (b != 0) {
        int r = a % b; 
        a = b;     
        b = r;           
    }
    return a;
}
```

- a,b两个要求最大公约数的数字
- 时间复杂度：O(log(min(a, b)))
- 空间复杂度：O(1)

> 思路：
>欧几里得算法的思路很简单：
>给定两个整数 a 和 b，不断用较大的数去除较小的数，直到余数为 0。
>计算 a % b，然后把 a 更新为 b，b 更新为余数 a % b。
>重复这个过程，直到余数为 0，此时 b 就是最大公约数。

## 计算最小公倍数（LCM，Least Common Multiple)

```
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
```

- a,b要求最小公倍数的数字
- 复杂度和GCD一样

> 思路：
>
> 用最大公约数求最小公倍数，小学数学，a与b的积除其最小公约数

## 反转数字+判断回文数

```
bool isHWS(int num) {
  int temp = num, ans = 0;
  while (temp != 0) {
    ans = ans * 10 + temp % 10;
    temp /= 10;
  }
  return ans == num;
}
```

- num需要判断的数字

> 思路（代码很短没什么好说的）：
>
> ans就是反转的数字

## 高精度阶乘

```

#define MAX_DIGITS XXXXXX

void printFactorial(int n) {
    if (n == 0 || n == 1) {
        printf("1\n");
        return;
    }

    int arr[MAX_DIGITS] = {0};
    arr[0] = 1; 

    for (int i = 1; i <= n; i++) {
    int carry = 0;
    for (int j = 0; j < MAX_DIGITS; j++) {
        arr[j] = product % 10;  
        carry = product / 10; 

        if (carry == 0 && j == MAX_DIGITS - 1) {
            break;
        }
    }
}
    int start = MAX_DIGITS - 1;
    while (start >= 0 && arr[start] == 0) {
        start--;
    }

    if (start == -1) {
        printf("0\n");
    } else {
        for (int i = start; i >= 0; i--) {
            printf("%d", arr[i]);
        }
        printf("\n");
    }
}
```

- n:要计算阶乘的数字

> 思路：
>
> 阶乘没什么思路，主要是高精度计算
> 高精度计算的思路：
>
>
```
for (int i = 1; i <= n; i++) {  // 外层循环，遍历阶乘的每个因子，从1到n
    int carry = 0;  // 初始化进位，初始时没有进位，进位为0
    // 内层循环，遍历arr数组中的每一位，进行逐位乘法
    for (int j = 0; j < MAX_DIGITS; j++) {
        // 计算当前位乘积及进位。每一位数字乘以i，并加上上一位的进位
        int product = arr[j] * i + carry;  // arr[j] 是当前位的数字，i 是当前的阶乘因子，carry 是上一位的进位
        arr[j] = product % 10;  // 取乘积的个位数，并将其存回 arr[j]，即保留当前位
        carry = product / 10;  // 计算当前位的进位，即乘积除以10后的商，并传递给下一位
        // 如果进位已经为0，并且我们已处理到数组的最后一位（MAX_DIGITS-1），
        // 说明后续的乘法不再产生任何进位，可以提前退出内层循环，节省计算
        if (carry == 0 && j == MAX_DIGITS - 1) {
            break;  // 如果进位为0并且当前已经是数组的最后一位，提前停止进位计算
        }
    }
}
```
