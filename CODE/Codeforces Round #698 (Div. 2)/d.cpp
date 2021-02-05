#include <bits/stdc++.h>
#define int long long 
using namespace std;

const int N = 2e5 + 10;

int a[N];

int Gcd(int x, int y) {
	if(y == 0) return x;
	else return Gcd(y, x % y);
}

void solve() {
	int n, k;
	cin >> n >> k;
	for(int i = 1; i <= n; ++i) {
		cin >> a[i];
	}
	int gcd = 0;
	for(int i = n; i >= 2; --i) {
		if(gcd == 0) {
			gcd = a[i] - a[i - 1];
		} else gcd = Gcd(gcd, a[i] - a[i - 1]);
	}
	for(int i = 1; i <= n; ++i) {
		if((k - a[i]) % gcd == 0) {
			puts("YES");
			return;
		}
	}
	puts("NO");
}

signed main() {
	int t;
	cin >> t;
	while(t--) {
		solve();
	}
	return 0;
}