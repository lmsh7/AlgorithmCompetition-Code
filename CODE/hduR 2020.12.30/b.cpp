#include <bits/stdc++.h>
using namespace std;

const int P = 998244353;

typedef long long ll;

ll q_pow(ll a, ll b) {
	ll w = 1;
	while(b) {
		if(b & 1) {
			w = (w * a) % P;
		}
		a = (a * a) % P;
		b >>= 1;
	}
	return w;
}

int main() {
	ll n, m, k;
	cin >> n >> m >> k;
	ll a = 1;
	for(ll i = 2; i <= k; ++i) {
		a = (a * i) % P;
	}
	ll b = 1;
	for(ll i = 2; i <= k / m; ++i) {
		b = (b * i) % P;
	} 
	b = q_pow(b, m);
	b = q_pow(b, P - 2);
	cout << (a * b) % P;
	return 0;
}