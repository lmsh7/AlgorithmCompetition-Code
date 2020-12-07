# CFR #687 Div.2

### A. Prison Break

计算四个角到$(r,c)$的距离即可

### B. Repainting Street

由于$c[i]$范围很小,所以暴力每次加$k$即可

### C.Bouncing Ball

> **题意**:有n个单元格，有一个小球会从左边来，第一次会落在单元格p，然后会落在单元格p+k，然后会落在p+2k……直到弹出第n个单元格为止。只有当当前位置的单元格有平台时，小球才能继续往下弹。你有两个操作：
> 1、花费x秒的时间在任意单元格添加一个平台。
> 2、花费y秒的时间删去最前面的单元格。
> 问最少需要多少秒，可以使小球弹出第n个单元格。

看起来挺唬人的,其实预处理出从$p$开始的跳到的每个格子为$0$的数目,即$num$数组,就是想跳出去要建造的格子数目

然后你这里要么建,要么删,循环一遍取最小值即可

```cpp
#include <bits/stdc++.h>
using namespace std;
 
const int N = 1e5 + 10;
const int INF = 2147483647;
 
int  num[N];
 
int main() {
	int t;
	cin >> t;
	while(t--) {
		int n, p, k, x, y;
		string s;
		cin >> n >> p >> k;
		cin >> s >> x >> y;
		int  ans = INF;
		p -= 1;
		memset(num, 0, sizeof(num));
		for(int i = 0; i < n; ++i) {
			if(i >= p) num[(i - p) % k] += ('1' - s[i]);
		}
		for(int i = p; i < n; ++i) {
			ans = min(num[(i - p) % k] * x + y * (i - p), ans);
			if(s[i] == '0') num[(i - p) % k] -= 1;
		}
		cout << ans <<endl;
 
	}
	return 0;
}
/*
1
10 3 3
0000000100
80 1
*/
```

### D. XOR-gun

> **题意**:给你一个长度为$n<1e5$的单调不降序列$a\leq 1e9$，每次操作可以取出相邻的两个数，异或后插入原来的位置，问最少操作几次才能使该数列不是单调不降序列。

考虑如果连续三个数的二进制最高位相同,那么后两个$xor$后就会比前一个小,操作次数是$1$.

如果我们找不到,考虑最坏的情况是$1~n$中每次都只有两个二进制最高位相同,由于$a\leq 1e9$, 由于$2^30 > 1e9 $所以最多$2^60$,即n最大也就$60$,直接暴力即可, 那么就考虑如何优雅的暴力.

最后产生的单调序列一定是两个数$c_i > c_{i+1}$c_i由$a_l$到$a_{mid}$ 异或得来, $c_{i+1}$由$a_{mid+1}$到$a_l$得到, 所以每次循环长度$k$,左端点$l$,中间点$mid$,由于长度从小到大,$xor$次数最小的就是我们第一次循环到的可行的方案

```CPP
#include <bits/stdc++.h>
using namespace std;
 
const int N = 1e5 + 10;
 
int a[N];
int hBit[N];
 
int main() {
	int n;
	cin >> n;
	for(int i = 1; i <= n; ++i) {
		cin >> a[i];
	}
	for(int i = 1; i <= n; ++i) {
		int la = a[i];
		int cnt = 1;
		while(la) {
			hBit[i] = cnt;
			la >>= 1;
			cnt ++;
		}
	}
	int ans = 0;
	for(int i = 3; i <= n; ++i) {
		if(hBit[i] == hBit[i - 1] && hBit[i - 1] == hBit[i - 2]) {
			ans = 1;
		}
	}
	if(ans) {
		cout << ans << endl;
		return 0;
	}
	for(int k = 2; k <= n; ++k) {
		for(int l = 1; (l + k - 1) <= n; ++l) {
			int r = l + k - 1;
			for(int mid = l; mid < r; ++mid) {
				int cl, cr;
				for(int i = l; i <= mid; ++i) {
					if(i == l) cl = a[i];
					else cl ^= a[i];
				}
				for(int i = mid + 1; i <= r; ++i) {
					if(i == mid + 1) cr = a[i];
					else cr ^= a[i];
				}
				if(cl > cr) {
					 // printf("%d %d l = %d r = %d mid = %d\n", cl, cr, l, r, mid);
					ans = (mid - l) + ( r - (mid + 1));
					break;
				}
			}				
			if(ans) break;
		}		
		if(ans) break;
	}
 
	if(ans) cout << ans <<endl;
	else cout << -1 <<endl;
	return 0;
}
```



