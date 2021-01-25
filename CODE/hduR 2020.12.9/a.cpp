/*
* @Author: LMSH7
* @Date:   2020-12-09 15:02:45
* @Last Modified by:   LMSH7
* @Last Modified time: 2021-01-11 21:10:23
*/
#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ll;

const unsigned long long P = 1e9 + 7;

ll q_pow(ll a, ll b) {
	ll w = 1;
	while(b) {
		if((b & 1)) {
			w = (w * a) % P;
		}
		b >>= 1;
		a = (a * a) % P;
	}
	return w;
}

int main() {
	ll n; 
	long long  ans = 1;
	cin >> n;
	if((n / 3) % 2 == 1) {
		// cout << ceil((n / 3) / 2.0)<<endl;
		ans = (ans * q_pow(100, ceil((n / 3) / 2.0))) % P;
		ans = (ans * q_pow(80, floor((n / 3) / 2.0))) % P;
	} else {
		ans = (ans * q_pow(100, floor((n / 3) / 2.0))) % P;
		ans = (ans * q_pow(80, ceil((n / 3) / 2.0))) % P;
	}
	cout << ans <<endl; 
	return 0;
}
/*
300000000000000000000
*/