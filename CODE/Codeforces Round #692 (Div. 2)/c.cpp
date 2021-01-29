#include <bits/stdc++.h>
#define int long long 
using namespace std;

const int N = 1e5 + 10;

int fa[N];

int find_fa(int x) {
	return x == fa[x] ? fa[x] : fa[x] = find_fa(fa[x]);
}

void solve() {
	int n, m;
	cin >> n >> m;
	int ans = m;
	for(int i = 1; i <= n; ++i) fa[i] = i;
	for(int i = 1; i <= m; ++i) {
		int lx, ly;
		cin >> lx >> ly;
		if(lx == ly) {
			ans --;
			continue;
		}
		if(find_fa(lx) == find_fa(ly)) {
			ans ++;
		} else {
			fa[fa[lx]] = ly;
		}
	}
	cout << ans <<endl;
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