#include <bits/stdc++.h>
#define int long long 
using namespace std;

const int N = 2e5 + 10;

int d[N];
int cha[N];

void solve() {
	int n;
	cin >> n;
	for(int i = 1; i <= 2 * n; ++i)
		cin >> d[i];
	sort(d + 1, d + 2 * n + 1);
	int flag = 0;
	for(int i = 1; i <= n; ++i) {
		if(d[2 * i - 1] != d[2 * i]) {
			flag = 1;
			break;
		}
		if(i != n && d[2 * i] == d[2 * i + 2]) {
			flag = 1;
			break;
		}
	}
	if(flag == 1) {
		puts("NO");
		return;
	}
	int sum = 0;
	for(int i = n; i >= 1; --i) {
		// printf("%lld ", d[i * 2]);
		if(i != 1) {
			if((d[i * 2] - d[i * 2 - 2]) % (2 * i - 2) != 0) {
				flag = 1;
				break;
			} else {
				cha[i] = (d[i * 2] - d[i * 2 - 2]) / (2 * i - 2);
				sum += cha[i] * (n - i + 1);
			}
		} else {
			if(d[1] % 2 != 0) {
				flag = 1;
				break;				
			} else {
				cha[1] = d[1] / 2;
			}
		}
	}
	if(flag == 1) {
		puts("NO");
		return;
	}
	if((cha[1] - sum) <= 0 || (cha[1] - sum) % n != 0) {
		puts("NO");
	} else puts("YES");
} 

signed main() {
	int t;
	cin >> t;
	while(t--) {
		solve();
	}
	return 0;
}