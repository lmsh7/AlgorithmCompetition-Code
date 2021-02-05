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