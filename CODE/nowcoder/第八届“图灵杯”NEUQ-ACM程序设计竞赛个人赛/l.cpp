#include <bits/stdc++.h>
#define int long long 
using namespace std;

const int N = 1e5 + 10;

int a[N];
int n, k, maxd, ans;

bool check(int x) {
	int m = 0;
	for(int i = 2; i <= n; ++i) {
		if(x == 0 && a[i] != a[i - 1]) return false;
		if(a[i] - a[i - 1] > x) {
			m += (a[i] - a[i - 1]) / x;
			if((a[i] - a[i - 1]) % x == 0) m --;			
		}
	}
	if(m <= k) return true;
	else return false;
}

signed main() {
	cin >> n >> k;
	for(int i = 1; i <= n; ++i) {
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	for(int i = 1; i <= n; ++i) {
		maxd = i > 1 ? max(maxd, a[i] - a[i - 1]) : 0;
	}
	int l = 0;
	int r = maxd;
	while(l <= r) {
		int mid = l + ((r - l) >> 1);
		if(check(mid)) {
			ans = mid;
			r = mid - 1;
		} else {
			l = mid + 1;
		}
	}
	cout << ans << endl;
	return 0;
}