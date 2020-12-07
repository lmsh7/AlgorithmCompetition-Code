#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;

const ull m = 9999999967;
const ull fuc = 4294967295;

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

int main() {
	int t;
	cin >> t;
	while(t--) {
		long long x, _i;
		cin >> x >> _i;
    cout << binpow(x, _i) <<endl;
	}
  // unsigned long long a;
  // a = 9992999966;
  // cout << binpow(a, 2);
}