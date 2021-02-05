#include <bits/stdc++.h>
#define int long long 
using namespace std;

const int N = 2e5 + 10;

int a[N], b[N], c[N], p[N];

void solve() {
	int n;
	cin >> n;	
	for(int i = 1; i <= n; ++i) cin >> c[i];
	for(int i = 1; i <= n; ++i) cin >> a[i];
	for(int i = 1; i <= n; ++i) {
		cin >> b[i];
	}
	int ans = 0;
	for(int i = 2; i <= n; ++i) {
		if(a[i] > b[i]) swap(a[i], b[i]);
		if(a[i] != b[i]) {
			if(i != 2)
				p[i] = max(p[i - 1] + a[i] - 1 + c[i - 1] - b[i] + 2, b[i] - a[i] + 2);
			else p[i] = b[i] - a[i] + 2;
		} else p[i] = 2;
		ans = max(p[i] + c[i] - 1, ans);		

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
/*
6
4
3 4 3 3
-1 1 2 2
-1 2 2 3
2
5 6
-1 5
-1 1
3
3 5 2
-1 1 1
-1 3 5
4
3 4 3 3
-1 1 2 2
-1 2 2 3
2
5 6
-1 5
-1 1
3
3 5 2
-1 1 1
-1 3 5

1
4
4 5 5 3
-1 2 3 4
-1 4 4 1

1
5
2 5 2 5 6
-1 1 1 2 5
-1 2 5 1 1

1
3
3 3 2
-1 2 2
-1 2 2
*/