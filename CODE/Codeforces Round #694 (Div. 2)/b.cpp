#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair <int, int> pii;

const int N = 1e5 + 10;

int a[N], b[N];

int main() {
	int t;
	cin >> t;
	while(t--) {
		int n, x;
		cin >> n >> x;
		ll ans = 0;
		int flag = 0;
		for(int i = 1; i <= n; ++i) {
			cin >> a[i];
			b[i] = a[i];
			ans += a[i];
		}
		while(1) {
			for(int i = 1; i <= n; ++i) {
				if(b[i] % x == 0) {
					ans += a[i];
					b[i] /= x;
				} else {
					flag = 1;
					break;
				}
			}
			if(flag == 1) break;
		}
		cout << ans <<endl;
	}
	return 0;
}