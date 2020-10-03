#include <bits/stdc++.h>
using namespace std;


typedef long long ll;
typedef unsigned long long ull;
const ull m = 1e9 + 7;
const int U = 1e8 + 1;
const int N = 1e5 + 10;
ull mul(ull a, ull b) {
	ull res = 0, f = 1;
	// if (a < 0) a = -a, f = -f;
	// if (b < 0) b = -b, f = -f;
	for (; b; b >>= 1, a = (a + a) % m)
		if (b & 1) res = (res + a) % m;
	return res * f;
}

ull binpow(ull a, ull b) {
	a %= m;
	ull res = 1;
	while (b > 0) {
		if (b & 1) {
			res = mul(res, a) % m;
		}
		a = mul(a, a) % m;
		b >>= 1;
	}
	return res;
}


ll f[N];

int main() {
	// freopen("a2.out", "w", stdout);
	int n;
	cin >> n;
	ll ans = 1;
	f[0] = 1;
	for(int i = 1; i <= 51839; ++i) {
		ans = ans * (ans + 1) % m;
		f[i] = ans;
		// cout << f[i] << endl;
	}
	while (n--) {
		int a, b;
		cin >> a >> b;
		if (a < b) swap(a, b);
		if (a >= 6772) a = (a - 6772) % (51839 - 6772) + 6772;
		if (b >= 6772) b = (b - 6772) % (51839 - 6772) + 6772;
		ll now = f[a] * binpow(f[b], m - 2) % m;
		cout << now << endl;
	}
	return 0;
}
/*


*/