#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a); i <= (b); ++i)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

const int lim = 100005;//因数最多到sqrt(q),质因数同理

void pre() {
	for (int i = 2; i < lim; ++i) {
		if (!vis[i]) {
			phi[i] = i - 1;
			prime[++cnt] = i;
		}
		for (int j = 1; j < cnt; ++j) {
			if (1ll * i * prime[j] >= lim) break;
			vis[i * prime[j]] = 1;
			if
		}
	}
}


int main() {
	int T;
	cin >> T;
	pre();
	while (T--) {
		ll a, b;
		cin >> a >> b;
		if (a < b) cout << a << endl;
		else if (a % b != 0) cout << a << endl;
		else {

		}
	}
	return 0;
}
