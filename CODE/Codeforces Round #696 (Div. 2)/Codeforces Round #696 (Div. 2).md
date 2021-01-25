GG

## A. Puzzle From the Future

### Code

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		string a;
		cin >> a;
		int qian = 0;
		for(int i = 0; i <= n - 1; ++i) {
			if(i == 0) {
				cout << 1;
				qian = a[i] - '0' + 1;
			} else {
				if(qian == a[i] - '0' + 1) {
					cout << 0;
					qian = a[i] - '0' + 0;
				} else {
					cout << 1;
					qian = a[i] - '0' + 1;
				}
			}
		}
		cout << endl;
	}
	return 0;
}
```

## B. Different Divisors

> **题意**:给出整数$d$,求满足下列条件的最小的正整数$a$
>
> - $a$至少有四个不同的因子
> - 任意两个不同的因子(所有因子, 不是任选$4$个)的差大于等于$d$

考虑多于$4$个因子的数, 可以只保留$3$个全为质数的因子然后得到一个更小的数

然后直接线性筛预处理出所有质数

对于每一个$d$选择$1$和前两个满足距离为$d$的质数

```cpp
#include <bits/stdc++.h>
#define int long long 
using namespace std;

const int N = 1e6 + 10;
int prime[N];
int is_prime[N];
int p = 0;

void Eratosthenes(int n) {
  for (int i = 0; i <= n; ++i) is_prime[i] = 1;
  is_prime[0] = is_prime[1] = 0;
  for (int i = 2; i <= n; ++i) {
    if (is_prime[i]) {
      prime[p++] = i;
      for (int j = i * i; j <= n; j += i)
        is_prime[j] = 0;
    }
  }
}

signed main() {
	int t;
	cin >> t;
	Eratosthenes(1000005);
	while(t--) {
		int d;
		cin >> d;
		int u;
		for(int i = 0; i <= p; ++i) {
			if(prime[i] >= 1 + d) {
				u = i;
				break;
			}
		}
		int v;
		for(int i = u; i <= p; ++i) {
			if(prime[i] >= prime[u] + d) {
				v = i;
				break;
			}
		}
		cout << prime[v] * prime[u] <<endl;
	}
}
```

## C. Array Destruction

> **题意**: 给出长度为$2n$的数列,在一开始, 选择一个正整数$x$,然后进行$n$次如下操作: 选择数列中两个和为$x$的两个数, 将他们从数列中剔除, 并且使$x$变为其中较大的一个数. 你需要确定是否能进行这样的操作, 如果可以, 给出方案.

### Solution

经过观察可以发现每次选择的较大的数都是当前数列中最大的数,否则当前数列中最大的数永远不可能被消除, 所以第一次操作后的$x$确定, 当前选择的较大的的数确定, 所以第一次操作以后的每一次操作都是固定的, 我们要确定的就是初始的$x,$ 它由初始数列的最大值以及数列中任意其他数组成.

### Code

```cpp
#include <bits/stdc++.h>
#define int long long 
using namespace std;

const int A = 1e6 + 10;
const int N = 2e3 + 10;

int n;
int a[N];
int vis[A];

struct Ans {
	int a, b;
} ans[N];

void reset() {
	for(int i = 1; i <= 2 * n; ++i) {
		vis[a[i]] = 0;
	}
	for(int i = 1; i <= 2 * n; ++i) {
		vis[a[i]]++;
	}
	return;
}

bool cmp(int x, int y) {
	return x > y;
}

void solve() {
	cin >> n;
	for(int i = 1; i <= 2 * n; ++i) {
		cin >> a[i];
	}
	memset(vis, 0, sizeof(vis));
	sort(a + 1, a + 2 * n + 1, cmp);
	for(int i = 2; i <= 2 * n; ++i) {
		reset();
		int x = a[1] + a[i];
		int j = 1;
		int flag = 1;
		for(int op = 1; op <= n; ++op) {
			while(j <= 2 *n && vis[a[j]] == 0) ++j;
			ans[op].a = a[j]; 
			ans[op].b = x - a[j];
			vis[a[j]] --;
			vis[x - a[j]] --;
			
			if(vis[a[j]] < 0 || vis[x - a[j]] < 0) {
				break;
			}
			x = max(a[j], x - a[j]);
			if(op == n) {
				flag = 0;
			}
		}
		if(flag == 0) {
			puts("YES");
			cout << ans[1].a+ ans[1].b <<endl;
			for(int q = 1; q <= n; ++q) {
				cout << ans[q].a <<" " <<ans[q].b <<endl;
			}
			return;
		}
	}
	puts("NO");
	return;
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

