#include <bits/stdc++.h>
using namespace std;

const int P = 998244353;
const int N = 1e5 + 10;

typedef long long ll;

int a[N];
ll f[N][23];

int main() {
	int n;
	cin >> n;
	ll ans = 0;
	for(int i = 1; i <= n; ++i) {
		cin >> a[i];
	}
	for(int i = 0; i <= 22; ++i) {
		ll now = 0;
		for(int j = 1; j <= n; ++j) {
			if((a[j] >> i) & 1)	{	
				now ++;
				f[j][i] = (f[j - 1][i] + ((a[j] % P  * (1 << i) % P) % P * now % P)% P) % P;
				// now += a[j];		
				// now ++;
				// ans = (ans + (now % P * (1 << i) % P) % P ) % P;
				ans = (ans + f[j][i]) % P;
			} else {
				now = 0;
			 }
		}
		// cout << ans << endl;
	}
	cout << ans <<endl;
	return 0;
}