> **题意**:$n\leq2e5$个应用需要释放$m\leq 1e9$个内存, 每个应用有$a_i\leq 1e9$的内存占用, 以及$1\leq b_i \leq 2$的便捷值, 求在至少释放$m$内存的条件下, 最少损失的便捷值

### Solution

将便捷值为$1$和$2$的分别按内存从大到小排序

可知最后的方案一定是两数组的前缀

遍历$1$的前缀,找到加在一起满足$m$的$2$的前缀

$a1$的前缀和是单增的, 所以$a2$的前缀和是单减的, 方向确定, 两个指针扫过去.

### Code

```cpp
#include <bits/stdc++.h>
#define int long long 
using namespace std;

const int N = 2e5 + 10;
const int M = 1e6 + 10;

int a[N];
vector <int> a1, a2;

bool cmp (int x, int y) {
	return x > y;
}

signed solve() {
	int n, m;
	cin >> n >> m;
	for(int i = 1; i <= n; ++i) {
		cin >> a[i];
	}
	for(int i = 1, lb; i <= n; ++i) {
		cin >> lb;
		if(lb == 1) {
			a1.emplace_back(a[i]);
		} else if(lb == 2) {
			a2.emplace_back(a[i]);
		} 
	}
	sort(a1.begin(), a1.end(), cmp);
	sort(a2.begin(), a2.end(), cmp);
	int sum2 = accumulate(a2.begin(), a2.end(), 0ll);
	int nowj = (int)a2.size() - 1;
	int ans = a1.size() + a2.size() * 2 + 1;
	while (sum2 >= m) {
		ans = min(ans, (nowj + 1) * 2);
		sum2 -= a2[nowj];
		nowj --;
	}
	int sum1 = 0;
	for(int i = 0; i <= (int)a1.size() - 1; ++i) {
		sum1 += a1[i];
		while(sum1 + sum2 >= m && nowj >= -1) {
			ans = min(ans, i + 1 + (nowj + 1) * 2);
			if(nowj >= 0) sum2 -= a2[nowj];
			nowj --;
		}
	}
	if(ans != a1.size() + a2.size() * 2 + 1) cout << ans << endl;
	else puts("-1");
	return 0;
}

signed main() {
	int t;
	cin >> t;
	while(t--) {
		a1.clear();
		a2.clear();
		solve();
	}
}
```

