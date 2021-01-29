#include <bits/stdc++.h>
#define int long long 
using namespace std;

bool check (int x, int d) {
	if(x % 10 == d) return true;
	else {
		while (x >= d) {
			x -= d;
			if(x % 10 == d) {
				return true;
			}
		}
		return false;
	}
}

signed main() {
	int t;
	cin >> t;
	while(t--) {
		int n, d;
		cin >> n >> d;
		for(int i = 1; i <= n; ++i) {
			int la;
			cin >> la;
			if(la >= d * 10) {
				puts("YES");
			} else {
				if(check(la, d)) {
					puts("YES");
				} else puts("NO");
			}
		}
	}
	return 0;
}