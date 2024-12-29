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

## 数字快速读取算法
>
> 意义：在程序设计中，快速读取算法（也称为快速输入或快速IO）主要用于减少因输入数据过多而带来的性能瓶颈，特别是在竞赛编程中，输入数据可能非常大，因此普通的输入方法（如 scanf）可能会显得比较慢。使用快速读取方法可以显著提高程序的输入效率。

```
int read() {
    int x = 0, f = 1;  // 用于存储读取的整数和符号标志
    char c = getchar(); // 从标准输入流获取字符
    while (c < '0' || c > '9') {  // 跳过非数字字符
        if (c == '-') f = -1;  // 如果遇到负号，则设置符号标志
        c = getchar();  // 继续读取下一个字符
    }
    while (c >= '0' && c <= '9') {  // 读取数字字符
        x = x * 10 + c - '0';  // 将字符转为数字并累加到结果中
        c = getchar();  // 继续读取下一个字符
    }
    return x * f;  // 返回最终结果，考虑符号
}

int main() {
    int n = read();  // 使用快速读取读取一个整数
    printf("You entered: %d\n", n);
    return 0;
}
```

> 代码解释
>
> 1. 读取字符： getchar()
>getchar() 是一个标准的输入函数，它从标准输入流（通常是键盘）读取一个字符。
>通过 getchar() 可以实现对每个字符的逐个读取，可以根据字符的特性进行不同的操作，比如跳过空格、换行符等。
>
> 2. 跳过无效字符： while (c < '0' || c > '9')
>输入的数据可能包含空格、换行符、制表符等字符，这些字符并不属于数字。为了跳过这些字符，while (c < '0' || c > '9') 会一直读取字符，直到碰到数字为止。
>如果是负号 -，那么就将符号标志 f 设置为 -1，后续计算时可以根据这个标志来确定最终结果的符号。
>
> 3. 数字转换： x = x *10 + c - '0'
>当读取到数字字符时，通过 c - '0' 将字符 '0' 到 '9' 转换成对应的数字（0 到 9）。
>x = x* 10 + c - '0'; 实现了将读取的每个数字字符累加到 x 中。这个方法类似于手动实现 atoi。
>
> 4. 返回结果： return x *f;
>读取结束后，返回结果 x* f，其中 f 用来表示符号，如果输入的是负数，f 就是 -1，否则是 1。

> ps:按照这个思路，通过修改可以对char，字母等等快速读取

## 字符串快速读取（包括空格）

```
#define MAX_LEN 1000000

void read_string(char *str) {
    char buffer[MAX_LEN];
    int i = 0;

    size_t n = fread(buffer, 1, MAX_LEN - 1, stdin);
    for (size_t j = 0; j < n; ++j) {
        if (buffer[j] == '\n' || buffer[j] == EOF) {
            break;
        }
        str[i++] = buffer[j];
    }

    str[i] = '\0';
}

int main() {
    char str[MAX_LEN];
    printf("Enter a string: ");
    read_string(str);
    printf("You entered: %s\n", str);
    return 0;
}
```

## 快速判断是否是质数
>
> 用到的头文件
>
> stdbool.h
>
> math.h

```

bool is_prime(int num) {
    if (num <= 1) return false;
    if (num <= 3) return true;  
    if (num % 2 == 0 || n % 3 == 0) return false;

    for (int i = 5; i * i <= n; i += 6) {
        if (num % i == 0 || num % (i + 2) == 0) {
            return false;
        }
    }
    return true;
}
```

- num:需要判断的数字
- 返回是或者不是

> 代码解读：
>
> 其实更像是一个数学问题
>
> 前两个if没什么好说的，<=1必然不是质数，2，3必然是质数，
> 后面if:如果是2，3倍数必然不是质数
>
> 再次之后就精彩了，现在我们吧所有>3数字统一变成6n,6n+1,6n+2,6n+3,6n+4,6n+5(n为任意整数),而我们之前的%2，%3已经把6n,6n+2,6n+3,6n+4排除了，所以我们现在就是要判断6n+1,6n+5是不是num的因数，所以我们有一个循环i代表6n+5(6(n+1)-1),i+2代表6n+1
