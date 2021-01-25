## A. Strange Partition

被fst了, `ceil`可别乱用了,乖乖用`(qwq + x - 1) / x`

### Code

```cpp
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair <int, int> pii;

int main() {
	int t;
	cin >> t;
	while(t--) {
		int n;
		int x;
		cin >> n >> x;
		ll sum = 0;
		ll ans = 0;
		for(int i = 1; i <= n; ++i) {
			int la;
			cin >> la;
			sum += la;
			ans += (la + x - 1) / x;
		}
        printf("%lld %lld\n", (sum + x - 1) / x, ans);
	}
	return 0;
}
```



## B. Strange List

### Code

```c++
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair <int, int> pii;

const int N = 1e5 + 10;

int a[N], b[N];

int main() {
	int t;
	cin >> t;
	while(t--) {
		int n, x;
		cin >> n >> x;
		ll ans = 0;
		int flag = 0;
		for(int i = 1; i <= n; ++i) {
			cin >> a[i];
			b[i] = a[i];
			ans += a[i];
		}
		while(1) {
			for(int i = 1; i <= n; ++i) {
				if(b[i] % x == 0) {
					ans += a[i];
					b[i] /= x;
				} else {
					flag = 1;
					break;
				}
			}
			if(flag == 1) break;
		}
		cout << ans <<endl;
	}
	return 0;
}
```

 

## C. Strange Birthday Party

### Solution

按照$k$从大到小对人排序,然后对每个人能送便宜的就送便宜的礼物,实在不行再送钱.

### Code

```cpp
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair <int, int> pii;

const int N = 3e5 + 10;

int k[N], c[N];

bool cmp(int x, int y) {
	return x > y;
}

int main() {
	int t;
	cin >> t;
	while(t--) {
		int n, m;
		cin >> n >> m;
		ll ans = 0;
		for(int i = 1; i <= n; ++i) cin >> k[i];
		sort(k + 1, k + n + 1, cmp);
		for(int i = 1; i <= m; ++i) cin >> c[i];
		int now = 1;
		for(int i = 1; i <= n; ++i) {
			if(c[now] < c[k[i]]) {
				ans += c[now];
				now ++;
			} else {
				ans += c[k[i]];
			}
		}
		cout << ans << endl;
	}
	return 0;
}
```



## D. Strange Definition

> **题意**:定义$x$和$y$**相邻**的条件为$\dfrac{lcm(x,y)}{gcd(x,y)}$为完全平方数. 对于给定的长度为$n$的初始数列$a$,在每一秒过后,每个数都乘上与之**相邻**的数,问任意秒时,数列中某一元素**相邻**数最多为几.

### Solution

首先$\dfrac{lcm(x,y)}{gcd(x,y)} = \dfrac{xy}{gcd^2(x,y)}$

所以两个数**相邻**的条件即为$xy$为完全平方数

~~如果$xy$为完全平方数,$yz$为完全平方数,那么$xz$一定也是完全平方数,因为$\dfrac{xy^2z}{y^2}=xz$~~

~~如果$xy$不是完全平方数,$yz$为完全平方数,同理$xz$也不是完全平方数~~

~~这里面有一个类似并查集的关系~~

~~然后我就开始瞎做了~~

> 定义 $x$ 的**核**$ \textrm{core}(x)$为$ x$ 去掉其完全平方数后剩余的部分，例如 $\textrm{core}(12)=\dfrac{12}{4}=3$ ,$\ \textrm{core}(16)=\dfrac{16}{16}=1$
>
> 由定义可知，$xy$为完全平方数，当且仅当$ \textrm{core}(x)=\textrm{core}(y)$
>
> 这样就可以通过统计$ \textrm{core}(x)$的个数来求出第$0$时的答案，即按照 $\textrm{core}$ 值分组，元素最多的组的元素个数。
>
> 对于**替换**操作，由于是将所有等于 $\textrm{core}(x)$ 的数乘起来，若这样的数有偶数个，显然我们可以得到一个完全平方数，乘积的 $\textrm{core}$ 值为 $1$；若这样的数有奇数个，则乘积的 $\textrm{core} $值仍为 $\textrm{core}(x)$。
>
> 所以经过一秒后，$\textrm{core}(x)$要么变为 $1$，要么不变。而 $\textrm{core}(x)$一旦变为$1$后，后续的替换操作也不会改变其值，所以对于任意正数秒之后的答案和第$1$秒的答案是一样的。将$ \textrm{core}$值更新一遍后重新统计即可。

