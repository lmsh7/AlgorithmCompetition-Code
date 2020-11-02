#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a); i <= (b); ++i)
using namespace std;
 
 
 
typedef long long ll;
typedef unsigned long long ull;
const int N = 3e5 + 10;
const ll P = 998244353;
int a[N], b[N];
 
ll qpow(ll x, ll y) {
	ll res = 1;
    for (; y; y >>= 1, x = 1LL * x * x % P)
        if (y & 1) res = 1LL * res * x % P;
    return res;
}
 
ll inv(int x) {
	ll f2 = 1;
	for(int i = 2; i <= x; ++i) {
		f2 *= i;
		f2 %= P;
	}
	return qpow(f2, P - 2);
	// return f2;
}
 
int main() {
	int n;
	cin >> n;
	ll f1 = 1;
	for(int i = n + 1; i <= 2 * n; ++i) {
		f1 *= i;
		f1 %= P;
	}
	ll sumR = 0;
	ll sumL = 0;
	for(int i = 1; i <= 2 * n; ++i) {
		cin >> a[i];
	}
	sort(a + 1, a + 2 * n + 1);
	for(int i = 1; i <= n; ++i) {
		sumL += a[i];
	}
	for(int i = n + 1; i <= 2 * n; ++i) {
		sumR += a[i];
	}
	// cout << (sumR - sumL) * (f1 / inv(n));
	cout << (1LL * (sumR - sumL + P) % P * (1LL * f1 % P * inv(n) % P) % P) % P;
	return 0;
}
