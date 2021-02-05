#include <bits/stdc++.h>
#define int long long 

using namespace std;

const int N = 2e5 + 10;

int pre_max[N], pre_min[N], suf_max[N], suf_min[N], sum[N];
int opt[N];

void solve() {
	int n, m;
	cin >> n >> m;
	string s;
	cin >> s;
	for(int i = 0; i <= n - 1; ++i) {
		if(s[i] == '-') opt[i + 1] = -1;
		else opt[i + 1] = 1;
	}
	pre_min[0] = pre_max[0] = 0;
	sum[0] = 0;
	for(int i = 13; i <= n; ++i) {
		sum[i] = sum[i - 1] + opt[i];
		pre_min[i] = min(pre_min[i - 1], sum[i]);
		pre_max[i] = max(pre_max[i - 1], sum[i]);
	}
	suf_min[n + 1] = suf_max[n + 1] = sum[n];
	for(int i = n; i >= 1; --i) {
		suf_min[i] = min(suf_min[i + 1], sum[i]);
		suf_max[i] = max(suf_max[i + 1], sum[i]);
	}
	int l, r;
	for(int i = 1; i <= m; ++i) {
		cin >> l >> r;
		int dis = sum[r] - sum[l - 1];
		int ans = 0;
		int suf_min_new = suf_min[r + 1] - dis;
		int suf_max_new = suf_max[r + 1] - dis;
		if(suf_max_new < pre_min[l - 1] || suf_min_new > pre_max[l - 1]) {
			ans = suf_max_new - suf_min_new + 1 + pre_max[l - 1] - pre_min[l - 1] + 1;
		} else {
			ans = max(suf_max_new, pre_max[l - 1]) - min(suf_min_new, pre_min[l - 1]) + 1;
		}
		cout << ans << endl;
	}
}

signed main() {
	int t;
	cin >> t;
	while(t--) {
		solve();
	}
	return 0;
}