以上来自https://www.luogu.com.cn/blog/endlesscheng/solution-cf1470b

下面go语言的代码也是抄的这位dalao的

### Code_cpp

```cpp
#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 10;

typedef long long ll;

int lpf[N];

void pre() {
	for(int i = 2; i <= 1000000; ++i) {
		if(lpf[i] == 0) {
			for(int j = i; j <= 1000000; j += i) {
				if(lpf[j] == 0) {
					lpf[j] = i;
				}
			}
		}
	}
}

int core(int x) {
	int c = 1;
	while(x > 1) {
		int p = lpf[x];
		int e = 1;
		for(x /= p; lpf[x] == p; x /= p) {
			e ^= 1;
		}
		if(e == 1) {
			c *= p;
		}
	}
	return c;
}


int main() {
	pre();
	int t;
	cin >> t;
	while(t--) {
		int n;
		scanf("%d", &n);
		unordered_map <int, int> mp;
		for(int i = 1; i <= n; ++i) {
			int la;
			scanf("%d", &la);
			mp[core(la)]++;
		}
		int max_0 = 0;
		int max_1 = mp[1];
		for (auto i: mp) {
			max_0 = max(max_0, i.second);
			if (i.first > 1 && (i.second & 1) == 0) {
				max_1 += i.second;
			}
		}
		int q;
		scanf("%d", &q);
		while(q--) {
			ll w;
			scanf("%lld", &w);
			if(w == 0) printf("%d\n", max_0);
			else printf("%d\n", max(max_0, max_1));
		}
	}
	return 0;
}
```

### Code_go

```go
package main

import (
	"bufio"
	. "fmt"
	"os"
)

func main() {
	in := bufio.NewReader(os.Stdin)
	out := bufio.NewWriter(os.Stdout)
	defer out.Flush()
	const N int = 1e6
	lpf := [N + 1]int{1: 1}//定义长度为1e6 + 1的数组, lpf[1]设为1
	//lpf为最大质因数的缩写
	for i := 2; i <= N; i++ {
		if lpf[i] == 0 {
			for j := i; j <= N; j += i {
				if lpf[j] == 0 {
					lpf[j] = i
				}
			}
		}
	}
	core := func(x int) int {
		c := 1
		for x > 1 {
			p := lpf[x]
			e := 1
			for x /= p; lpf[x] == p; x /= p {
				e ^= 1
			}
			if e == 1 {
				c *= p
			}
		}
		return c
	}
	var t, n, q int
	var w int64
	for Fscan(in, &t); t > 0; t-- {
		cnt := map[int]int{}
		for Fscan(in, &n); n > 0; n-- {
			var la int
			Fscan(in, &la)
			cnt[core(la)] ++
		}
		max_0, max_1 := 0, cnt[1]
		for v, c := range cnt {
			max_0 = max(max_0, c)
			if v > 1 && c & 1 == 0 {
				max_1 += c
			}
		}
		for Fscan(in, &q); q > 0 ; q-- {
			if Fscan(in, &w); w == 0 {
				Fprintln(out, max_0)
			} else {
				Fprintln(out, max(max_0, max_1))
			}
		}
	}
}

func max(x int, y int) int {
	if x > y {
		return x
	} else {
		return y
	}
}
```

