/*
* @Author: LMSH7
* @Date:   2021-01-05 18:24:43
* @Last Modified by:   LMSH7
* @Last Modified time: 2021-01-11 21:10:10
*/
#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 10;

int a[N];

int main() {
	int t;
	cin >> t;
	while(t--) {
		int n, k;
		cin >> n >> k;
		int m = ceil(n / 2.0);
		for(int i = 1; i <= n * k; ++i) {
			cin >> a[i];
		}
		int num = 0;
		long long ans = 0;
		for(int i = n * k - (n - m); i >= 1; i -= (n - m)) {
			ans += a[i];
			// cout << m <<endl;
			num ++;
			i--;

			if(num == k) break;
		}
		cout << ans << endl;
	}
	return 0;
}