#include <bits/stdc++.h>
using namespace std;

int a[10005];
int b[10005];
long long suma[10005];
long long sumb[10005];

int main() {
	int t;
	cin >> t;
	while(t--) {
		int n, m;
		cin >> n;
		long long ans = 0;
		// long long now = 0;
		memset(suma, 0, sizeof(suma));
		memset(sumb, 0, sizeof(sumb));
		for(int i = 1; i <= n; ++i)	{
			cin >> a[i];
			suma[i] = suma[i - 1] + a[i];
		}
		cin >> m;
		for(int i = 1; i <= m; ++i) {
			cin >> b[i];
			sumb[i] = sumb[i - 1] + b[i];			
		}
		for(int i = 1; i <= n + m; ++i) {
			for(int j = 0; j <= i; ++j) {
				ans = max(ans, sumb[j] + suma[i - j]);
			}
		}
		cout << ans <<endl;
	}
	return 0;
}