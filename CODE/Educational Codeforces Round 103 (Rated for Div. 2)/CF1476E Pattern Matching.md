> **题意**:  给定长度为$k$的$n$个模式串和$m$个匹配串，其中模式串由小写字母和通配符'_'组成，匹配串由小写字母组成，同时，为每个匹配串指定一个$mt$, 要求重新排列模式串顺序以后，按顺序匹配时，匹配串第一个匹配到的模式串为原顺序中的第$mj$个模式串，求是否能得到新的排列, 如果可以, 输出新的排列.
>
> $1 \le n, m \le 10^5, 1 \le k \le 4$

### Solution

匹配串需要让$mt$模式串在最前面的"矛盾"转化为图, 将$mt$模式串与可以与此匹配串匹配的模式串连边.

但是又需要我们快速地知道匹配串是否能和模式串匹配, $k$的数量很小, 我们枚举通配符出现的情况, 最多为$2^k$种, 然后处理当前匹配串, 配合用``map`预处理模式串, 复杂度为$O(nk+m2^k)$

最终得到的图如果可以拓扑排序, 那么证明有新的排列, 且拓排的顺序即为新的排列, 如果没有, 则说明图中出现了环, 无法得到新的排列.

### Code

```cpp
#include <bits/stdc++.h>
#define int long long 
using namespace std;

const int N = 1e5 + 10;

map <string, int> mp;

signed main() {
	int n, m, k;
	cin >> n >> m >> k;
	vector <vector<int>> adj(n + 1);
	vector <int> rudu(n + 1, 0);
	for(int i = 1; i <= n; ++i) {
		string la;
		cin >> la;
		mp[la] = i;
	}
	int flag = 0;
	for(int i = 1; i <= m; ++i) {
		string la;
		int mt;
		int mt_flag = 0;
		cin >> la >> mt;
		if(flag == 1) continue;
		for(int j = 0; j <= (1 << k) - 1; ++j) {
			int now = j;
			string lb = la;
			for(int z = k - 1; z >= 0; --z) {
				if(now >= (1 << z)) {
					lb[z] = '_';
					now -= (1 << z);
				}
			}
			if(mp[lb]) {
				if(mp[lb] == mt)
					mt_flag = 1;
				else {
					rudu[mp[lb]]++;
					adj[mt].emplace_back(mp[lb]);
				}
			}
		}
		if(mt_flag == 0) {
			flag = 1;
			continue;
		}
	}

	if(flag == 1) puts("NO");
	else { // topo
		queue <int> q;
		vector <int> ans;
		for(int i = 1; i <= n; ++i) {
			if(rudu[i] == 0) q.push(i);
		}
		while(!q.empty()) {
			int u = q.front();
			q.pop();
			ans.push_back(u);
			for(auto j : adj[u]) {
				rudu[j] --;
				if(rudu[j] == 0) q.push(j);
			}
		}
		if(ans.size() != n) {
			puts("NO");
		} else {
			puts("YES");
			for(auto j : ans) {
				cout << j << " ";
			}
			cout << endl;
		}
	}
	return 0;
}
```

