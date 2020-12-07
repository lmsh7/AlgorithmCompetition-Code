#include <bits/stdc++.h>
using namespace std;

const int P = 998244353;
const int N = 1e5 + 10;

typedef long long ll;

int a[N];
int f[N][23];

int main() {
	int n;
	cin >> n;
	ll ans = 0;
	for(int i = 1; i <= n; ++i) {
		cin >> a[i];
	}
	for(int i = 1; i <= n; ++i) {
		for(int j = i; j <= n; ++j) {
			ll q = a[j];
			ll num = 0;
			for(int k = i; k <= j; ++k) {
				q = q & a[k];
				num = (num + a[k]) % P;
			}
			ans = (ans +  (num * q) % P) % P;
		}
	}
	cout << ans <<endl;
	return 0;
}