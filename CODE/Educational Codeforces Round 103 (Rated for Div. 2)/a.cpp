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