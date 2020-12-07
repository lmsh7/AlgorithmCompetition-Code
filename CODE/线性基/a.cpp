#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 50 + 5;

ll a[N];

int main() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
	}
	ll ans = 0;
	for(ll i = 51; i >= 0; --i)  {
		for(int j = 1; j <= n; ++j) {
			if((a[j] & (1LL << i)) == (1LL << i)) {
				if((ans & (1LL << i)) == 0) {
					ans ^= a[j];
				}

				for(int k = 1; k <= n; ++k) {
					if((a[k] & (1LL << i)) == (1LL << i) && k != j) {
						a[k] ^= a[j];
					}
				}
				a[j] = 0;
				break;
			}
		}
	}
	cout << ans << endl;
	return 0;
}