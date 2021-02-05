又是一场两题场

## A. Nezzar and Colorful Balls

最长连续相同子序列

### Code

```cpp
#include <bits/stdc++.h>
#define int long long 
using namespace std;

const int N = 1e4 + 10;

int a[N];

signed main() {
	int t;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		int now = 0;
		int ans = 1;
		for(int i = 1; i <= n; ++i) {
			cin >> a[i];
			if(i != 1 && a[i] != a[i - 1]) {
				ans = max(now, ans);
				now = 1;
			} else now ++;
		}
		ans = max(now, ans);
		cout << ans <<endl;
	}
	return 0;
}
```

## B. Nezzar and Lucky Number

### Solution

$d0,d1,d2,d3,d4,d5,d6,d7,d8,d9$足以让之后的所有数都被满足

所以直接判断一下比较小的数即可

### Code

```cpp
#include <bits/stdc++.h>
#define int long long 
using namespace std;

bool check (int x, int d) {
	if(x % 10 == d) return true;
	else {
		while (x >= d) {
			x -= d;
			if(x % 10 == d) {
				return true;
			}
		}
		return false;
	}
}

signed main() {
	int t;
	cin >> t;
	while(t--) {
		int n, d;
		cin >> n >> d;
		for(int i = 1; i <= n; ++i) {
			int la;
			cin >> la;
			if(la >= d * 10) {
				puts("YES");
			} else {
				if(check(la, d)) {
					puts("YES");
				} else puts("NO");
			}
		}
	}
	return 0;
}
```

## C. Nezzar and Symmetric Array

> **题意**: $2n$个不同的数, 且对于每一个$a_i$存在与之对应的$-a_i$. 定义$d_i = \sum\limits_{j = 1}^{2n} {|a_i - a_j|}$, 现在给出数组$d$, 询问是否有与之对应的数组$a$.
>
> $1 \le n \le 10^5$

### Solution

不失一般性地, 我们假设$0 < a_1 < a_2 < \ldots < a_n$, 并且$a_{i+n}=-a_i$.

如果我们将$d$从大到小排序, $d$数组首先要满足

- $d_{2i−1}=d_{2i}$ for each $1≤i≤n$;
- $d_{2i}≠d_{2i+2}$ for each $1≤i<n$.
- $d_{2i}$ must be generated for index $ i$ or $ i+n$ .

然后我们就得出一个草淡的公式
$$
d_{2n}-d_{2n-2}=\sum_{i=1}^{n} (a_n-a_i)+\sum_{i=1}^n (a_n+a_i) - \sum_{i=1}^n|a_{n-1}-a_i| - \sum_{i=1}^n (a_{n-1}+a_i) = (2n-2)(a_n-a_{n-1})
$$
它的确特别正确

然后我们就得到了$a$的差分数组
$$
\text{又}\ d_1=\sum_{i = 1}^n(a_i-a_1)+\sum_{i=1}^n(a_i+a_1)=2\sum_{i =1}^na_i
$$
然后你他娘推推式子就能知道$a_1$是否合法啦, $a_1$合法则整个都合法啦, 草!

### Code

```cpp
#include <bits/stdc++.h>
#define int long long 
using namespace std;

const int N = 2e5 + 10;

int d[N];
int cha[N];

void solve() {
	int n;
	cin >> n;
	for(int i = 1; i <= 2 * n; ++i)
		cin >> d[i];
	sort(d + 1, d + 2 * n + 1);
	int flag = 0;
	for(int i = 1; i <= n; ++i) {
		if(d[2 * i - 1] != d[2 * i]) {
			flag = 1;
			break;
		}
		if(i != n && d[2 * i] == d[2 * i + 2]) {
			flag = 1;
			break;
		}
	}
	if(flag == 1) {
		puts("NO");
		return;
	}
	int sum = 0;
	for(int i = n; i >= 1; --i) {
		// printf("%lld ", d[i * 2]);
		if(i != 1) {
			if((d[i * 2] - d[i * 2 - 2]) % (2 * i - 2) != 0) {
				flag = 1;
				break;
			} else {
				cha[i] = (d[i * 2] - d[i * 2 - 2]) / (2 * i - 2);
				sum += cha[i] * (n - i + 1);
			}
		} else {
			if(d[1] % 2 != 0) {
				flag = 1;
				break;				
			} else {
				cha[1] = d[1] / 2;
			}
		}
	}
	if(flag == 1) {
		puts("NO");
		return;
	}
	if((cha[1] - sum) <= 0 || (cha[1] - sum) % n != 0) {
		puts("NO");
	} else puts("YES");
} 

signed main() {
	int t;
	cin >> t;
	while(t--) {
		solve();
	}
	return 0;
}
```

## D. Nezzar and Board

> **题意** : 黑板上初始有$n$个数, 每次可以写一个$2x-y$在黑板上, 问一个数$k$能不能被写出来.
>
> $2 \le n \le 2 \cdot 10^5, -10^{18} \le k \le 10^{18}$

### Solution

总之经过奇怪的猜想和证明, 我猜这个数的表示就是

$a_1x+a_2y+a_3z+\cdots+a_{n-1}t = k-x_i (1\leq i\leq n)$ 

其中$a_n = x_{n+1} - x_n$

然后经过扩展裴蜀定理, 我们可知$n$元一次不定方程有解的充要条件是$gcd(a_1, a_2, a_3, \cdots,a_{n-1})|k-x_i (1\leq i\leq n)$

### Code

```cpp
#include <bits/stdc++.h>
#define int long long 
using namespace std;

const int N = 2e5 + 10;

int a[N];

int Gcd(int x, int y) {
	if(y == 0) return x;
	else return Gcd(y, x % y);
}

void solve() {
	int n, k;
	cin >> n >> k;
	for(int i = 1; i <= n; ++i) {
		cin >> a[i];
	}
	int gcd = 0;
	for(int i = n; i >= 2; --i) {
		if(gcd == 0) {
			gcd = a[i] - a[i - 1];
		} else gcd = Gcd(gcd, a[i] - a[i - 1]);
	}
	for(int i = 1; i <= n; ++i) {
		if((k - a[i]) % gcd == 0) {
			puts("YES");
			return;
		}
	}
	puts("NO");
}

signed main() {
	int t;
	cin >> t;
	while(t--) {
		solve();
	}
	return 0;
}
```

