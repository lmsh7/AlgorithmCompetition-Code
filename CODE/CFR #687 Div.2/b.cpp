#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;

int last[N];
int acc[N];
int occ[N];
int a[N];

int main() {
	int t;
	cin >> t;
	while(t--) {
		int n, k;
		cin >> n >> k;
		int ans = n;
		memset(last, 0, sizeof(last));
		memset(occ, 0, sizeof(occ));
		memset(acc, 0, sizeof(acc));
		memset(a, 0, sizeof(a));
		for(int i = 1; i <= n; ++i) {
			cin >> a[i];
			// acc[la] += ceil( (i - last[la] - 1) / (1.0 * k));
			occ[a[i]] = 1;
			// last[la] = i;
		}
		for(int i = 1; i <= 100; ++i) {
			if(occ[i]) {
				int tmp = 0;
				for(int j = 1; j <= n;) {
					if(a[j] == i) ++j;
					else {
						j += k; 
						tmp ++;
					}
				}
				// printf("i = %d tmp = %d\n", i, tmp);
				ans = min(ans, tmp);
			}
		}
		cout << ans << endl;
	}
}