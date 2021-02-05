**教育**场

## A. K-divisible Sum

> **题意**: 尝试构造出一个长度为$n$的正整数数列，使它各个数和能被$k $整除，并使这个数列里的**最大数**尽可能的**小**。输出这个最小值。

### Solution

当$n\leq k$时, 答案是$\lceil \frac{k}n\rceil$ 

当$n>k$时, 我们能通过二分找到这个玩意

### Code

```cpp
#include <bits/stdc++.h>
#define int long long 
using namespace std;

void solve() {
	int n, k;
	cin >> n >> k;
	if(n <= k) 	{
		cout << (k + n - 1) / n <<endl;
		return;
	}

	int num = k;
	int l = 0;
	int r = (n + k - 1) / k;
	while(l <= r) {
		int mid = l + ((r - l) >> 1);
		if(k * mid >= n) {
			num = k * mid;
			r = mid - 1;
		} else l = mid + 1;
	}
	cout << (num + n - 1) / n <<endl;
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

## B. Inflation

奇怪的通胀学说

### Code

```cpp
#include <bits/stdc++.h>
#define int long long 
using namespace std;



void solve() {
	int n, k;
	cin >> n >> k;
	int sum = 0;
	int ans = 0;
	int lp;
	for(int i = 0; i <= n - 1; ++i) {
		cin >> lp;
		if(i > 0) {
			int len = (lp * 100 - sum * k) > 0 ? (lp * 100 - sum * k + k - 1) / k: 0;
			ans += len;
			sum += len;
		}
		sum += lp;
	}
	cout << ans << endl;
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

## C. Longest Simple Cycle

最后发现是第一条线没特判

![](https://espresso.codeforces.com/f5b742ef7ad02ab00141f54a6dda3eb9bc79d4d3.png)

> **题意**: 找出上图的最长的简单环

### Solution

简单的递推, 取上一条线的成环与不成环情况的最大值

### Code

```cpp
#include <bits/stdc++.h>
#define int long long 
using namespace std;

const int N = 2e5 + 10;

int a[N], b[N], c[N], p[N];

void solve() {
	int n;
	cin >> n;	
	for(int i = 1; i <= n; ++i) cin >> c[i];
	for(int i = 1; i <= n; ++i) cin >> a[i];
	for(int i = 1; i <= n; ++i) {
		cin >> b[i];
	}
	int ans = 0;
	for(int i = 2; i <= n; ++i) {
		if(a[i] > b[i]) swap(a[i], b[i]);
		if(a[i] != b[i]) {
			if(i != 2)
				p[i] = max(p[i - 1] + a[i] - 1 + c[i - 1] - b[i] + 2, b[i] - a[i] + 2);
			else p[i] = b[i] - a[i] + 2;
		} else p[i] = 2;
		ans = max(p[i] + c[i] - 1, ans);		

	}
	cout << ans << endl;
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

## D. Journey

> **题意**: $n+1$个点, $n$条路,向左向右走, 每走一步, 路的方向反转,  问初始在每个点能走到多少个不同的点.

### Solution

连边, 并查集, 查询并查集大小

![1612440513384.jpg](https://i.loli.net/2021/02/04/t7IhNgBoxAvdYD4.jpg)

### Code

```cpp
#include <bits/stdc++.h>
#define int long long 
using namespace std;

const int N = 6e5 + 10;

int fa[N];
int siz[N];

int find_fa(int x) {
	if(x == fa[x]) return fa[x];
	else {
		fa[x] = find_fa(fa[x]);
		siz[x] = siz[fa[x]];
		return fa[x];
	}
}

void solve() {
	int n;
	cin >> n;
	for(int i = 1; i <= n + 1 + n + 1; ++i) {
		fa[i] = i;
		siz[i] = 1;
	}
	string s;
	cin >> s;
	for(int i = 0; i <= n - 1; ++i) {
		if(s[i] == 'R') {
			int fa_a = find_fa(i + 1);
			int fa_b = find_fa(i + 2 + n + 1);
			if(fa_b == fa_a) continue;
			else {
				siz[fa_b] += siz[fa_a];
				fa[fa_a] = fa[fa_b];
			}
		} else {
			int fa_a = find_fa(i + 2);
			int fa_b = find_fa(i + 1 + n + 1);
			if(fa_b == fa_a) continue;
			else {
				siz[fa_b] += siz[fa_a];
				fa[fa_a] = fa[fa_b];
			}			
		}

	}
	for(int i = 1; i <= n + 1; ++i) {
		find_fa(i);
		cout << siz[i] << " ";
	}
	cout << "\n";
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

## [E. Pattern Matching](http://lmsh7.xyz/index.php/2021/02/04/cf1476e-pattern-matching/)