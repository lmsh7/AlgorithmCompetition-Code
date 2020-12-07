#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

const int INF = 2147483647;
const int N = 2e5 + 10;

ll cha[N];
int a[N];

int main() {
	int t;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		ll tmp = 0;
		ll ans;
		memset(cha, 0, sizeof(cha));
		cin >> a[1];
		for(int i = 2; i <= n; ++i) {
			cin >> a[i];
			cha[i] = a[i] - a[i - 1];
			tmp += abs(cha[i]);
		}
		ans = min({tmp, tmp - abs(cha[2]), tmp - abs(cha[n])});
		for(int i = 2; i <= n - 1; ++i) {
			// printf("ans = %d\n", ans);
			ans = min(ans, tmp - abs(cha[i + 1]) - abs(cha[i]) + abs(a[i + 1] - a[i - 1]));
		}
		cout << ans << endl;
	}

	return 0;
}