#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair <int, int> pii;

int main() {
	int t;
	cin >> t;
	while(t--) {
		int n;
		double x;
		cin >> n >> x;
		ll sum = 0;
		ll ans = 0;
		for(int i = 1; i <= n; ++i) {
			double la;
			cin >> la;
			sum += la;
			ans += ceil(la / x);
		}
		cout << ceil(sum / x) << " " << ans <<endl;
	}
	return 0;
}