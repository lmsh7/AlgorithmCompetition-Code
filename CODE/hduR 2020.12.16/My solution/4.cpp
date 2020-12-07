#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int P = 19260817;
const int N = 5e5 + 10;

int n;
int a[N], f[N];

int main() {
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i) {
		scanf("%d", a + i);
	}
	map <int, int> mp;
	ll ans = 0;
	mp[a[1]] = 1;
	f[1] = 2;
	for(int i = 2; i <= n; ++i) {
		if(!mp[a[i]]) {
			f[i] = ((f[i - 1] * 2) % P + 2) % P;
		} else {
			int p = mp[a[i]];
			f[i] = ((f[i - 1] * 2) % P - f[p - 1] + 1 + P) % P;
		}
		mp[a[i]] = i;
		ans = (f[i] + ans) % P;
	}
	cout << ans + 2<< endl;
	return 0;
}