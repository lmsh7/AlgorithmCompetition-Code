#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 10;

int a[N];

int main() {
	int T;
	cin >> T;
	while(T--) {
		int n;
		cin >> n;
		memset(a, 0, sizeof(a));
		for(int i = 1; i <= n; ++i) {
			int la;
			cin >> la;
			a[la] ++;
		}
		int ans = 0;
		int len = 0;
		int sum = 0;
		for(int i = 1; i <= 2 * n + 1; ++i) {
			if(a[i] == 0 &&	len) {
				if(sum > len) {
					ans += len + 1;
				} else ans += len;
				len = 0;
				sum = 0;
			}
			if(a[i]) {
				len ++;
				sum += a[i];
			}
		}
		cout << ans <<endl;
	}
}