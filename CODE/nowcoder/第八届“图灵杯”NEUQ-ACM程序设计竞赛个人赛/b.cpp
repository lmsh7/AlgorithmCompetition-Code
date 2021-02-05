#include <bits/stdc++.h>
#define int long long 
using namespace std;


signed main() {
	int t;
	cin >> t;
	while(t--) {
		int n, k;
		cin >> n >> k;
		map <int, int> mp;
		int ans = -1;
		int sum = 0;
		mp[0] = 1;
		for(int i = 1; i <= n; ++i) {
			int la;
			cin >> la;
			sum += la;

			if(mp[sum % k]) {
				ans = max(ans, i - mp[sum % k] + 1);
			}
			else mp[sum % k] = i + 1;
		}
		cout << ans << endl;
	} 
	return 0;
}