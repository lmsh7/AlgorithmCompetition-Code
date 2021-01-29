#include <bits/stdc++.h>
#define int long long 
using namespace std;

const int N = 1e4 + 10;

int a[N];

signed main() {
	int t;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		int now = 0;
		int ans = 1;
		for(int i = 1; i <= n; ++i) {
			cin >> a[i];
			if(i != 1 && a[i] != a[i - 1]) {
				ans = max(now, ans);
				now = 1;
			} else now ++;
		}
		ans = max(now, ans);
		cout << ans <<endl;
	}
	return 0;
}