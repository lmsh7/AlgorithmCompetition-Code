#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair <int, int> pii;

const int N = 3e5 + 10;

int k[N], c[N];

bool cmp(int x, int y) {
	return x > y;
}

int main() {
	int t;
	cin >> t;
	while(t--) {
		int n, m;
		cin >> n >> m;
		ll ans = 0;
		for(int i = 1; i <= n; ++i) cin >> k[i];
		sort(k + 1, k + n + 1, cmp);
		for(int i = 1; i <= m; ++i) cin >> c[i];
		int now = 1;
		for(int i = 1; i <= n; ++i) {
			if(c[now] < c[k[i]]) {
				ans += c[now];
				now ++;
			} else {
				ans += c[k[i]];
			}
		}
		cout << ans << endl;
	}
	return 0;
}