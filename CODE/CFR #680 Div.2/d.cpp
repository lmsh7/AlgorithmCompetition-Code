#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a); i <= (b); ++i)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

const ll P = 998244353;

ll sum[300005];
ll ans = 0;
ll a[300005];

bool cmp(ll x, ll y) {
	return x > y;
}

int main() {
	int n;
	cin >> n;
	rep(i, 1, 2 * n) {
		cin >> a[i];
		
		// cout << sum[i]<<endl;
	}
	sort(a + 1, a + 2 * n + 1, cmp);
	rep(i, 1, 2 * n) {
		sum[i] = sum[i - 1] + a[i];
	}
	for(int i = 1; i <= n; ++i) {
		ans += a[i] * n - sum[i + n] + sum[i];
		cout <<sum[i + n] - sum[i]<<endl; 
		// ans = (ans + ((a[i] % P) * (n % P)) % P - (sum[i + n] - sum[i]) % P + P) % P;
	}
	for(int i = n + 1; i <= 2 * n; ++i) {
		ans += sum[i - 1] - sum[i - n -1] - a[i] * n;
		cout <<sum[i - 1] - sum[i - n -1] - a[i] * n<<endl; 
		// ans = (ans + (sum[i - 1] - sum[i - n -1]) % P - ((a[i] % P) * (n % P)) % P + P) % P;
	}
	cout << (ans * 2) % P<<endl;
	return 0;
}

/*

4294967294
*/